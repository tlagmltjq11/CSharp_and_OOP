using System;

//핵심
// 1. 접근 지정자는 모든 멤버에 개별적으로 표시한다.
// ex) public int data1;

// 2. 상속은 : 연산자를 사용한다.

// 3. 객체 생성시에는 ()가 있어야 한다.
// c++은 디폴트 생성자로 생성할 때 Derived* p = new Derived; 처럼 사용함.

// 4. 부모의 멤버를 숨기고 싶다면 new 키워드를 사용해라!

class Base
{
    public int data1 = 10;
    public int data2 = 10;
}

class Derived : Base
{
    //public int data1 = 20;
    //부모에 존재하는 멤버와 동일한 이름으로 멤버를 생성할 수 있다.
    // 즉 부모의 멤버를 숨기게 되는 것이므로 컴파일러가 경고를 띄워준다.
    // 이때 컴파일러는 개발자의 실수라고 생각하고 경고를 주는것이기 때문에
    // 이러한 경고를 숨기고, 즉 내 의도라는것을 명백히하려면 new 키워드를 사용하면 된다.

    public new int data1 = 20;
}

class Program
{
    static void Main()
    {
        Derived d = new Derived();

        Console.WriteLine(d.data1); // 20
        Console.WriteLine(((Base)d).data1); // 10

    }
}
