using System;

// 핵심
// 1. ?? 연산자 (null 접합 연산자) : 좌변이 null인 경우 우변 값 반환

class Car
{
    public int color = 10;
    public void Go() { Console.WriteLine("Go"); }
}

class Program
{
    public static Car CreateCar(int speed)
    {
        if (speed > 200) return null;
        return new Car();
    }
    public static void Main()
    {
        Car c = CreateCar(300) ?? new Car();


        int? n1 = 10; // null;// 10;

        //int n2 = n1; // error

        //int n2 = (int)n1; // ★ -> 만약 n1이 null이었다면 error를 뿜었을 것이다.

        int n2 = n1 ?? 0; // ★ n1이 null이 아니면 n1의 int 값을 꺼내어 준다.

        Console.WriteLine(n2);

    }
}
