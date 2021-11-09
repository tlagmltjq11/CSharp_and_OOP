using System;

// 핵심
// 1. 기본적으로 Equals를 많이 사용한다.

struct Point
{
    public int x;
    public int y;
    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    // x값만 비교하는 Equals로 재정의
    public override bool Equals(object obj)
    {
        Point pt = (Point)obj;
        return x == pt.x;
    }
}

class Program
{
    static void Main()
    {
        Point p1 = new Point(1, 1);
        Point p2 = p1;
        p2.y = 2; // 이 문장 때문에 false가 나올 것임.

        // 방법 1. == 연산자 사용
        // 값타입인 경우 기본적으로 제공 안됨. - 연산자 재정의 제공가능
        //Console.WriteLine(p1 == p2); 

        // 방법 2. Equals() 가상함수 사용
        // 값타입인 경우 메모리 전체, 즉 실제 값을 비교한다.
        // x, y라는 멤버가있는 것을 모를테니 그냥 메모리 전체를 비교해버리며 값 비교가 되는 것
        Console.WriteLine(p1.Equals(p2)); // true
    }
}




