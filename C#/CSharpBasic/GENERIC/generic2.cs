using System;

// 핵심
// 1. 메소드가 새로 생성된다는 점 주의

// 2. 같은 타입을 받겠다고 해놓고 서로 다른 타입을 준다면
// 컴파일러가 최선의 경우로 정해준다.
// 하지만 아예 결정할 수 없는 경우에는 error를 뿜는다.

class Program
{
    public static T Foo1<T>(T a) 
    {
        Type t = a.GetType();
        Console.WriteLine(t.FullName);
        return a;
    }

    public static T Foo2<T>(T a, T b)
    {
        // a가 가리키는 실제 객체의 타입..
        Type t = a.GetType(); // int32
        Console.WriteLine(t.FullName);

        Type t2 = typeof(T); // object
        Console.WriteLine(t2.FullName);
        return a;
    }

    static void Main()
    {
        Foo1<int>(3); // 이 순간 int로 바뀐 메소드가 생성된다.
        Foo1<double>(3.4); // 이 순간 double로 바뀐 메소드가 생성된다.
        Foo1(3); // 타입 생략 가능

        Foo2(1, 2);
        Foo2(1, 3.4); // 서로 다른 타입일때 C#에서는 더블로 처리해줌. c++은 에러
        //Foo2(1, "AAA"); // error : int로 해도 string으로 해도 모두 받을 수 없다.
        Foo2<object>(1, "AAA"); // ok
    }
}
