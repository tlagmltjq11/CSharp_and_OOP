using System;

// 핵심
// 1. public은 "외부의 잘못된 사용"으로 부터 방어할 수 없다.
// 2. 필드 접근 시 "추가적인 기능(스레드 동기화, 로깅 등)을 수행" 할 수 없다.
// -> 필드를 직접 접근하면 예외 체크를 할 수 없는 것을 의미하기도 한다.

// 이런식으로 코딩하는 것을 "데이터 캡슐화" 라고 한다.
// -> 너무 많이 사용하니까 "c#에서 Property"를 제공한다.
// 프로퍼티란 게터/세터를 자동으로 생성하는 문법이다.

class People
{
    private int age = 0;

    public int  get_age() { return age; }
    public void set_age(int value)
    {
        if ( value <= 0 )
        {
            // 예외 전달
        }
        else
            age = value;
    }
}

class Program
{
    static void Main()
    {
        People p = new People();

        //p.age = 10;
        //p.age = -5;

        p.set_age(10);
        p.set_age(-5);
    }
}





