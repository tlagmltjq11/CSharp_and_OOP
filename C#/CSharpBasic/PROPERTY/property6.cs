using System;

// 핵심
// 1. 객체 생성 시 프로퍼티 초기화 표기법 알아두기

// 2. 프로퍼티를 갖는 무명 타입 (Linq에서 많이 사용된다. 다른곳에선 딱히)

class Point
{
    public int X { get; set; } = 0; // 디폴트 방식
    public int Y { get; set; } = 0;
}

class Program
{
    static void Main()
    {
        // 프로퍼티 초기화 방식들
        Point p1 = new Point();
        Point p2 = new Point() { X = 10, Y = 20 };
        Point p3 = new Point   { X = 10, Y = 20 };
        Point p4 = new Point { Y = 20 };


        // 무명 타입
        // Name, Age라는 읽기전용 프로퍼티를 갖는 무명 타입을 생성한다.
        var p = new { Name = "kim", Age = 20 };

        Console.WriteLine(p.Name); // "kim"
        //p.Name = "lee"; // error : 읽기 전용이다.

        Type t = p.GetType();
        Console.WriteLine(t.FullName); //무명 타입명 출력해봄
    }
}






