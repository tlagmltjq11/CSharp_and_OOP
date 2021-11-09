using System;

// 핵심
// 1. Delegate 선언 형식


//void foo(int arg); // foo는 메소드(함수)

delegate void FUNC(int arg); // FUNC는 메소드의 호출정보를 담는 타입이다.

class Program
{
    static void Main()
    {
        FUNC f = foo;
        f(10);
    }

    public static void foo(int arg)
    {
        Console.WriteLine($"foo : {arg}");
    }
}


