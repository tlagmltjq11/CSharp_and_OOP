## 🔔 yield

아래 링크들도 함께 공부해야 할 부분들<br>
[IEnumerable와 IEnumerator](https://github.com/tlagmltjq11/CSharp_and_OOP/blob/main/C%23/IEnumerable%20%26%20IEnumerator.md)<br>
[코루틴](https://github.com/tlagmltjq11/CSharp_and_OOP/blob/main/C%23/Coroutine.md)<br>
<br>
<br>

👉 **첫번째 사용법**<br>
C#의 yield 키워드는 호출자(Caller)에게 컬렉션 **데이터를 하나씩 리턴할 때 사용**한다.<br>
흔히 Enumerator(Iterator)라고 불리우는 이러한 기능은 집합적인 데이터셋으로부터 데이터를 하나씩 호출자에게 보내주는 역할을 한다.<br>
-> ⭐⭐ **즉 열거자 혹은 반복자의 역할로 사용이 가능하다는 것인데 이는 yield 키워드를 만났을 때 컴파일러가 자동으로<br>
-> IEnumerable와 IEnumerator를 구현한 객체를 만들어주어 IEnumerator를 반환 할 수 있기 때문이다.** ⭐⭐<br>

**즉 yield는 IEnumerator/IEnumerable 의 간편표기법으로 사용 할 수 있다는 의미다.** ⭐<br>
yield를 사용하면 IEnumerable, IEnumerator를 상속받는 클래스를 작성해 줄 필요가 없다.<br>
IEnumerable 클래스에서 GetEnumerator() 메서드를 구현하는 한 방법으로 yield 를 사용할 수 있다.<br>
-> 즉 IEnumerable를 구현하는 하나의 방법으로 yield 사용 방식을 채택 할 수 있다는 것이다.<br>
-> **IEnumerator 혹은 IEnumerable 을 리턴하는 함수안에 yield return을 사용하기만 하면된다.** ⭐<br>
GetEnumerator() 메서드에서 yield return를 사용하여 컬렉션 **데이타를 순차적으로 하나씩 넘겨주는 코드를 구현하고,<br>
리턴타입으로 IEnumerator를 리턴할 수 있다.**<br>

yield는 yield return 또는 yield break의 2가지 방식으로 사용되는데,<br>
(1) yield return은 컬렉션 데이터를 하나씩 리턴하는데 사용된다.<br>
(2) yield break는 리턴을 **중지하고 Iteration 루프를 빠져 나올 때 사용한다.**<br>
<br>
<br>

👉 **두번째 사용법** (Unity에서 사용하는 것)<br>
⭐⭐ **코루틴과 같이 비동기적 실행이 가능해진다.** ⭐⭐<br>
⭐ yield return문을 만나면 함수를 호출한 곳에 리턴을 해준 후 다시 돌아와서 다음 yield return문 까지의 코드를 실행한다.<br>
즉, 하나의 함수가 끝까지 다 실행할 때까지 기다리는 것이 아니라 **yield를 만나면 잠시 함수 중간에 빠져나와 호출한 곳에<br>
리턴 값을 전달해주고 다시 돌아와 마저 함수를 진행하는 식으로 왔다 갔다 하며 실행되는 것이다.** ⭐<br>
-> **유니티에서는 멀티스레딩을 지원하지 않기 때문에 해당 코루틴 매커니즘을 사용해서 병렬 작업이 되는 것 처럼 실행한다.** ⭐<br>
<br>

```c#
public class CoroutineStudy : MonoBehaviour
{
    private void Start()
    {
        StartCoroutine(DoCoroutine());
        Debug.Log("Start");
    }
    
    IEnumerator DoCoroutine()
    {
        Debug.Log("DoCoroutine WaitForSeconds");
        yield return new WaitForSeconds(1.0f);
        Debug.Log("DoCoroutine Null");
        yield return null;
        Debug.Log("DoCoroutine end");
    }
}
```
위 코드 처럼 코루틴을 사용하는 것을 볼 수 있는데 이러한 코루틴을 직접 구현해보면 아래와 같을 것이다.<br>
<br>

```c#
public class CoroutineStudy : MonoBehaviour
{
    // native code written by compiler service
    class PseudoCoroutineEnumerator : IEnumerator
    {
        int _state = 0;
        object _current = null;
        public object Current => _current;

        public bool MoveNext()
        {
            switch (_state)
            {
                case -1:
                    return false;
                case 0:
                    Debug.Log("DoPseudoCoroutine WaitForSeconds");
                    _state++;
                    _current = new WaitForSeconds(1.0f);
                    return true;
                case 1:
                    Debug.Log("DoPseudoCoroutine Null");
                    _state++;
                    _current = null;
                    return true;
                case 2:
                    _state = -1;
                    Debug.Log("DoPseudoCoroutine end");
                    return true;
            }
            return false;
        }

        public void Reset()
        {
            _state = 0;
        }
    }

    IEnumerator enumerator;                         // native code of UnityEngine
    private void Start()
    {
        StartPseudoCoroutine(DoPseudoCoroutine());  // native code of UnityEngine
        Debug.Log("Start");

    }

    float seconds = 1.0f;    // = WaitForSeconds.m_seconds
    float elapsed = .0f;     // native code of UnityEngine
    private void LateUpdate()
    {
        // native code of UnityEngine
        if (enumerator.Current != null)
        {
            if (enumerator.Current is WaitForSeconds)
            {
                if (seconds < elapsed)
                {
                    enumerator.MoveNext();
                }
                elapsed += Time.deltaTime;
            }
        }
        else
        {
            enumerator.MoveNext();
        }
    }

    // native code of UnityEngine
    void StartPseudoCoroutine(IEnumerator enumerator)
    {
        this.enumerator = enumerator;
        enumerator.MoveNext();
    }

    IEnumerator DoPseudoCoroutine()
    {
        // native code written by compiler service
        return new PseudoCoroutineEnumerator();
    }
}
```
<br>
[해당 링크](https://planek.tistory.com/36)에서는 추측이지만 위와 같이 동작 할 것이라고 한다.<br>
**MoveNext()와 Current를 참조해 코루틴을 구현하기 때문에 yield를 만나면 위와 같이 코드를 구분해서**<br>
순서대로 실행 할 수 있도록 **코드열거자와 같이 동작할 것이라는 것이다.**<br>
<br>

👉 **그 외**<br>
* 함수의 상태를 저장/복원 하는게 가능하다.<br>
->오래 걸리는 작업을 잠시 끊거나 원하는 타이밍에 함수를 잠시 스탑했다가 재시작 할 수 있다.<br>

* 원하는 타입으로 리턴이 가능하다. 심지어 클래스 타입 리턴도 가능하다.<br>
<br>
<br>

## 🔔 예제
👉 **예제 1**<br>
yield 의 간단한 예제로 아래 코드를 살펴보자.<br>
GetNumber() 라는 메서드는 3개의 yield return 문을 가지고 있다.<br>
만약 외부에서 이 GetNumber()를 호출하게 되면, 첫번째 호출시에는<br>
첫번째 yield return 10 을 실행하여 10을 리턴하게 되고,<br>
두번째로 호출되면 yield return 20 이 실행되어 20을 리턴하게 된다.<br>
이러한 방식으로 GetNumber()는 한꺼번에 10,20,30을 모두 리턴하는 것이 아니라,<br>
**한번 호출시마다 다음 yield return 문의 값을 리턴하는 것이다.**<br>
```c#
class Program
    //-> IEnumerable를 반환하고있는데, yield 구문을 만나고나서 컴파일러가
    //IEnumerable와 IEnumerator를 구현한 객체를 알아서 만들어주기 때문이다.
    static IEnumerable<int> GetNumber()
    {
        yield return 10;  // 첫번째 루프에서 리턴되는 값
        yield return 20;  // 두번째 루프에서 리턴되는 값
        yield return 30;  // 세번째 루프에서 리턴되는 값
    }

    static void Main(string[] args)
    {
        foreach (int num in GetNumber())
        {
            Console.WriteLine(num);
        }             
    }
}
```
<br>
<br>

👉 **예제 2**<br>
아래의 예제는 MyList라는 컬렉션 타입에 있는 데이타를 하나씩 리턴하는 GetEnumerator() 메서드의 샘플코드이다.<br>
예제의 GetEnumerator() 메서드는 데이타를 **하나씩 리턴하기 위해 yield return문을 while 루프 안에서 사용하고 있다.** ⭐<br>
클래스 안의 샘플 data는 1부터 5까지 숫자인데, 외부 호출자가 순차적으로 호출하면 yield return에서 하나씩 리턴한다.<br>
예를 들어, 처음에는 1을 리턴하고, 다음에는 2를, 그 다음에는 3을 리턴한다.<br>

호출자(Caller)가 이 메서드를 사용하는 방법은<br>
(1) foreach 문을 사용하여 C#에서 자동으로 Iterator 루프 처리를 하게 하는 방법과<br>
(2) GetEnumerator()로부터 IEnumerator 인터페이스를 얻어 MoveNext() 메서드와 Current 속성을 사용하여<br>
개발자가 직접 수동으로 요소를 하나씩 사용하는 방법이 있다.<br>
**일반적으로 그 편리성 때문에 foreach 문을 사용하는 방식을 사용한다.** ⭐<br>

아래 예제의 하단은 foreach문을 사용하여 Enumeration을 하는 방법과 IEnumerator의 멤버를 써서<br>
수동으로 Enumeration을 하는 방법을 예시하고 있다.<br>
```c#
public class MyList
{
    private int[] data = { 1, 2, 3, 4, 5 };
    
    public IEnumerator GetEnumerator()
    {
        int i = 0;
        while (i < data.Length)
        {
            yield return data[i];
            i++;                
        }
    }

    //...
}

class Program
{
    static void Main(string[] args)
    {
        // (1) foreach 사용하여 Iteration
        var list = new MyList();

        foreach (var item in list)  
        {
            Console.WriteLine(item);
        }

        // (2) 수동 Iteration
        IEnumerator it = list.GetEnumerator();
        it.MoveNext();
        Console.WriteLine(it.Current);  // 1
        it.MoveNext();
        Console.WriteLine(it.Current);  // 2
    }
}
```
<br>
<br>

## 🔔 yield 실행 순서<br>
C#에서 호출자가 yield를 가진 Iteration 메서드를 호출하면 다음과 같은 방식으로 실행된다.<br>
즉, 호출자(A)가 IEnumerable을 리턴하는 메서드(B)를 호출하면, yield return문에서 하나의 값을 리턴하고, 해당 메서드(B)의 위치를 기억해 둔다.<br>
호출자(A)가 다시 루프를 돌아 다음 값을 메서드(B)에 요청하면, 메서드의 기억된 위치 다음 문장부터 실행하여 다음 yield 문을 만나 값을 리턴한다.<br>
<br>
<br>

## 🔔 yield return 종류<br>
* 👉 yield return XX<br>
XX에는 System.Object를 상속 받는 것이라면 무엇이든간에 다 들어갈 수 있다. **즉 object 리턴.**<br>
IEnumerator 객체의 Current값에 해당 object 리턴 값이 대입된다. -> 제네릭 인터페이스도 존재<br>

* 👉 yield return null<br>
null을 리턴하므로 마땅히 ⭐ **리턴되는건 없지만 사실상 이 null을 리턴해주고<br>
다시 돌아오는 과정을 거치므로 1프레임 정도 한박자 쉬어주는 셈이다.** ⭐<br>

* 👉 yield break<br>
일반 함수의 return과 같다. 다시는 돌아가지 않으며 완전히 **종료**된다.<br>
<br>
<br>

## 🔔 yield 를 사용하면 좋은 경우<br>
* 만약 데이타의 양이 커서 모든 데이타를 한꺼번에 리턴하는 것하는 것 보다 조금씩 리턴하는 것이 더 효율적일 경우.<br>
예를 들어, 어떤 검색에서 1만 개의 자료가 존재하는데, UI에서 10개씩만 On Demand로 표시해 주는게 좋을 수도 있다.<br>
즉, 사용자가 20개를 원할 지, 1000개를 원할 지 모르기 때문에, 일종의 지연 실행(Lazy Operation)을 수행하는 것이 나을 수 있다.<br>

* 어떤 메서드가 무제한의 데이타를 리턴할 경우.<br>
예를 들어, 랜덤 숫자를 무제한 계속 리턴하는 함수는 결국 전체 리스트를 리턴할 수 없기 때문에 yield 를 사용해서 구현하게 된다.<br>

* 모든 데이타를 미리 계산하면 속도가 느려서 그때 그때 On Demand로 처리하는 것이 좋은 경우.<br>
예를 들어 소수(Prime Number)를 계속 리턴하는 함수의 경우, 소수 전체를 구하면<br>
(물론 무제한의 데이타를 리턴하는 경우이기도 하지만) 시간상 많은 계산 시간이 소요되므로 다음 소수만 리턴하는 함수를 만들어<br>
소요 시간을 분산하는 지연 계산(Lazy Calculation)을 구현할 수 있다.<br>
<br>
<br>

## 🔔 yield 와 예외<br>
yield return문은 try-catch 문 안에서 쓸 수 없다.<br>
yield break문은 try-catch 문 안에선 쓸 수 있지만 finally 에선 쓸 수 없다.<br>
<br>
<br>

## 🔔 참조링크
https://ansohxxn.github.io/c%20sharp/enumerate/ <br>
http://www.csharpstudy.com/CSharp/CSharp-yield.aspx <br>
https://planek.tistory.com/36 <br>
