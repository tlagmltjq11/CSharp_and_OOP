using System;

//핵심
// 1. 가상이 아닌 메소드를 재정의 할 때는 컴파일러 경고를 막기위해
// new 키워드를 사용해야 한다.

// 2. C# 역시 C++ 처럼 가상인 함수, 가상이 아닌 함수로 구별된다.

class Base
{
    public void Foo() { Console.WriteLine("Base foo"); }
}

class Derived : Base
{
    public new void2 Foo() { Console.WriteLine("Derived foo"); }
}

class Program
{
    static void Main()
    {
        Base b1 = new Base();        
        b1.Foo();  // Base Foo

        Derived d1 = new Derived(); 
        d1.Foo();  // Derived Foo

        Base b2 = new Derived();
        b2.Foo();  // Base Foo ? Derived Foo(java)
                   // Base Foo(C#, C++)

        //Base Foo()는 가상함수가 아니기 때문에 Base형 b2에 Derived() 객체를 대입했다고 해도
        //Derived 객체의 Foo()가 불리지 않는다.
        //하지만 자바는 모든 함수가 가상이기 때문에 Derived의 Foo()가 불린다!!
        //즉 자바는 참조가아닌 객체를보고 호출한다는 의미다.
    }
}
