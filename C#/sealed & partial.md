## 🔔 sealed
봉인클래스(Sealed Class)는 해당 클래스로부터 다른 파생클래스를 생성할 수 없는 클래스를 말한다.<br>
-> **즉 상속받지 못하도록 봉인하는 키워드다.** ⭐<br>
봉인클래스는 C#에서 sealed라는 키워를 class앞에 붙여 만들며, 기본클래스/추상클래스가 될 수 없다.<br>
그리고 이 sealed는 클래스 뿐 아니라 **속성이나 함수에서도 사용이 가능하다.** ⭐<br>
클래스에 sealed가 없고 함수나 속성에 sealed가 있다면 해당 클래스를 상속 받은 클래스에서는<br>
함수나 속성을 재정의 하는 것이 불가능하다.<br>
<br>

```c#
public sealed class D
{
    // Class members here.
}

public class D : C
{
    public sealed override void DoWork() { }
}
```
<br>
<br>

## 🔔 partial
partial class란 **동일한 클래스를 여러개로 분리하여(서로 다른 파일에서도 가능) 개발 가능하도록 구현된 기술이다.**<br> 
두개 이상의 파일에 하나의 클래스를 구현해 줄수가 있다. 이렇게 함으로써 얻을 수 있는 이점들은 다음과 같다.<br>

* **이러한 Partial 기능은 개발자에게 포커스 해야하는 코드를 분리해 준다는 점에서 크게 도움이 된다.** ⭐<br>
* **또한 소스가 꼬이는 일을 방지할 수 있다.**<br>
-> 무분별하게 나누면 오히려 복잡해 질 수 있다.<br>

partial class는 CLR 수준이 아닌 **C# Compiler 수준에서 실제 컴파일시에 하나의 클래스로 인식하여 단일 코드로 취합한다.** ⭐<br> 
<br>

```c#
// 1. Partial Class - 3개로 분리한 경우
partial class Class1
{
    public void Run() { }
}

partial class Class1
{
    public void Get() { }
}

partial class Class1
{
    public void Put() { }
}

// 2. Partial Struct
partial struct Struct1
{
    public int ID;
}

partial struct Struct1
{
    public string Name;

    public Struct1(int id, string name)
    {
        this.ID = id;
        this.Name = name;
    }
}

// 3. Partial Interface
partial interface IDoable
{
    string Name { get; set; }
}

partial interface IDoable
{
    void Do();
}

// IDoable 인터페이스를 구현
public class DoClass : IDoable
{
    public string Name { get; set; }

    public void Do()
    {
    }
}
```
<br>

Method에도 partial을 사용할 수 있다.<br>
<br>
<br>

## 🔔 참조링크
https://www.csharpstudy.com/CSharp/CSharp-partial.aspx <br>
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=cookatrice&logNo=50045096389 <br>
