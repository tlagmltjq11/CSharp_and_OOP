using System;

// 핵심
// 1. 반환값은 가장 마지막에 호출된 메소드의 반환값을 받는다.
// 모두 받고싶다면 각각 따로 호출해야 한다.
// ★ -> GetInvocationList()를 통해서 등록된 각 Delegate를 받아온 후
// 반복문을 통해서 각각의 리턴값을 받아내야 한다.

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
        FUNC uni = Test.Method1;

        int ret1 = uni();
        Console.WriteLine(ret1); // 1



        FUNC multi = Test.Method1;
        multi += Test.Method2;
        multi += Test.Method3;
        multi += Test.Method4;

        int ret2 = multi();
        Console.WriteLine(ret2); // 4

        //-------------------------
        // 각 Delegate를 모두 반환
        Delegate[] arr = multi.GetInvocationList();

        foreach( Delegate d in arr)
        {
            // 호출 할 때 캐스팅이 필요하다.
            FUNC f = (FUNC)d;
            int ret3 = f();
            Console.WriteLine(ret3);
        }
    }
}


