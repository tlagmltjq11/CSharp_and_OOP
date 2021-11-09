using System;

// 핵심
// 1. out 키워드 : 메소드로 부터 하나의 반환값 이외에도 추가적인 값을 받아오고 싶다면
// out 키워드로 변수를 넘겨주어 받아올 수 있다.
// 이때 위 과정을 ref로도 구현할 수 있지만, 값을 "받아오기만" 할 것이라면
// out을 사용하는것이 권장사항이다.

// ref vs out : 둘의 추가적인 차이점은 ref는 메소드 내에서 read/write가 모두 가능한 반면
// out은 메소드내에서 write만 가능하다.
// 그렇기 때문에 out은 초기화하지 않아도 매개변수로 보낼 수 있으며,
// ref는 read할 가능성도 있기 때문에, 초기화한 변수만 보낼 수 있다.

class Program
{
    //메소드로 부터 2개의 결과 값을 반환 받고 싶다.
    public static int prev_next_number1(int n, ref int r)
    {
        int a = r; // ok : ref는 write/read 모두 가능하다.
        r = n + 1;
        return n - 1;
    }

    public static int prev_next_number2(int n, out int r)
    {
        int a = r; // error : write만 해달라는게 out 키워드인데 read를 했기 때문에 에러가 발생된다.
        r = n + 1;
        return n - 1;
    }

    public static void Main()
    {
        int n1 = 10;
        int result2;// = 0; 메소드 내에서 write만 할테니 초기화하지 않아도 된다.

        //int result1 = prev_next_number1(n1, ref result2);
        int result1 = prev_next_number2(n1, out result2);

        Console.WriteLine($"{result1}, {result2}");
    }
}