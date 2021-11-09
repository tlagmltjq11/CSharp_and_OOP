using System;

class Car
{
}

class Program
{
    public static void Main()
    {
        Car c = new Car();

        Type t = c.GetType();

        t.ToString();

        Console.WriteLine(t.FullName);
        Console.WriteLine(t.BaseType.FullName);



        int n = 10;

        // 컴파일 시간에 결정..
        var n2 = n;

        // 항상 언어를 학습할때는 "변수의 타입을 조사"하는 방법을 알아두면 좋다.
        Type t1 = n2.GetType(); // 변수명으로 타입정보 얻기
        Type t2 = typeof(int); // 타입명으로 타입정보 얻기
        Console.WriteLine(t1.Name);
    }
}