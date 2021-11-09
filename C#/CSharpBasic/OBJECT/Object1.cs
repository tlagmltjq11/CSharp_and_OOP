using System;

// 핵심
// 1. 모든 타입은 Object로 부터 파생 된다.
// 컴파일러가 다음과 같이 바꿔준다. Class Car : System.Object
// -> C#의 모든 타입은 "공통의 특징"을 갖고 있다는 얘기가 된다.

// 2. 즉 모든 것은 객체이다.
// c++, java : primitive 개념 + class 개념
// c# : 모든 것이 객체 형

class Car // class Car : Object로 변경된다.
{

}

class Program
{
    static void Main(string[] args)
    {  
        Car c = new Car();

        string s = 10.ToString(); // 10도 멤버함수가 있다

        c.ToString();

        //Car.Equals(null, null); //Object에게 받은 static 메소드

        Foo(1);
        Foo(3.4);
        Foo("aa");
        Foo(c);
    }

    // 함수 인자로 object를 받으면 모든 객체를 받을 수 있다.
    public static void Foo(object o)
    {
        int n;
        string s = o.ToString();
        Console.WriteLine(s);
    }
}


