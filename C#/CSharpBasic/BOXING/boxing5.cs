using System;

// 핵심
// 1. Object가 제공하는 가상 Equals는 매개변수가 object로 고정이기 때문에
// -> Generic을 사용할 수 없다. 고로 인터페이스를 구현해서 오버로딩을 사용해야 한다.
// -> 결론은 둘 다 재정의해야 한다는 것이다.


// CompareTo : Icomparable, Icomparable<T> 가 있다.
// Equals    : Object로 부터 상속받게 됩니다. => val 타입에서 재정의 할 때는 Boxing 현상이 있다.
//           : IEquatable<T> : Boxing 없는 Equals를 위한 인터페이스

// 모든 객체에 반드시 필요한 작업이다. : 기반 클래스(Object)에 넣자
// 모든 객체에 반드시 필요한 작업은 아니다 : 필요한 클래스만 만들게 하자... 그런데 함수 이름은 인터페이스로 약속 해 두자


/*
interface IEquatable<T>
{
    bool Equals(T other)
}
*/

struct Point : IEquatable<Point>
{
    private int x;
    private int y;

    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    // Generic 사용
    public bool Equals(Point pt)
    {
        Console.WriteLine("Point");
        return x == pt.x && y == pt.y;
    }

    // 애초에 Object에서 제공하는 가상 Equals 메소드는 매개변수가 object기 때문에
    // Point 형으로 매개변수를 변경할 수 없다.
    // 고로 오버로딩을 사용하는게 맞다. -> IEquatable 인터페이스 구현
    public override bool Equals(object obj)
    {
        Console.WriteLine("object");
        Point pt = (Point)obj;
        return x == pt.x && y == pt.y;
    }
}

class Program
{
    static void Main()
    {
        Point p1 = new Point(1, 1);
        //Point p2 = new Point(1, 1);
        object p2 = new Point(1, 1);
        
        Console.WriteLine(p1.Equals(p2));
    }
}

