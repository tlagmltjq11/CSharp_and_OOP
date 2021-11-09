using System;

// 핵심
// 1. 객체의 동등성을 조사하는 방법
//  == 연산자, Equals() 가상메소드 사용

//              참조타입                        값타입
// ==           기본적으로 주소 비교            기본 제공 안됨
//              사용자가 연산자 재정의 가능     사용자가 재정의 가능
// Equal        기본적으로 주소 비교            기본 값 비교
//              가상함수 재정의 가능            가상함수 재정의 가능

// 2. C#도 연산자 재정의가 가능하다.

// 3. 권장사항은 Equals()만 재정의해서 사용하는 것이다.

class Point
{
    private int x = 0;
    private int y = 0;

    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    // 본인의 입맛에 맞게 Equals를 재정의하여 사용할 수 있다.
    public override bool Equals(object obj)
    {
        Point pt = (Point)obj; // as 캐스팅을 사용하는 것이 더 좋다.

        return x == pt.x && y == pt.y;
    }

    // C#도 연산자 재정의가 가능하다. (오버로딩!★)
    // == 연산자 재정의 -> != 도 꼭 함께 재정의해줘야 한다.
    public static bool operator ==(Point p1, Point p2)
    {
        return p1.x == p2.x && p1.y == p2.y;
    }
    public static bool operator !=(Point p1, Point p2)
    {
        return p1.x != p2.x || p1.y != p2.y;
    }
}

class Program
{
    static void Main()
    {
        //Point p1 = new Point(1, 1);
        //Point p2 = p1;
        //Point p3 = new Point(1, 1);

        object p1 = new Point(1, 1);
        object p2 = p1;
        object p3 = new Point(1, 1);

        // 방법 1. == 연산자 사용
        // 기본 동작 : 참조(주소)가 동일한가 ?
        Console.WriteLine(p1 == p2); // true

        // Object 참조로 호출한 것이기 때문에 오버로딩된 즉 재정의된 연산자가 불리지 않는 것이다.
        // Point 참조로 호출했다면 True가 출력된다.
        Console.WriteLine(p1 == p3); // false


        // 방법 2. Equals() 가상함수 사용
        // 기본 동작 : 참조가 동일 한가 ?
        Console.WriteLine(p1.Equals(p2)); // true
        Console.WriteLine(p1.Equals(p3)); // true
    }
}




