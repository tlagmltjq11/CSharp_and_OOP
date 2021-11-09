using System;

// 핵심
// 1. nullable 사용법
// 주의할 점 ★ : int끼리 연산하는데 한쪽이 null이라면 결과는 무조건 null이다.

class Program
{
    public static void Main()
    {
        int? n1 = null;// 10;
        int  a1 = 20;

        //n1 = a1; // int? = int   ok : nullable이 더 큰 개념이기 때문에 담을 수 있다.
        //a1 = n1; // int = int?   error : int에는 bool이 없기 때문에 담을 수 없다.

        //a1 = (int)n1; // int = int?   // bool 제외하고 int값만 넣기위해 캐스팅하는 과정

        Console.WriteLine(a1);

        int? n2 = null;// 10;
        int? n3 = 20;
        int? n4 = n2 + n3; // 한쪽이 null이라면 최종 결과는 당연히 null 이다.

        Console.WriteLine(n4==null);
        Console.WriteLine(n4);

    }
}