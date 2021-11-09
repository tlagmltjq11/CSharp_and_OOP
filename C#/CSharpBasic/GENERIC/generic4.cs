using System;

// 핵심
// 1. Generic 제약조건
// where T : class - ref 타입이어야만 한다. (맨 앞에 써야한다.)
// where T : struct - val 타입이어야만 한다.
// where T : new() - 디폴트 생성자가 있어야 한다. (맨 뒤에 써야한다.)
// where T : 인터페이스이름 - 해당 인터페이스를 구현한 타입만.
// where T : 클래스이름 : 특정 클래스로 부터 파생된 타입만.

class Program
{
    /*
    public static int Max(int a, int b)
    {
        return a.CompareTo(b) < 0 ? b : a;
    }

    public static string Max(string a, string b)
    {
        return a.CompareTo(b) < 0 ? b : a;
    }
    */


    // 1. object
    // 값 타입의 경우 Boxing / UnBoxing이 발생한다.
    /*
    public static object Max(object a, object b)
    {
        // obejct 참조형으로 가리키면 CompareTo를 사용할 수 없기 때문에
        // 해당 인터페이스형으로 캐스팅 후 사용한다.
        IComparable c1 = a as IComparable;
        IComparable c2 = b as IComparable;

        return c1.CompareTo(c2) < 0 ? b : a;
    }
    */


    // 2. IComparable
    // 모든 인터페이스 : reference type -> 즉 Boxing / UnBoxing 현상이 일어난다.
    /*
    public static object Max(IComparable a, IComparable b)
    {
        return a.CompareTo(b) < 0 ? b : a;
    }
    */


    // 3. generic
    // 임의의 타입 T에 CompareTo가 있다고 보장할 수 없어서 에러가 뜬다.
    // Equals는 오브젝트의 기능이기에 가능하다.
    // -> Generic 제약을 사용하자 !!!
    // C++20에서는 concept이라고 부르는 개념.
    public static T Max<T>(T a, T b) where T : IComparable, new()
    {
        // 기본적으로 object로 할수 있는 연산만 가능
        // a.Equals(b); // ok.. object 멤버
        return a.CompareTo(b) < 0 ? b : a;
    }


    static void Main()
    {
        Console.WriteLine(Max(10, 20));
        Console.WriteLine(Max("A", "B"));
        //Console.WriteLine(Max(new Car(), new Car())); // IComparable을 구현하지 않아서 보낼 수 없다.

        int n = Max(10, 20);
    }
}

class Car { }


