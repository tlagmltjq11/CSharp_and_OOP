using System;
using static System.Console;

// 핵심
// 1. C#에서 가상함수를 재정의하려면 override 키워드를 꼭 사용해야 한다.
// 2. new or void or virtual을 사용하면 부모와 연관없는 자신만의 새로운 메소드를 작성한 것.

class Base
{
    // 가상함수
    public virtual void Foo() { WriteLine("Base foo"); }
}

class Derived : Base
{
    // C#에서 제대로 가상함수를 재정의하는 법
    // C++은 void Foo() 또는 virtual void Foo()를 사용해서 재정의한다.
    //public override void Foo() { WriteLine("Derived foo"); }

    // 아래 3가지 케이스는 부모 클래스의 가상함수를 재정의 한 것이 아니라
    // 자신만의 새로운 메소드를 만든 것이기 때문에 Base Foo가 호출되게 된다.
    //public new void Foo() { WriteLine("Derived foo"); }
    //public void Foo() { WriteLine("Derived foo"); }
    //public virtual void Foo() { WriteLine("Derived foo"); }
}

class Program
{
    static void Main()
    {
        // 가상함수에 의해 참조가아닌 객체를 보고 호출하게 된다.
        // 가상함수테이블 개념을 떠올려보자!!!
        Base b = new Derived();
        b.Foo();  
    }
}
