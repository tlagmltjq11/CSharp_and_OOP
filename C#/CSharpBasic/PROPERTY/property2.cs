using System;

// 핵심
// 1. 프로퍼티는 ()를 붙이지않아 메소드지만 필드처럼 사용이 가능하다.

class People
{
    private int age = 0;

    public int Age // ()를 붙이지않아 필드처럼 사용이 가능하다.
    {
        get { return age; } 
        set { age = value; }
    }

    // 컴파일러가 위 코드를 아래와 같이 만들어 주는 것이다.
    //public int get_age() { return age; }
    //public void set_age(int value) { age = value;  }
}

class Program
{
    static void Main()
    {
        People p = new People();

        p.Age = 10; // set {}
        int n2 = p.Age; // get{}

        p.set_age(10);
        int n = p.get_age();
    }
}





