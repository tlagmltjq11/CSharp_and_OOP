using System;

// 핵심
// 선택적 매개변수
// 1. 매개변수에 디폴트값을 지정하여 선택적으로 매개변수를 보낼 수 있다.

class Program
{
    // 만약 인자를 안준다면 정해준 디폴트값으로 사용하겠다는 의미.
    public static void foo(int a = 0, int b = 0, int c = 0)
    {
        Console.WriteLine($"{a}, {b}, {c}");
    }

    public static void Main()
    {
        foo(1, 2, 3); // 3개 모두 보내는 경우
        foo(1, 2); // a, b만 보내는 경우 c = 0 이 된다.
        foo(1);
        foo();
        foo(b: 10);
        foo(c: 20);
    }

}