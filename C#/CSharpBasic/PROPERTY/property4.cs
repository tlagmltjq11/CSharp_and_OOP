using System;

// 핵심
// 1. setter / getter 중 하나를 생략하거나 접근 지정자를 변경 할 수 있다.

// 2. IsAdult와 같이 Backing field가 없는 프로퍼티도 만들어 사용할 수 있다.

class People
{
    private int age = 0; // 지원필드(Backing field)

    public int Age
    {
        get { return age; }
     //   protected set { age = value; }
    }

    // Backing Field가 없는 프로퍼티
    public bool IsAdult
    {
        get { return age > 18; }
    }
}

class Program
{
    static void Main()
    {
        People p = new People();

        //p.Age = 10;
        Console.WriteLine(p.Age);

        if (p.IsAdult) { }
    }
}






