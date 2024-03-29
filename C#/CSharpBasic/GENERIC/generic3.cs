﻿using System;

// 핵심
// 1. 하나의 메소드로 묶으려면 구현부가 똑같아야 한다.
// -> int도 CompareTo로 비교가 가능하니 묶어보자.

class Program
{
    public static int Max(int a, int b)
    {
        // return a < b ? b : a;
        return a.CompareTo(b) < 0 ? b : a;
    }

    public static string Max(string a, string b)
    {
        return a.CompareTo(b) < 0 ? b : a;
    }

    static void Main()
    {
        Console.WriteLine( Max(10, 20) );
        Console.WriteLine( Max("A", "B"));
        //Console.WriteLine(Max(1.2, 2.1));
    }
}
