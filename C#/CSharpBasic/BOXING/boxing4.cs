using System;

// 핵심
// 1. Boxing / UnBoxing을 최소화하기 위해서 Generic을 사용하자.
// -> IComparable vs IComparable<T>
// 모든 경우의 수를 대응하기 위해 둘 다 구현하는 경우가 많다.

/*
// C# 1.0
interface IComparable
{
    int CompareTo(object other);
}
*/

/*
// C# 2.0 : generic interface
interface IComparable<T>
{
    int CompareTo(T other);
}*/

struct Point : IComparable<Point>, IComparable
{
    private int x;
    private int y;

    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    // Generic 사용한 버전
    public int CompareTo(Point pt)
    {
        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }

    public int CompareTo(object other) // Struct가 넘어온다면 Boxing이 일어날 수 있다 !!!
    {
        //Point pt = other as Point; //Point는 nullable이 아니기 때문에 에러를 뿜는다.
        Point pt = (Point)other; // UnBoxing !!!

        if (x > pt.x) return 1;
        else if (x == pt.x) return 0;
        return -1;
    }  
}

class Program
{
    static void Main()
    {
        string s;
        Point p1 = new Point(1, 1);
        Point p2 = new Point(2, 2);

        // struct를 보냈기 때문에 Boxing되면서 Heap에 복사본 1개
        // UnBoxing 되면서 Point pt; 라는 복사본 1개
        // 총 2개가 생성되며 연산속도 자체에서도 성능의 이슈가 생긴다.
        Console.WriteLine(p1.CompareTo(p2)); // Point형으로 보냈으니 Generic 버전의 우선순위가 높아져 해당 메소드가 호출된다.
    }
}

