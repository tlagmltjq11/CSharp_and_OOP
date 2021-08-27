## 🔔 Nullable이란
C#에서 정수, 부동자릿수, 구조체 등의 **Value Type은 NULL을 가질 수 없다.** ⭐<br>
예를 들어, 정수 int i 가 있을 때 변수 i에는 null을 할당할 수 없으며,<br>
따라서 변수 i는 어떤 **값이 할당되지 않은 상태 (missing value)를 가질 수 없다.**<br>
만약 정수형 변수 i에 값이 설정되지 않은 상태를 할당하려면, 개발자는 2가지 방법을 사용할 수 있을 것이다.<br>
(1)프로그램에서 사용될 것 같지 않은 특정 값을 추정하여 할당하던지 (예를 들어, int i = int.MaxValue;)<br>
(2)아니면 또 하나의 변수를 두어 변수 i가 missing임을 나타내게 할 수 있다. (예를 들어, bool iHasValue = false;)<br>
이 **두번째 방식이 Nullable의 기본 아이디어다.**<br>
<br>

C# 에서는 **Value Type에도 null을 할당할 수 있는 Nullable 타입을 지원한다.** ⭐<br>
Nullable 타입은 Value 값을 갖고 있으면서 **NULL 상태를 체크할 수 있는 기능(HasValue⭐)** 을 함께 가지고 있는 **struct** 이다.<br>
**따라서 Nullable 타입은 struct(구조체)이므로 Value Type이다.** ⭐<br>

C#에서 int? 와 같이 해당 Value Type 뒤에 물음표를 붙이면, 해당 정수형 타입이 Nullable 정수형 타입임을 의미한다.<br>
즉, 이 변수에는 NULL을 할당할 수 있다.<br> C#의 이러한 특별한 문법은 .NET의 Nullable(T) 구조체로 **컴파일시에 변환된다.** ⭐<br>
즉, **int?는 Nullable(int)와 동일하다.**<br>
<br>

**Nullable(T)로 선언하는 방법**<br>
```c#
int? i = null;
bool? b = null;
int?[] a = new int?[100];
```
<br>
<br>

## 🔔 Nullable(T) 구조체

![널러블](https://user-images.githubusercontent.com/43705434/131155386-deec4add-c9e6-4281-8dfe-e7e91c4f7cdd.PNG)<br>
<br>

👉 **속성과 메서드**<br>

1. HasValue 속성<br>
값이 있는 경우  : true<br>
값이 없는 경우(Null) : false<br>

2. Value 속성<br>
값이 있는 경우 : 할당된 값<br>
값이 없는 경우(null) : 예외(Exception) 발생<br>

3. GetValueOrDefault() 메서드<br>
값이 있는 경우 : 할당된 값 반환<br>
값이 없는 경우(Null) : 기존 타입의 default 값 반환<br>
<br>
<br>

👉 **사용법**<br>
```c#
Nullable<int> a;    // int? a;
a = null;

Console.WriteLine(a);                        // null이 나옵니다.
Console.WriteLine(a.HasValue);              // 할당된 값이 없으므로 false
Console.WriteLine(a.Value);                // 할당된 값이 없으므로 예외
Console.WriteLine(a.GetValueOrDefault()); // 할당된 값이 없으므로 int 타입의 default 값인 0 이 반환됩니다.

int? b;            // Nullable<int> b;
b = 10;
Console.WriteLine(b);                        // 10이 나옵니다.
Console.WriteLine(b.HasValue);              // 할당된 값이 있으므로 true
Console.WriteLine(b.Value);                // 할당된 값이 있으므로 10
Console.WriteLine(b.GetValueOrDefault()); // 할당된 값이 있으므로 10이 반환됩니다.
```
<br>
<br>

👉 **주의할 점**<br>
* Value를 접근할때는 HasValue로 체크 한 후에 접근하기.⭐⭐⭐<br>
위에 예시에서 봤겠지만 **값이 존재하지 않는 Null인 경우<br>
Value에 바로 접근하게 되면 예외가 발생하며 프로세스가 죽을 위험이 있다.**<br>
그렇기 때문에 HasValue로 값이 존재하는지 체크 한 후 에 Value에 안전하게 접근해야 한다.<br>

* int, int?는 엄연히 다른 타입이므로 **캐스팅**에 주의해야 한다.⭐<br>
<br>
<br>

👉 **예제**<br>
Nullable 타입이 실무에서 흔히 사용되는 케이스는 **DB와 연동되는 Data Layer 클래스**들을 들 수 있는데,<br>
예를 들어 SQL 서버 테이블에서 NULL을 허용하는 숫자, 날짜, bool등의 컬럼이 있다면,<br>
이 컬럼 타입은 Nullable 타입으로 변환되어 테이블의 NULL 속성을 표현하게 된다.<br>
아래 예제는 다양한 종류의 Nullable 파라미터를 받아들여 HasValue로 NULL 값을 미리 체크한 후,<br>
.Value 속성을 써서 해당 타입의 실제 값을 사용하고 있다.<br>

Nullable 타입과 연관되어 자주 사용되는 C#의 ?? 연산자는 ?? 앞의 파라미터가 NULL인 경우 연산자 뒤의 값을 할당할 때 사용한다.<br>
```c#
double _Sum = 0;
DateTime _Time;
bool? _Selected;

public void CheckInput(int? i, double? d, DateTime? time, bool? selected)
{
    if (i.HasValue && d.HasValue)
        this._Sum = (double)i.Value + (double)d.Value;

    // time값이 있는 체크.
    if (!time.HasValue)
        throw new ArgumentException();
    else
        this._Time = time.Value;

    // 만약 selected가 NULL이면 false를 할당
    this._Selected = selected ?? false;
}
```
<br>
<br>

## 🔔 Nullable static 클래스
.NET Framework에 있는 정적(static) 클래스 System.Nullable 은 **두개의 Nullable 객체를 비교**하거나 (**Compare(), Equals() 메서드**),<br>
특정 **Nullable 타입이 어떤 Value 타입에 기반을 두고 있는지** 알아내는 (**GetUnderlyingType() 메서드**) 기능을 제공하고 있다.<br>
**이 정적 클래스는 Nullable(T) 타입을 위한 몇 가지 편리한 정적 메서드들을 제공한다.** ⭐<br>
<br>

```c#
void NullableTest()
{
    int? a = null;
    int? b = 0;            
    int result = Nullable.Compare<int>(a, b);
    Console.WriteLine(result); //결과 -1

    double? c = 0.01;
    double? d = 0.0100;
    bool result2 = Nullable.Equals<double>(c, d);
    Console.WriteLine(result2); //결과 true
}
```
<br>
<br>

## 🔔 Null Operator

👉 null 조건 연산자 = **?. 와 ?[]**<br>
![널연산자1](https://user-images.githubusercontent.com/43705434/131155389-247b5546-2883-4825-abd8-0e57b791f753.PNG)<br>
<br>
두 연산자 모두 **왼쪽 피연산자의 값을 검사 후**, 이 값이 **null이 아닌 경우에만 연산자 오른쪽의 표현식을 실행한다.**<br>
만약 왼쪽 피연산자의 값이 null이라면 연산자 오른쪽의 표현식을 실행하지 않고 null을 반환한다.<br>
<br>

**예제** ⭐<br>
```c#
int? length = customers?.Length; // customers가 null일 경우 null
Customer first = customers?[0]; // customers가 null일 경우 null
int? count = customers?[0]?.Orders?.Count(); // customers, customers[0], Orders 중 하나라도 null일 경우 null
```
<br>

여기서 마지막 문장만 보면 총 3개의 널 조건 연산자가 사용되었고,<br>
'customers 검사 -> customers[0] 검사 -> customers.Orders 검사'와 같이 진행됨을 볼 수 있다.<br>
셋 중 하나라도 null이 나온다면 count에는 null이 들어가게 될 것이다.<br>
<br>
<br>

👉 null 병합 연산자 = **??**<br>
**?? 왼쪽의 변수가 null 일 경우 오른쪽 값을 리턴<br>
?? 왼쪽의 변수가 null 이 아닐 경우 왼쪽 변수의 값을 리턴**<br>
<br>

**예제** ⭐<br>
```c#
int? count = null;
int cnt = count ?? 100;    //count 가 null 이므로 오른쪽 100 이 리턴되어 cnt = 100
                        //만약 count 가 null 이 아니고 값이 있다면 cnt = count
```
<br>
<br>

👉 null 조건 연산자 + null 병합 연산자<br>
위 두 연산자는 함께 사용할 때 위력이 증가한다.<br>
?. 만 사용하게 되면 리턴을 받을 변수는 무조건 null을 받을 수 있는 타입이어야 한다.<br>
**만약 null을 가질 수 없는 경우라면 혹은 null이 아니어야만 한다면<br>
?? 연산자를 함께 사용하면 해결할 수 있다.<br>
즉 null인 경우 ?? 뒤의 디폴트 값을 리턴하게 하면 된다.**<br>
<br>

**예제** ⭐<br>
```c#
// rows가 NULL이면 cnt = 0
// 아니면 cnt는 실제 rows 갯수

int cnt = rows?.Count ?? 0;
```
<br>

👉 IsOfNullableType(var);<br>
만일 nullable이라면 True를, 그렇지 않으면 False를 반환한다.<br>
<br>
<br>

## 🔔 참조링크
http://www.csharpstudy.com//CSharp/CSharp-nullable.aspx <br>
https://www.csharpstudy.com/CS6/CSharp-null-conditional-operator.aspx <br>
https://blockdmask.tistory.com/360 <br>
https://blog.hexabrain.net/315 <br>
https://blog.hexabrain.net/315 <br>
https://skuld2000.tistory.com/17 <br>
