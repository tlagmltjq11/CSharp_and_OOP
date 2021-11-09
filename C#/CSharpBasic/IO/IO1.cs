using System;
using static System.Console; //System 네임스페이스 내부에있는 Console Static 메소드를 사용하겠다는 의미

//핵심
// 1. using System;
// 2. using static System.Console;
// 3. System.Console 클래스 : 표준 입출력 함수를 제공하는 "static 클래스"

class Program
{
    static void Main(string[] args)
    {
        System.Console.WriteLine("Hello, C#");

        Console.WriteLine("Hello, C#");

        WriteLine("Hello, C#");
    }
}

