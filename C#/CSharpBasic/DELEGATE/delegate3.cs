using System;

// 핵심
// 1. Delegate는 Class이며 컴파일러가 다음과 같은 코드로 변경해준다.
// 너무많은 축약형 표현법을 지원하는게 오히려 독이 될 수 있다.. 정확한 원리를 파악하자

delegate void FUNC(int arg);

// 컴파일러가 위 코드를 아래와 같이 변경해준다.
/*
class FUNC : System.MulticastDelegate
{
    // 반환값이 void고 파라메터를 저장할 정보를 모두 생성해준다.
    //....
}
*/

class Program
{
    public static void Main()
    {
        FUNC f1 = new FUNC(foo); // 정확한 표기법
        f1.Invoke(10);       // 정확한 표기법

        // 단순 표기법 하지만 원리를 알아야 한다.
        FUNC f2 = foo; 
        f2(10); // f2.Invoke(10)
    }

    public static void foo(int arg)
    {
        Console.WriteLine($"foo : {arg}");
    }
}


