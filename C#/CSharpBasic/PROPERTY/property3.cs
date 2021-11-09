using System;

// 핵심
// 1. 컴파일러는 프로퍼티를 get_Age()와 같은 메소드로 변환해준다.

class People
{
    private int age = 0;

    public int Age
    {
        get { return age; }
        set { age = value; }
    }
    
    // 실제 컴파일러가 아래와 동일하게 메소드명을 짓고 만들기 때문에
    // error가 난다.
    //public int get_Age() { return age; }
}

class Program
{
    static void Main()
    {
        People p = new People();
        p.Age = 10;
        int n2 = p.Age;
    }
}






