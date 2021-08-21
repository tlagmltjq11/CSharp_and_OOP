## IComparable & IComparer
IComarable 인터페이스와 IComparer 인터페이스는 개체의 값 비교(선후 관계)를 제공하기 위해 정의되었다.<br>
C#의 컬렉션은 대부분 Sort 메서드를 제공하는데 IComparable 인터페이스 기반의 요소를 보관하고 있을 때<br>
정상적으로 동작하고 그렇지 않으면 예외를 발생한다.<br>
-> 즉 정렬할 때 어떠한 기본방식으로 개체의 값을 비교할 것인지 IComparable 인터페이스를 구현하여 방식을 제공해야 한다는 것<br>

그리고 IComparer 개체를 입력 인자로 받는 Sort 메서드가 중복 정의되어 있는데<br>
정렬하는 과정에서 입력 인자로 받은 IComparer 개체를 이용한다.<br>
-> 기본 방식으로 정렬하는 것이 아니라 새로운 기준을 기반으로 정렬하고 싶다면 IComparer를 구현한 클래스를 넘겨주면 되는 것.<br>

IComparable<T>를 이용하여 타입의 기본적인 선후 관계를 정의하고 IComparer<T>를 이용하여 기본적인 선후 관계 이외에 추가적인 선후 관계를 정의할 수 있다.



C#의 System에 정의되어 있는 기본 형식들은 ICompable 인터페이스를 기반으로 정의되어 있어서<br>
기본 형식을 보관한 컬렉션은 Sort 메서드를 이용하여 정렬할 수 있다.<br>
<br>
    
.NET 환경이 제공하는 최신 API는 IComparable<T>를 사용하지만 일부 오래된 API들은 여전히 IComparable를 구현하기 때문에 IComparable<T>를 구현할 때는 IComparable를 같이 구현해줘야 한다.    
    

```c#
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

프로그램에서 하나 이상의 정렬 기능을 제공할 때는 어떻게 할까요? 기본이 되는 값으로 비교하는 것은 IComparable 인터페이스에서 약속한 CompareTo에서 정의하면 되겠죠. 그리고 다른 값으로 비교를 원한다면 IComparer 인터페이스 기반의 형식을 정의하세요. Sort 메서드는 IComparer 개체를 입력 인자로 받는 메서드도 지원하고 있습니다.

```c#
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

https://ehpub.co.kr/c-8-2-5-icomparable-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4%EC%99%80-icomparer-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4/
