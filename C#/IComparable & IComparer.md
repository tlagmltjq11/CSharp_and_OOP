## IComparable & IComparer
IComarable 인터페이스와 IComparer 인터페이스는 개체의 값 비교(선후 관계)를 제공하기 위해 정의되었다.<br>
C#의 컬렉션은 대부분 Sort 메서드를 제공하는데 IComparable 인터페이스 기반의 요소를 보관하고 있을 때<br>
정상적으로 동작하고 그렇지 않으면 예외를 발생한다.<br>
-> 즉 정렬할 때 어떠한 기본방식으로 개체의 값을 비교할 것인지 IComparable 인터페이스를 구현하여 방식을 제공해야 한다는 것<br>

그리고 IComparer 개체를 입력 인자로 받는 Sort 메서드가 중복 정의되어 있는데<br>
정렬하는 과정에서 입력 인자로 받은 IComparer 개체를 이용한다.<br>
-> 기본 방식으로 정렬하는 것이 아니라 새로운 기준을 기반으로 정렬하고 싶다면 IComparer를 구현한 클래스를 넘겨주면 되는 것.<br>

IComparable<T>를 이용하여 타입의 기본적인 선후 관계를 정의하고 IComparer<T>를 이용하여 기본적인 선후 관계 이외에 추가적인 선후 관계를 정의할 수 있다.

C#에 정의되어 있는 int, double, string 등의 기본 형식들은 IComparable 인터페이스를 기본적으로 구현하고 있어서 대상 객체간의 기본적인 비교가 가능하다. -> 고로 이러한 기본 형식을 보관한 컬렉션은 Sort 메서드를 이용해 정렬이 가능한 것이다.
사용자가 정의한 클래스나 구조체는 여러 필드나 속성을 포함할 수 있으므로 어떤 기준으로 정렬할 지를 사용자가 지정해야한다. 사용자가 클래스를 정의할 때 IComparable 인터페이스 기반으로 정의하고 CompareTo 메서드를 정의하면 객체의 컬렉션에서 Sort 메서드를 사용할 수 있다.
    
C#의 System에 정의되어 있는 기본 형식들은 ICompable 인터페이스를 기반으로 정의되어 있어서<br>
기본 형식을 보관한 컬렉션은 Sort 메서드를 이용하여 정렬할 수 있다.<br>
<br>
    
.NET 환경이 제공하는 최신 API는 IComparable<T>를 사용하지만 일부 오래된 API들은 여전히 IComparable를 구현하기 때문에 IComparable<T>를 구현할 때는 IComparable를 같이 구현해줘야 한다.    
    public struct Customer : IComparable<Customer>, IComparable
그런데 타입 매개변수를 취하지 않고 object를 매개변수로 취하는 IComparable은 상당히 많은 단점이 있는데 이 인터페이스를 구현하려면 매개변수에 대한 타입을 런타임에 확인해야 한다.
즉, CompareTo()에 올바르지 않은 객체를 전달하는 경우에도 아무런 방비가 없다. 올바른 객체를 전달한다고 하더라도 실제 비교를 위해서 박싱/언박싱 작업이 필요하게 되고 이 작업은 앞선 항목에서도 말한바와 같이 성능에 상당히 많은 비용을 지불해야 한다.
그럼 제네릭 버전이 아닌 IComparable 인터페이스를 왜 구현해야 하는지 의문이 들지도 모르겠다. 앞서 잠깐 얘기했었는데 여전히 제네릭을 쓰지 않는 많은 API들을 위해서 즉, 하위 호환성을 위해서 구현해야 한다. 짧게 얘기하자면 .NET 프레임워크 2.0 이전에 개발된 코드에서 이 타입을 사용하려면 반드시 이 인터페이스를 구현해야 한다.


```c#
interface IComparable<T>
{
    int CompareTo(T other);
}
    
interface IComparable
{
    int CompareTo(object obj);
}

class Member:IComparable
{
    string name;
    string addr;
    public Member(string name, string addr)
    {
        this.name = name;
        this.addr = addr;
    }
 
    public int CompareTo(object obj) //IComparable에서 약속한 메서드 구현
    {
        Member member = obj as Member;
        if (member == null)
        {
            throw new ApplicationException("Member 개체가 아닙니다.");
        }
        return name.CompareTo(member.name);
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

    int 형식을 저장하고 있는 배열이 있고 해당 배열의 Sort 메서드를 호출 할 경우 정렬하는 과정에서 각 숫자를 비교하는 기본 동작을 제공한다. 그런데, int 형식의 기본 비교 로직은 IComparable 인터페이스를 상속하여 CompareTo 메소드를 내림차순으로 구현하고 있는데 오름차순으로 정렬하고 싶은 경우가 있다.

이와 같이, 기본 비교 로직을 변경할 수 없을 때 기본 비교 로직을 사용하지 않고 자신이 만든 비교 로직을 이용하여 두개의 객체를 비교하기 위해 필요한 것이  IComparer 인터페이스이다.
    
프로그램에서 하나 이상의 정렬 기능을 제공할 때는 어떻게 할까요? 기본이 되는 값으로 비교하는 것은 IComparable 인터페이스에서 약속한 CompareTo에서 정의하면 되겠죠. 그리고 다른 값으로 비교를 원한다면 IComparer 인터페이스 기반의 형식을 정의하세요. Sort 메서드는 IComparer 개체를 입력 인자로 받는 메서드도 지원하고 있습니다.

```c#
interface IComparer<T>
{
    int Compare(T x, T y);
}
    
interface IComparer
{
    int Compare(object x, object y);
}

class AddrComparer : IComparer
{
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
https://smujihoon.tistory.com/178
https://andjjip.tistory.com/153
https://ehpub.co.kr/
https://blog.daum.net/save_us_222/41
