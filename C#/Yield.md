## yield
C#의 yield 키워드는 호출자(Caller)에게 컬렉션 데이터를 하나씩 리턴할 때 사용한다.<br>
흔히 Enumerator(Iterator)라고 불리우는 이러한 기능은 집합적인 데이터셋으로부터 데이터를 하나씩 호출자에게 보내주는 역할을 한다.<br>

yield는 yield return 또는 yield break의 2가지 방식으로 사용되는데,<br>
(1) yield return은 컬렉션 데이터를 하나씩 리턴하는데 사용된다.<br>
(2) yield break는 리턴을 중지하고 Iteration 루프를 빠져 나올 때 사용한다.<br>

**즉 yield는 IEnumerator/IEnumerable 의 간편표기법이다.**<br>
yield를 통해 IEnumerable, IEnumerator 를 상속받는 객체를 간단하게 구현할 수 있는 것이나 마찬가지다.<br>

✈ yield 장점Permalink
yield를 사용하면 Ienumerable, IEnumerator를 상속받는 클래스를 작성해 줄 필요 없다.<br>
IEnumerable 클래스에서 GetEnumerator() 메서드를 구현하는 한 방법으로 yield 를 사용할 수 있다.<br>
-> 즉 IEnumerable를 구현하는 하나의 방법으로 yield 사용 방식을 채택 할 수 있다는 것이다.<br>
즉 GetEnumerator() 메서드에서 yield return를 사용하여 컬렉션 데이타를 순차적으로 하나씩 넘겨주는 코드를 구현하고,<br>
리턴타입으로 IEnumerator를 리턴할 수 있다.<br>

C#에서 Iterator 방식으로 yield 를 사용하면, 명시적으로 별도의 Enumerator 클래스를 작성할 필요가 없다.<br>
-> **컴파일러가 알아서 만들어주기 때문이다! (밑에 참고)**<br>

비동기적 실행이 가능<br>
⭐ yield return문을 만나면 함수를 호출한 곳에 리턴을 해준 후 다시 돌아와서 다음 yield return문을 실행한다.<br>
즉, 하나의 함수가 끝까지 다 실행할 때까지 기다리는 것이 아니라 yield를 만나면 잠시 함수 중간에 빠져나와 호출한 곳에<br>
리턴 값을 전달해주고 다시 돌아와 마저 함수를 진행하는 식으로 왔다 갔다 하며 실행되는 것이다.<br>

유니티에서는 yield return WaitForSeconds(float) 같은 것을 사용하면 프레임마다 직접 초를 세면서 대기하는 것으로 코딩하는 것보다 훨씬 성능상 유리하다.<br>

함수의 상태를 저장/복원 하는게 가능<br>
엄청 오래 걸리는 작업을 잠시 끊거나<br>
원하는 타이밍에 함수를 잠시 스탑했다가 복원하려는 경우<br>
리턴은 우리가 원하는 타입으로 가능<br>
심지어 클래스 타입 리턴도 가능<br>

**예제 1**<br>
yield 의 간단한 예제로 아래 코드를 살펴보자.<br>
GetNumber() 라는 메서드는 3개의 yield return 문을 가지고 있다.<br>
만약 외부에서 이 GetNumber()를 호출하게 되면, 첫번째 호출시에는<br>
첫번째 yield return 10 을 실행하여 10을 리턴하게 되고,<br>
두번째로 호출되면 yield return 20 이 실행되어 20을 리턴하게 된다.<br>
이러한 방식으로 GetNumber()는 한꺼번에 10,20,30을 모두 리턴하는 것이 아니라,<br>
한번 호출시마다 다음 yield return 문의 값을 리턴하는 것이다.<br>
```c#
class Program
    //-> IEnumerable를 반환하고있는데, yield 구문을 만나고나서 컴파일러가 IEnumerable와 IEnumerator를 구현한 객체를 알아서 만들어주기 때문이다.
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

**예제 2**<br>
아래의 예제는 MyList라는 컬렉션 타입에 있는 데이타를 하나씩 리턴하는 GetEnumerator() 메서드의 샘플코드이다.<br>
예제의 GetEnumerator() 메서드는 데이타를 하나씩 리턴하기 위해 yield return문을 while 루프 안에서 사용하고 있다.<br>
클래스 안의 샘플 data는 1부터 5까지 숫자인데, 외부 호출자가 순차적으로 호출하면 yield return에서 하나씩 리턴한다.<br>
예를 들어, 처음에는 1을 리턴하고, 다음에는 2를, 그 다음에는 3을 리턴한다.<br>

호출자(Caller)가 이 메서드를 사용하는 방법은<br>
(1) foreach 문을 사용하여 C#에서 자동으로 Iterator 루프 처리를 하게 하는 방법과<br>
(2) GetEnumerator()로부터 IEnumerator 인터페이스를 얻어 MoveNext() 메서드와 Current 속성을 사용하여<br>
개발자가 직접 수동으로 요소를 하나씩 사용하는 방법이 있다.<br>
일반적으로 그 편리성 때문에 foreach 문을 사용하는 방식을 사용한다.<br>

아래 예제의 하단은 foreach문을 사용하여 Enumeration을 하는 방법과 IEnumerator의 멤버를 써서 수동으로 Enumeration을 하는 방법을 예시하고 있다.<br>
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

✈ yield return 을 만나면 생기는 일<br>
IEnumerable/IEnumerator 클래스를 컴파일러가 알아서 만들어준다.<br>

```c#
IEnumerable Test()
{
    yield return 1;
    yield return 2;
    yield return 3;
}
```
<br>

자동으로 컴파일러가 IEnumerable, IEnumerator 클래스를 알아서 생성해준다.<br>
인덱스의 초기값은 -1 인 상태에서 시작한다.<br>
MoveNext()를 통해 다음 yield 구문을 만날 때까지 다음 실행을 한다.<br>

MoveNext() 가 실행되어 yield return 1 이전까지만 실행되고 인덱스 값은 0 이 된다. 이때 Current를 읽고 1 을 리턴한다.<br>
리턴 후 다시 돌아오면 MoveNext() 가 실행되어 yield return 2; 이전까지만 실행되고 인덱스 값은 1 이 된다. 이때 Current를 읽고 2 을 리턴한다.<br>
리턴 후 다시 돌아오면 MoveNext() 가 실행되어 yield return 3; 이전까지만 실행되고 인덱스 값은 2 이 된다. 이때 Current를 읽고 3 을 리턴한다.<br>
리턴 후 다시 돌아오니 더 이상 yield 가 없어서 MoveNext() 가 false를 리턴한다. 그러므로 이제 완전 종료된다.<br>
IEnumerator 혹은 IEnumerable 을 리턴하는 함수안에 yield return을 사용하기만 하면, 컴파일러가 알아서 IEnumerable, IEnumerator클래스를 만들어준다.<br>
즉, IEnumerator를 상속받고 구현한 클래스를 만들어 줄 필요가 없는 것이다.<br>

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
            Console.WriteLine(item); // 1 2 3 4 5 
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

C# yield 실행 순서<br>
C#에서 호출자가 yield를 가진 Iteration 메서드를 호출하면 다음과 같은 방식으로 실행된다.<br>
즉, 호출자(A)가 IEnumerable을 리턴하는 메서드(B)를 호출하면, yield return문에서 하나의 값을 리턴하고, 해당 메서드(B)의 위치를 기억해 둔다.<br>
호출자(A)가 다시 루프를 돌아 다음 값을 메서드(B)에 요청하면, 메서드의 기억된 위치 다음 문장부터 실행하여 다음 yield 문을 만나 값을 리턴한다.<br>

✈ yield return 종류<br>
yield return 땡땡<br>
땡땡에는 System.Object를 상속 받는 것이라면 무엇이든간에 다 들어갈 수 있다. 즉 object 리턴.<br>
뭐든 리턴할 수 있다는 얘기!.<br>
IEnumerator 객체의 Current값에 해당 object 리턴 값이 대입된다.<br>
yield return null<br>
null을 리턴하므로 마땅히 리턴되는건 없지만 사실상 이 null을 리턴해주고 다시 돌아오는 과정을 거치므로 1프레임 정도 한박자 쉬어주는 셈이다.<br>
yield break<br>
일반 함수의 return과 같다. 다시는 돌아가지 않으며 완전히 종료된다.<br>
<br>

✈ yield 를 사용하면 좋은 경우<br>
만약 데이타의 양이 커서 모든 데이타를 한꺼번에 리턴하는 것하는 것 보다 조금씩 리턴하는 것이 더 효율적일 경우.<br>
예를 들어, 어떤 검색에서 1만 개의 자료가 존재하는데, UI에서 10개씩만 On Demand로 표시해 주는게 좋을 수도 있다.<br>
즉, 사용자가 20개를 원할 지, 1000개를 원할 지 모르기 때문에, 일종의 지연 실행(Lazy Operation)을 수행하는 것이 나을 수 있다.<br>
어떤 메서드가 무제한의 데이타를 리턴할 경우.<br>
예를 들어, 랜덤 숫자를 무제한 계속 리턴하는 함수는 결국 전체 리스트를 리턴할 수 없기 때문에 yield 를 사용해서 구현하게 된다.<br>
모든 데이타를 미리 계산하면 속도가 느려서 그때 그때 On Demand로 처리하는 것이 좋은 경우.<br>
예를 들어 소수(Prime Number)를 계속 리턴하는 함수의 경우, 소수 전체를 구하면<br>
(물론 무제한의 데이타를 리턴하는 경우이기도 하지만) 시간상 많은 계산 시간이 소요되므로 다음 소수만 리턴하는 함수를 만들어<br>
소요 시간을 분산하는 지연 계산(Lazy Calculation)을 구현할 수 있다.<br>
<br>

✈ yield 와 예외<br>
yield return문은 try-catch 문 안에서 쓸 수 없다.<br>
yield break문은 try-catch 문 안에선 쓸 수 있지만 finally 에선 쓸 수 없다.<br>
<br>

## 참조링크
https://ansohxxn.github.io/c%20sharp/enumerate/ <br>
http://www.csharpstudy.com/CSharp/CSharp-yield.aspx <br>
