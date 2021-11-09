using System;

// 핵심
// 1. 매개변수로 Delegate를 넘겨주어야 할 때
// -> 람다식을 이용한 "익명 메소드"를 넘겨줄 수 있다.

class Program
{
    public static void foo(Func<int, int, int> f)
    {
        int s = f(1, 2);
        Console.WriteLine(s);
    }
    static void Main(string[] args)
    {
        foo( Add );

        foo( (int a, int b) => { return a - b; }   );

    }
    public static int Add(int a, int b) { return a + b; }
    
}
