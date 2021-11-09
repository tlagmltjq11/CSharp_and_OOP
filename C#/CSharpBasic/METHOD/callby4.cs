using System;

// 핵심
// 1. val 타입이 아닌 ref 타입을 ref 키워드로 넘겨주는 경우
// -> 참조 타입을 "값"으로 전달하면 객체의 상태를 변경할 수 있지만
// 새로운 객체를 담아 올 수는 없다.
// -> 하지만 "ref"로 즉 참조를 전달하면 객체의 상태를 변경할 수 있고
// 새로운 객체도 담아 올 수 있다. (2중 포인터의 개념이며 그림을 그려보면 쉽게 이해된다.)

class Point
{
    public int x = 0;
    public int y = 0;

    public Point(int a, int b) { x = a; y = b; }
}

class Program
{
    public static void f1(Point p) // Point p = p1
    {
        p.x = 2;
        p = new Point(5, 5); // p1에는 영향이 없다.
    }

    public static void Main()
    {
        Point p1 = new Point(1, 1);

        // f1(p1); // p1은 참조타입이기 때문에 ref를 사용하지 않고 보내도 CBR가 된다.
        f2(ref p1);

        Console.WriteLine(p1.x); // ref X : 2, ref O : 5
    }

    public static void f2(ref Point p) // ref Point p = refp1
    {
        // 참조타입의 참조를 받았기 때문에 p가 p1을 가리키고 있다고 이해하면 된다.
        p.x = 2;
        p = new Point(5, 5);
    }

}