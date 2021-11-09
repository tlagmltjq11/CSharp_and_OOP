using System;

// 핵심
//선택적 매개 변수의 주의사항
// 1. 디폴트 값은 "마지막(가장 오른쪽) 인자 부터 차례대로 지정해야 한다."

// 2. 디폴트 값은 "컴파일 시간에 알 수 있는 상수"로만 지정할 수 있다.

class Program
{
    public void f1(int a = 0, int b = 0, int c = 0){}
    public void f2(int a,     int b = 0, int c = 0) { }

    // f3, f4는 error
    public void f3(int a, int b = 0, int c) { } // error
    public void f4(int a = 0, int b, int c = 0) { } // error


    public void f5(DateTime dt = DateTime.Now) { } // error : 런타임에 정해지는 값을 디폴트로 사용했기 때문에 에러다.
    public void f6(DateTime dt = new DateTime()) { }
    public void f7(DateTime dt = default(DateTime)) { }

    public static void Main()
    {
        f3(1, 2);
    }
}
