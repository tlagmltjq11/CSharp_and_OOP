using System;

//핵심
// 1. 입력은 무조건 문자열로 받기 때문에 캐스팅해서 사용해야 한다.
// -> Convert.ToInt32(str), int.Parse(str), int.TryParse(str) 등등
// TryParse는 예외처리하기 좋다.

// 2. Read()는 문자 한 개만 입력받는 것.

class Program
{
    public static void Main()
    {
        //    string s = Console.ReadLine();
        //    Console.WriteLine(s);

        // 10 => "10"

        // 정수로 입력받기
        //string s = Console.ReadLine();
        //  int n = Convert.ToInt32(s);
        // Console.WriteLine(n);

        // 더블로 입력받기
        //double d = Convert.ToDouble(s);
        //Console.WriteLine(d);

        // 문자 한 개 입력!
        // abcdef를 입력한다면 c1 = a, c2 = b, s2 = cdef를 갖게 된다.
        int c1 = Console.Read();
        Console.WriteLine((char)c1); //int로 입력받았기 때문에 char 형으로 캐스팅

        int c2 = Console.Read();
        Console.WriteLine((char)c2);

        string s2 = Console.ReadLine();
        Console.WriteLine(s2);
    }
}



