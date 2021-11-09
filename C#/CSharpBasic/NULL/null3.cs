using System;

// 핵심
// 1. ?. 연산자 (elvis 오퍼레이터) : 좌변이 null인 경우 좌변은 수행하지 않고 전체 결과를 null로 반환

// 2. ?[ 연산자 : 좌변의 배열객체가 null이라면 우변을 실행하지 않고 전체 결과를 null로 반환

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
        Car c = CreateCar(300);

        //if ( c != null )
        //    c.Go();

        // 위 코드를 아래와 같이 단축 표기할 수 있다.
        c?.Go(); // ?. 좌변의 객체가 null이 아닌 경우에만 뒤를 수행

        //int n = c.color;  // -> c가 null이면 에러!

        //int n = c?.color;  // error -> n이 nullable이 아니기 때문
        
        int? n = c?.color; // ok

        //------------------
        int[] arr = null; // { 1, 2, 3 };

        //int n2 = arr[0]; // 배열이 null인 경우도 프로그램이 죽을 수 있다.

        int? n2 = arr?[0]; // ?[ 연산자
    }
}
