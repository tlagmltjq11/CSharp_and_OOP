using System;

// 핵심
// 1. 익명 메소드

delegate int FUNC(int arg1, int arg2);

class Program
{
    public static int Add(int a, int b) { return a + b; }

    public static void Main()
    {
        //FUNC f = Add;

        // 익명 메소드 생성 법
        FUNC f = delegate (int a, int b) { return a + b; };

        Console.WriteLine(f(1, 2));

        Foo(Add);
        Foo(delegate (int a, int b) { return a - b; });
    }


    public static void Foo(FUNC f) 
    {
        Console.WriteLine(f(1, 2));
    }
}


