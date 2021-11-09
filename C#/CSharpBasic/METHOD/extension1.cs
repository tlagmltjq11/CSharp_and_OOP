using System;

// 핵심
// 확장메소드 : 기존의 클래스를 수정하지 않고 "새로운 메소드를 추가하는 문법"
// 1. 기존 클래스의 수정없이 새로운 기능을 추가하여 사용할 수 있다.

// ★ 2. c++ 배울때와 동일하게 c.Go()를 호출하게 되면 사실은
// -> Go(c);와 같이 자신의 객체를 인자로 넘겨주게 된다.
// -> 고로 public void Go(this car); 와 같이 생각해야 한다.

// 3. Linq 에서 해당 확장메소드를 사용한다.


// 기존 클래스는 수정되지 않는다.
class Car
{
    private int speed;
    public void Go() { Console.WriteLine("Go"); }

}

// Car 클래스에 메소드를 추가하기 위한 static 클래스
static class CarExtension
{
    //확장메소드 작성 시 아래와 같은 문법을 따라야 한다. static, this..
    public static void Stop(this Car c)
    {
    //    c.speed = 10; // error : private 이기 때문
    //    c.SetSpeed(10); // 게터/세터를 만들어야 접근 가능할 것임.
        Console.WriteLine("Stop");
    }

    public static void Foo(this Car c, int a, double d)
    {
        Console.WriteLine($"Foo {a} {d}");
    }
}

static class stringExtension
{
    public static void Stop(this string c)
    {
        Console.WriteLine("Stop");
    }

    // 첫번째 매개변수는 자동으로 객체가 넘어오기 때문에 a, d만 직접 넘겨주면 된다.
    public static void Foo(this string c, int a, double d)
    {
        Console.WriteLine($"Foo {a} {d}");
    }
}

class Program
{
    public static void Main()
    {
        Car c = new Car();        
        c.Go(); // Go(c)
        c.Stop(); // CarExtension.Stop(c)
        c.Foo(3, 4.5);

        string s = "aaa";
        s.Foo(1, 1.2);
    }

}