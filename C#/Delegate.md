## 🔔 Delegate
delegate란 ⭐ **"대리인"** 이라는 의미로, ⭐ **함수 포인터**로 생각하면 쉽다.<br>
즉 함수들을 가리킬 수 있는 변수처럼 사용된다.<br>
<br>

⭐ **이러한 델리게이트는 콜백 메서드를 인자로 넘겨줄 때 많이 사용되며, 위에서 설명했듯 이벤트 처리에도 자주 사용된다.**<br>
<br>

👉 **사용법**<br>
1. 우선 delegate 원형 타입을 선언한다. (타입을 가진 클래스지 인스턴스가 아니다. ⭐)<br>

```c#
delegate float Calculate(float a, float b);
```
<br>

2. 선언된 delegate의 참조 변수를 선언한다.<br>

```c#
Calculate onCalculate;
```
<br>

3. 해당 변수에 콜백함수를 등록한다. (원형과 일치해야 함)<br>

```c#
  void Start()
  {
      onCalculate = Sum;
      onCalculate += Subtract;
      onCalculate -= Subreact;
      onCalculate += Multiply;
  }
```
<br>

4. delegate 참조 변수를 메서드처럼 실행한다.<br>

```c#
onCalculate(1, 10);
```
<br>
<br>

👉 **주의할 점**<br>
1. delegate의 리턴 값은 등록된 메서드들 중 가장 **마지막 메서드의 반환값**을 리턴한다.<br>
2. **null 검사**는 꼭 하도록 하자.<br>
<br>
<br>

## 🔔 Event Keyword
Event 키워드는 delegate의 참조변수를 생성할 때 앞에 추가하는 한정자이다.<br>
사실 실행 방식은 delegate만 사용할때와 크게 다를 바 없지만 event 키워드를 사용하는 주된 이유는<br>
⭐⭐ **delegate를 온전히 이벤트의 방향으로 사용되도록 제한하기 위해서이다.** ⭐⭐<br>

![이벤트](https://user-images.githubusercontent.com/43705434/125920725-3e13e496-371b-4d1d-8edc-db78e4f241b3.PNG)<br>
<br>
<br>

👉 **Delegate와의 차이점과 Event의 특징**<br>
1. ⭐⭐ **해당 event를 갖고있는 클래스 이외의 외부 클래스에서는 delegate를 실행시킬 수 없다.<br>
-> 이는 이벤트 기반 프로그래밍에서 안정성을 추구할 수 있도록 한다.** ⭐⭐<br>

2. 외부 클래스는 단순히 event 체인에 자신의 메서드를 추가/삭제만 할 수 있다.<br>

3.  다음 코드와 같이 이벤트 전체를 하나의 메서드로 덮어씌우는 경우를 제한한다.<br>
```c#
player.playerBoost += HealthBoost;
player.playerBoost += ShieldBoost;
player.playerBoost = DamageBoost;  // 덮어씌우기 방지. 에러💥
```
-> 이벤트를 사용하는 의미가 없어지기 때문.<br>
<br>

4. ⭐⭐ **이벤트는 인터페이스 내부에 선언할 수 있지만 델리게이트는 선언할 수 없다.**<br>
-> **event가 delegate의 프로퍼티 처럼 동작하기 때문임.** ⭐⭐<br>
<br>
<br>

👉 **추가 설명**<br>
⭐ **이벤트는 근본적으로 Property와 비슷하다.** Property가 get/set 을 가지는 반면 add/remove method를 가지고 있다.<br>
Field-like event를 선언하게 되면(명시적인 add/remove 선언을 하지 않은), public event가 만들어지고, back단에 private field가 만들어진다.<br>
이로써 public하게 등록 가능한, private event가 만들어지는 것이다. 단순한 Public delegate field로써는 다른 누구든지 해당 delegate 이벤트를<br>
제거하거나 호출할 수 있고 이는 encapsulation 재앙을 가져온다. 따라서 기능적인 관점에서 event keyword를 붙이나 안붙이나 비슷하지만,<br>
Encapsulation의 관점에서 본다면 event를 붙이게 되면 ⭐ **Access Contorl** 을 가능하게 할 수 있다.<br>
(선언된 Class 외부에서 Invoke, Clear, Assign(+=, -=제외)을 할 수 없다.)<br>
<br>
<br>
    
## 🔔 Action && Func
델리게이트를 사용하기 위해서는, 필요한 델리게이트 형태에 맞춰서 타입을 선언해줘야하는데,<br>
만약 무명 메소드로 잠깐 사용하거나 델리게이트 형태가 많은 경우 잦은 선언에 불편함이있다.<br>
⭐ **C#에서는 이런 불편함을 줄이기 위해 Func와 Action delegate가 미리 선언되어있다.** ⭐<br>
<br>

👉 Action - 매개 변수를 0~16개 가질 수 있는 ⭐ **값을 반환하지 않는** 메서드의 대리자<br>
```c#
Action output1 = () => Console.WriteLine("AAAA");
output1();
 
Action<int> output2 = (v) => Console.WriteLine(v);
output2(2);
```
<br>


👉 Func - 매개 변수를 0~16개를 가질 수 있는 ⭐ **값을 반환하는** 메서드의 대리자<br>
```c#
Func<int> value = () => 2+8;
Console.WriteLine(value());

Func<int, int, int> plus = (n1, n2) => n1 + n2;    
Console.WriteLine(plus(2, 7));

Func<int, int, float> minus = (n1, n2) => n1 * n2 * 0.5f; 
Console.WriteLine(minus(6, 7));
```
<br>
<br>

위 내용을 복기했다면 [다음 링크](https://github.com/tlagmltjq11/Game_Programming/blob/main/_Unity/UnityEvent.md)도 복습해야 한다.<br>
<br>
<br>
