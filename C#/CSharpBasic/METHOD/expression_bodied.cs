using System;

// 핵심
// 1. 간단한 메소드는 람다식으로 구현할 수 있다.

class Program
{
    /*
    public static int Square(int a)
    {
        return a * a;
    }
    */

    // 람다식으로 구현
    public static int Square(int a) => a * a;

    public static void Main()
    {
        Console.WriteLine( Square(3) );
    }
}
