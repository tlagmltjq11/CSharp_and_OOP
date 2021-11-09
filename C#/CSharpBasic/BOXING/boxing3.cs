using System;

// 핵심
// 1. 사용자 정의 타입에 대해서 비교연산자를 적용하고 싶은 경우
// -> CompareTo를 정의하면 되는데 IComparable 인터페이스를 구현하는 방식으로 제공하면 된다.
// -> 일관성 제공 + 다형성 사용 가능(다운캐스팅)

// 2. C#에서는 대부분의 메소드를 구현할 때 인터페이스 구현을 기본으로 한다.

//void foo(IComparable c) { } //다형성 예제

/*
// 비교 하는 메소드의 이름을 약속하자.
interface IComparable
{
    int CompareTo(object other);
}
*/

// 모든 크기의 비교가 가능한 객체는 IComparable 인터페이스를 구현해야 한다.
class Point  : IComparable
{
    private int x;
    private int y;

    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }  

    // Object 형식으로 매개변수를 받고 있다.
    // 만약 Point가 struct 즉 값타입이었다면 Boxing이 일어나게 되는 것이다 !
    public int CompareTo(object other)
    {
        Point pt = other as Point;

        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }
}

class Program
{
    static void Main()
    {
        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);

        Console.WriteLine(p1.CompareTo(p2));
    }
}

