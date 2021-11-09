using System;

// 핵심
// 1. Delegate.Combine(delegate1, delegate2)
// 두 델리게이트를 합친 것을 반환
// -> Method 이름을 직접 사용할 수 없다.

// ★ 2. +, +=, -, -= 연산자
// Delegate 이름 또는 Method 이름을 사용하여 결합이 가능하다.

// ★ 3. Delegate는 Immutable 하다!

class Test
{
    public static int Method1() 
    {
        Console.WriteLine("Method1"); 
        return 1; 
    }

    public static int Method2() 
    {
        Console.WriteLine("Method2"); 
        return 2; 
    }

    public static int Method3() 
    {
        Console.WriteLine("Method3"); 
        return 3; 
    }

    public static int Method4()
    {
        Console.WriteLine("Method4"); 
        return 4; 
    }
}

delegate int FUNC();

class Program
{
    public static void Main()
    {
        FUNC f1 = Test.Method1;
        FUNC f2 = Test.Method2;
        FUNC f3 = Test.Method3;

        // 1. Delegate.Combine()
        //FUNC f4 = (FUNC)Delegate.Combine(f1, f2);
        //FUNC f4 = (FUNC)Delegate.Combine(f1, f2, f3);
        //FUNC f4 = (FUNC)Delegate.Combine(f1, Test.Method4);
        //f4();

        // 2. +, -, += , -=
        //FUNC f5 = f1 + f2 + f3;
        //FUNC f5 = f1 + Test.Method4 + f2;
        //f5();

        // 3. delegate 는 reference type
        FUNC f6 = Test.Method1;
        FUNC f7 = f6;

        Console.WriteLine(f6 == f7); // true : 같은 주소를 참조

        // 불변 클래스이기 때문에 아예 새로운 객체가 할당된다.
        f6 += Test.Method2; // f6 = f6 + Test.Method2;
                            // f6 = new FUNC(  ... )
        Console.WriteLine(f6 == f7); // false : 서로 다른 주소를 참조

      
        f6(); // 2개 호출
        Console.WriteLine("----");
        f7(); // 1개


        // 델리게이트는 불변 클래스다. 2번째 예제
        FP f1 = Foo; // FP f1 = new FP(Foo);
        FP f2 = f1;

        if (f1 == f2)
        {
            Console.WriteLine("same"); // 참조타입으로 같은 곳을 가리키므로 출력될 것이다.
        }

        f2 += Goo;

        if (f1 == f2)
        {
            Console.WriteLine("same");
        }
        else
        {
            Console.WriteLine("Not same"); // 불변인데 새로운 객체를 넣었으므로 다른 객체가 된다.
        }

        f1(10); // Foo 만 호출된다!!!!!!!!!!!!
        // -> 이유는 델리게이트는 불변 객체이기 때문 (string과 같다)

        // c#의 문자열은 불변이다. (참조타입)
        string s1 = "AA";
        string s2 = s1;

        s1 = "BBBB"; // s1이 가리키는 곳이 변경되지 않고
                     // "BBBB"라는 새로운 객체를 생성 후 s1이 가리키게 한다.

        Console.WriteLine(s2);
    }

    public static void Foo(int a) { Console.WriteLine($"Foo : {a}"); }
    public static void Goo(int a) { Console.WriteLine($"Goo : {a}"); }
}


