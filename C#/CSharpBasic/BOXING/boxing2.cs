using System;

// 핵심
// 객체의 크기를 비교하는 방법
// 1. 관계연산자 (>, < 등) : 수치 관련 타입만 가능하다.
// -> 물론 연산자 재정의로 제공할 수는 있다.

// 2. CompareTo() 메소드 : 대부분의 타입을 지원한다.

class Program
{
    static void Main()
    {
        Console.WriteLine(10 < 20); // true
        
        Console.WriteLine(10.CompareTo(20)); // -1 10이 더 작으므로
        Console.WriteLine(10.CompareTo(10)); // 0
        Console.WriteLine(10.CompareTo(5));  // 1

        string s1 = "AAA";
        string s2 = "BBB";

        //Console.WriteLine(s1 < s2); // string 타입에는 관계연산자를 사용할 수 없다.
        // 아스키코드로 비교할테니 s1이 더 작은 경우가 된다.
        Console.WriteLine(s1.CompareTo(s2)); // -1
    }
}
