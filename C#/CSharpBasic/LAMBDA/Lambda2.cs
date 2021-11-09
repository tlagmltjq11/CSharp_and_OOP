using System;

// 핵심
// 1. 람다식을 통한 여러가지 방식의 익명메소드 생성 법

class Program
{
    public static int Add(int a, int b) { return a + b; }

    static void Main()
    {
        Func<int, int, int> f1 = Add;

        Func<int, int, int> f2 = (int a, int b) => { return a + b; };

        Func<int, int, int> f3 = ( a,  b) => { return a + b; };

        Func<int, int, int> f4 = (a, b) => a + b;

        Func<int, int> f5 = (a) => a + a;

        Func<int, int> f6 = a => a + a; // Linq가 즐겨 사용하는 모양

    }

}
