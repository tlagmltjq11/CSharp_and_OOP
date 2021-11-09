using System;

// 핵심
// 1. c#에서는 초기화 되지 않은 변수는 사용할 수 없다. (c언어는 쓰레기값)

// 2. var는 우변의 표현식을 보고 좌변의 타입을 결정한다. (c++에서는 auto)

class Program
{
    public static void Main()
    {
        
        int n1; // = 10;
        n1 = 20;
        Console.WriteLine(n1);

        double n2 = 10;
        var n3 = n2; // 우변의 표현식을 보고 좌변의 타입을 결정한다.
    }
}