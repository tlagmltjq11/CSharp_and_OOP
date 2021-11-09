using System;

// 핵심
// 1. 메소드에 인자를 전달할 때 "인자 이름"을 사용하여 가독성을 높일 수 있다.
// 인자의 순서를 바꿀 수도 있으며, 일부만 이름을 주어도 된다.

class Program
{
    public static void Main()
    {
        SetRect(10, 20, 30, 40);

        SetRect(x: 10, y: 20, width: 30, height: 40);
        SetRect(y: 20, x: 10, width: 30, height: 40);
        SetRect(10, 20, width: 30, height: 40);

    }

    public static void SetRect(int x,     int y, 
                               int width, int height)
    {
        Console.WriteLine($"{x}, {y}, {width}, {height}");
    }
}