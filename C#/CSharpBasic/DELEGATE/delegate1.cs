using System;

// 핵심
// 1. 메소드(메소드 호출 정보, 메소드 모양/주소 등)를 저장하는 타입을 델리게이트라고 한다.
// 함수 포인터는 메소드의 주소만 저장하지만 delegate는 파라메터, 타입 등 모든 정보를 보관해
// 유연성이 좀 더 높다고 한다.

delegate void FUNC(int arg);

class Program
{
    static void Main()
    {
        int    n = 10; 
        double d = 3.4;   
        string s = "hello";

        FUNC f = foo;
        f(10); // foo(10)
        f.Invoke(10); // foo(10)
    }

    public static void foo(int arg)
    {
        Console.WriteLine($"foo : {arg}");
    }
}

