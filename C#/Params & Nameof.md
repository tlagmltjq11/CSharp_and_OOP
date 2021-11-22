## 🔔 Params
일반적으로 메서드의 파라미터 갯수는 고정되어 있다.<br>
하지만 어떤 경우는 **파라미터의 갯수를 미리 알 수 없는 경우⭐**도 있는데,<br>
이런 경우 C# 키워드 params를 사용한다.<br>
-> **개수의 제한 없이 보내주는 대로 받는다.** ⭐<br>

이 params 키워드는 가변적인 배열을 인수로 갖게 해주는데,<br>
파라미터들 중 반드시 하나만 존재해야 하며, 맨 마지막에 위치해야 한다.<br>
**1차원 배열로 선언해야하며, 매개변수를 아예 보내지 않아도 된다.** ⭐<br>
<br>

paramas 사용 자체가 오버헤드일 수 있어서, 자주 사용되는 매개변수의 갯수가 있다면<br>
해당 메소드들을 오버로딩 해두는 것이 성능 상 좋다.<br>
-> 실제 Console 의 메소드들이 위와같이 구성되어 있다.<br>
<br>

```c#
//메서드
 int Calc(params int[] values)

//사용
int s = Calc(1,2,3,4);
s = Calc(6,7,8,9,10,11);
```
<br>
<br>

## 🔔 Nameof
**특정 변수나 타입, 혹은 멤버의 이름을 문자열로 반환한다.** ⭐<br>
<br>

```c#
Console.WriteLine(nameof(System.Collections.Generic)); // output: Generic
Console.WriteLine(nameof(List<int>)); // output: List
Console.WriteLine(nameof(List<int>.Count)); // output: Count
Console.WriteLine(nameof(List<int>.Add)); // output: Add

var numbers = new List<int> { 1, 2, 3 };
Console.WriteLine(nameof(numbers)); // output: numbers
Console.WriteLine(nameof(numbers.Count)); // output: Count
Console.WriteLine(nameof(numbers.Add)); // output: Add
```
<br>
<br>

**이러한 명칭들을 하드코딩하지 않게 하는 잇점이 있다.**<br>
즉, 이는 하드코딩에 의한 타이핑 오류 방지나 혹은 **차후 리팩토링에서 유연한 구조를 만들어 준다는 잇점이 있다.**<br>
예를 들어, 아래 예제와 같이 ArgumentException을 발생시킬 때, 파라미터명을 직접 하드코딩하지 않고 nameof()를 사용하면,<br>
만약 리팩토링을 통해 id가 identity로 변경하더라도 아무런 문제가 없게 된다.<br>
<br>

```c#
// 1. 파마미터명 id (Hard coding 하지 않음)
throw new ArgumentException("Invalid argument", nameof(id));

// 2. 속성명을 nameof 로 추출
Console.WriteLine("{0}: {1}", nameof(objPerson.Height), objPerson.Height);

// 3. 메서드명 로깅에 추가
void Run() {
   Log(nameof(Run) + " : Started");
}
```
<br>
<br>

## 🔔 참조링크
https://www.csharpstudy.com/CSharp/CSharp-method.aspx <br>
http://www.csharpstudy.com/CS6/CSharp-nameof.aspx <br>
https://huiyu.tistory.com/entry/Effective-C-nameof-%EC%97%B0%EC%82%B0%EC%9E%90 <br>
<br>
<br>

