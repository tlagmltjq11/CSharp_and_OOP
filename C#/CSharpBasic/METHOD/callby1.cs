using System;

// 핵심
// 1. ref 키워드를 통해서 val 타입의 객체도  참조를 이용해 가리키게 할 수 있다.
// 거대한 val 타입의 구조체를 복사하지않고 참조하는 방식으로 성능을 높일 수 있다.

class Program
{
    public static void Main()
    {
        int n1 = 10;
        int n2 = n1;

        n2 = 20;

        Console.WriteLine($"{n1}, {n2}"); // 10, 20

        int n3 = 10;
        ref int n4 = ref n3; // val 타입이라 하더라도 ref 변수처럼 사용할 수 있게 된다.
        // ref int n4 -> int 형 변수를 가리키는 변수를 만들겠다.
        // n4 = ref n3; // n4가 n3를 가리키게 한다.
        // 거대한 사이즈의 val 타입 객체를 복사하지않고 참조하게끔 할 수 있기 때문에
        // 유용하게 사용될 수 있다.
            
        n4 = 20;

        Console.WriteLine($"{n3}, {n4}"); // 20, 20
    }
}