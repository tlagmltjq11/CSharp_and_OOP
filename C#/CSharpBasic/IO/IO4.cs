using System;

//핵심
// 1. Read()나 ReadLine()은 입력 버퍼에서 입력받기 때문에 무조건 엔터를 입력해야 한다.
// -> 입력 버퍼가 아닌 키보드로 부터 직접 입력받으려면, 즉 엔터키를 누르지 않아도
// -> 곧바로 입력처리를 하려면 Conosole.ReadKey(); 를 사용하면 된다.

// 2. ReadKey()는 ConsoleKeyInfo 구조체를 반환한다!
// -> 입력받은 key 확인 법 cki.KeyChar

class Program
{
    public static void Main()
    {
        int n = Console.Read();
        Console.WriteLine(n);

        //ConsoleKeyInfo cki = Console.ReadKey(); // 키를 누르자마자 곧바로 입력
        ConsoleKeyInfo cki = Console.ReadKey(true); // true인자는 no echo 옵션이다 즉 사용자의 입력을 출력하는것을 막는것이다.


        Console.WriteLine(cki.KeyChar);
    
    }
}



