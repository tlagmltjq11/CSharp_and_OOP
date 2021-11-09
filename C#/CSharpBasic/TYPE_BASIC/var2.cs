using System;

// 핵심
// 1. C#에서 "모든 것은 객체" 이다.
// 10, 3.4, "aa"도 모두 객체이다. (멤버를 갖는다.)
// c++과의 큰 차이점이기도 하다.

class Program
{
    public static void Main()
    {
        // int : 타입
        // 10  : int 타입의 객체
        10.ToString();
        //int.Parse(); // static 메소드

        //3.4.CompareTo
        int n = 10;

        // string == String
        string s1 = "AAA";
        String s2 = "AAA";
        System.String s3 = "AAA";

        // int == Int32
        System.Int32 n3 = 10;
        Int32 n4 = 10;
    }
}
