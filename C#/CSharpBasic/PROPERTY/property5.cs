using System;

// 핵심
// 1. 자동 프로퍼티를 사용할 수도 있다.
// -> Backing Field, set, get의 구현을 자동으로 제공한다.

// 2. 그렇다면 일반 public 변수 vs 자동 프로퍼티는 무슨 차이인가?
// -> 사실 현재 둘은 똑같은 코드라고 볼 수 있다.
// 하지만 만약 추후에 set / get에 대해서 특정 기능을 추가하려고 한다면
// public 변수를 쓴 코드는 모든 사용처에서 코드를 변경해주어야 한다.
// 하지만 애초부터 같은 코드지만 자동 프로퍼티를 사용했다면
// 해당 프로퍼티 내 set / get만 바꿔주게되면 모든 사용처의 코드가 바뀔 필요가 없다.
// 즉 추후 유지보수에 유리한 장점을 갖고 있다.
// ★ 사이드 이펙트가 없어지는 -> 진정한 캡슐화!

class People
{
    private int age = 0;
    public int Age
    {
        get { return age; }
        set { age = value; }
    }

    // 위 코드는 아래 한줄의 코드로 대체할 수 있다.
    //public int Age { get; set; } = 0; // 자동 속성

    // public int age = 0;
    // public int Age { };
}

class Program
{
    static void Main()
    {
        People p = new People();

        //p.age = -10;

        p.Age = 10; // Age의 set / get이 바뀌더라도 해당 코드는 수정되지 않는다.
        Console.WriteLine(p.Age);
    }
}






