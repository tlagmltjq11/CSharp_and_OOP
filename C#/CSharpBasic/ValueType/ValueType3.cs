using System;
using System.Collections;
// 핵심
// 1. val / ref 타입 조사법 GetType()

// 2. reflection을 통해 객체의 타입 정보를 얻어올 수 있다. GetType()

class Program2
{
    public static void Main()
    {
        int[] arr = { 1, 2, 3 };
        Type t = arr.GetType(); // 특정 객체의 타입 정보를 얻어 올 수 있다.
        Console.WriteLine(t.IsValueType); // false

        int n = 1;
        Type t1 = n.GetType();
        Console.WriteLine(t1.IsValueType); // true

        string s = "hello";
        Type t2 = s.GetType();
        Console.WriteLine(t2.IsValueType); // false
    }
}


