using System;

// 핵심
// 1. class -> struct , struct -> class 로의 형변환을 하려면 연산자 재정의를 사용해야 한다.

class Point
{
    private int x;
    private int y;

    public Point(int xPos, int yPos)
    {
        x = xPos;
        y = yPos;
    }

    public override string ToString()
    {
        return string.Format($"{x}, {y}");
    }

    // 연산자 재정의
    // Point를 인자로 받아서 int를 꺼내어 주겠다는 의미.
    // explicit는 명시적이라는 의미로 명시적 형변환을 의미한다.
    // 실무에서 많이 쓰이는 방식은 아니다.
    public static explicit operator int(Point pt)
    {
        return pt.x;
    }

    // int를 인자로 받아서 Point를 만들어 반환하겠다는 의미.
    public static explicit operator Point(int n)
    {
        return new Point(n, n);
    }
}

class Program
{
    static void Main()
    {
        double d = 3.4;
        //int n1 = d; // error : 데이터의 손실이 있으므로    
        int n1 = (int)d; // ok


        Point pt = new Point(1, 2);

        //int n2 = pt; // Point => int
        int n2 = (int)pt; // Point => int.. ok : 위에서 명시적 형변환에 대한 연산자 재정의를 통해 가능하다
        Console.WriteLine(n2);

        //---------------------
        Point pt2 = (Point)n2; // int => Point
        Console.WriteLine(pt2); // pt2.ToString()을 출력하는것과 같은 표현식


       // Point pt2 = n2 as Point; // error : as 연산자 사용시 사용자가 만든 변환연산자를 호출 할 수 없다.
    }
}






