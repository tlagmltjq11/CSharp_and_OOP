using System;

// 핵심
// 1. ref 키워드를 사용해서 Call by Reference를 구현할 수 있다.

class Program
{
    // Call by Value
    public static void inc1(int n) // int n = n1 -> 복사되는 것
    {
        ++n;
    }

    // Call by Reference
    public static void inc2(ref int n) // ref int n = ref n2
    {
        ++n;
    }

    public static void Main()
    {
        int n1 = 10;
        inc1(n1);
        Console.WriteLine(n1);

        int n2 = 10;
        inc2(ref n2); // ★ inc2의 매개변수와 합쳐보면 ref int n = ref n2; 가 된다.
        Console.WriteLine(n2);
    }
}