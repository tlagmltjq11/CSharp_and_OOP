## IComparable & IComparer
IComparable(T)를 이용하여 **타입**의 **기본적인 정렬 방식**을 정의하고 IComparer(T)를 이용하여 기본적인 선후 관계 **이외에 추가적인 선후 관계**를 정의할 수 있다.<br>
C#에 정의되어 있는 int, double, string 등의 **기본 타입**들은 IComparable 인터페이스를 기본적으로 구현하고 있어서 **대상 객체간의 기본적인 비교가 가능하다.**<br>
-> IComparable 인터페이스를 구현했기 때문에 해당 타입을 담은 **컬렉션은 Sort 메서드를 이용해 정렬이 가능하다.**<br>
-> 즉 어떠한 기본 정렬 방식으로 정렬을 진행할지 IComparable 인터페이스를 구현하여 제공했기에 가능한 것.<br>
<br>

그리고 **IComparer 개체를 입력 인자로 받는 Sort 메서드**가 중복 정의되어 있는데 정렬하는 과정에서 입력 **인자로 받은 IComparer 개체를 이용한다.**<br>
-> 기본 방식으로 정렬하는 것이 아니라 **새로운 기준을 기반으로 정렬하고 싶다면 IComparer를 구현한 클래스**를 넘겨주면 되는 것.<br>
-> 혹은 public delegate int Comparison(in T)(T x, T y); 해당 델리게이트를 이용해 익명함수를 넘겨주는 방식으로도 기준을 바꿀 수 있다.<br>
<br>

사용자가 정의한 클래스나 구조체는 여러 필드나 속성을 포함할 수 있으므로 `어떤 기준으로 정렬할 지를 사용자가 지정해야한다.`<br>
사용자가 클래스를 정의할 때 `IComparable` 인터페이스 기반으로 정의하고 CompareTo 메서드를 정의하면 객체의 컬렉션에서 Sort 메서드를 사용할 수 있다.<br>
또한 다른 정렬 방식을 원한다면 `IComparer`를 구현한 객체를 넘겨주어 해결할 수 있다.<br>
<br>
<br>

## 제네릭을 사용하지 않는 IComparable
타입(T) 매개변수를 취하지 않고 **object를 매개변수로 취하는 IComparable은 상당히 많은 단점이 있는데**<br>
이 인터페이스를 구현하려면 매개변수에 대한 **타입을 런타임에 확인**해야 한다.<br>
즉, CompareTo()에 **올바르지 않은 객체를 전달하는 경우에도 아무런 방비가 없다.**<br>
올바른 객체를 전달한다고 하더라도 실제 비교를 위해서 **박싱/언박싱 작업이 필요하게 되고**<br>
이 작업은 앞선 항목에서도 말한바와 같이 **성능에 상당히 많은 비용을 지불해야 한다.**<br>
그럼 제네릭 버전이 아닌 IComparable 인터페이스를 왜 구현해야 하는지 의문이 들지도 모르겠다.<br>
**여전히 제네릭을 쓰지 않는 많은 API들을 위해서 즉, 하위 호환성을 위해서 구현해야 한다.**<br>
짧게 얘기하자면 .NET 프레임워크 2.0 이전에 개발된 코드에서 이 타입을 사용하려면 반드시 이 인터페이스를 구현해야 한다.<br>
```c#
public struct Customer : IComparable<Customer>, IComparable
```
<br>
<br>

## IComparable 예시

**Interface**<br>
```c#
interface IComparable<T>
{
    int CompareTo(T other);
}
    
interface IComparable
{
    int CompareTo(object obj);
}
```
<br>

**Implementation**<br>
```c#
class Member : IComparable
{
    string name;
    string addr;
    public Member(string name, string addr)
    {
        this.name = name;
        this.addr = addr;
    }
 
    //제네릭을 사용하지 않은 버전
    public int CompareTo(object obj) //IComparable에서 약속한 메서드 구현
    {
        Member member = obj as Member;
        if (member == null)
        {
            throw new ApplicationException("Member 개체가 아닙니다.");
        }
        
        return name.CompareTo(member.name); //정렬 기준
    }
    
    public override string ToString()
    {
        return string.Format("이름:{0} 주소:{1}",name,addr);
    }
}

class Program
{
    static void Main(string[] args)
    {
        Member[] members = new Member[3];
        members[0] = new Member("홍길동", "율도국");
        members[1] = new Member("강감찬", "대한민국");
        members[2] = new Member("장언휴", "이에이치");
 
        Array.Sort(members);
 
        foreach (Member member in members)
        {
            Console.WriteLine(member);
        }
    }
}

//실행 결과
이름:강감찬 주소:대한민국
이름:장언휴 주소:이에이치
이름:홍길동 주소:율도국
```
<br>
<br>

## IComparer 예시

**Interface**<br>
```c#
interface IComparer<T>
{
    int Compare(T x, T y);
}
    
interface IComparer
{
    int Compare(object x, object y);
}
```
<br>

**Implementation**<br>
```c#
class AddrComparer : IComparer
{
    //제네릭을 사용하지 않은 버전
    public int Compare(object x, object y) // IComparer에서 약속한 기능 구현
    {
        Member mx = x as Member;
        Member my = y as Member;
 
        if ((mx == null) || (my == null)) 
        {
            throw new ApplicationException("Member 개체가 아닌 인자가 있습니다.");
        }
 
        return mx.Addr.CompareTo(my.Addr);
    }
}
    
class Member : IComparable
{
    string name;
    public string Addr
    {
        get;
        private set;
    }
 
    public Member(string name, string addr)
    {
        this.name = name;
        this.Addr = addr;
    }
 
    public int CompareTo(object obj) //IComparable에서 약속한 기능 구현
    {
        Member member = obj as Member;
        if (member == null)
        {
            throw new ApplicationException("입력 인자가 Member 개체가 아닙니다. ");
        }
        return name.CompareTo(member.name);
    }
 
    public override string ToString()
    {
        return string.Format("이름:{0} 주소:{1}", name, Addr);
    }
}
 
class Program
{
    static void Main(string[] args)
    {
        Member[] members = new Member[3];
        members[0] = new Member("홍길동", "율도국");
        members[1] = new Member("강감찬", "대한민국");
        members[2] = new Member("장언휴", "이에이치");
        
        Array.Sort(members); //요소의 CompareTo 메서드 이용하여 정렬
        
        foreach (Member member in members)
        {
            Console.WriteLine(member);
        }
        
        Array.Sort(members, new AddrComparer()); //IComparer 개체를 이용하여 정렬
        
        Console.WriteLine("-------------------------");
        foreach (Member member in members)
        {
            Console.WriteLine(member);
        }
    }
}

//실행 결과
이름:강감찬 주소:대한민국
이름:장언휴 주소:이에이치
이름:홍길동 주소:율도국
-----------------------------
이름:강감찬 주소:대한민국
이름:홍길동 주소:율도국
이름:장언휴 주소:이에이치
```
<br>
<br>   
    
## 참조링크
https://smujihoon.tistory.com/178<br>
https://andjjip.tistory.com/153<br>
https://ehpub.co.kr/<br>
https://blog.daum.net/save_us_222/41<br>
<br>
<br>
