using System;

// 핵심
// 1. ToString()은 객체를 문자열로 변경하는 메소드
// -> 기본 구현은 객체의 "타입 이름을 문자열로 반환한다." ex) Point 출력
// -> 일반적으로 "객체의 상태를 나타내도록 재정의해서 사용한다"

// 2. 사용자 정의 타입을 설계 할 때 Object의 3개의 가상 메소드를 재정의하는게 일반적이다.

class Point
{
    private int xPos = 0;
    private int yPos = 0;

    public Point(int x, int y) { xPos = x; yPos = y; }

    // ToString() 입맛에 맞게 재정의해서 사용
    public override string ToString()
    {
        return string.Format($"{xPos}, {yPos}");
    }
}

class Program
{
    public static void Main()
    {
        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);

        Console.WriteLine( p1.ToString() );
        Console.WriteLine( p2.ToString() );
    }
}
