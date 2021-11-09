using System;

// 핵심
// 1. params가 매개변수의 맨앞에 있으면 어디까지가 배열의 끝인지 알 수 없기에 마지막에 써야한다.

// 2. params를 통해서 매개변수를 넘길 때, 계속해서 배열이 힙에 할당되고 가비지가 되기 때문에
// 성능의 저하를 불러올 수 있다. 고로 자주 사용되는 매개변수의 갯수를 담당하는 메소드를
// 여럿 오버로딩으로 생성해 성능의 저하를 막는 것이 좋다.
// 실제로 Console.WriteLine() 같은 경우 매개변수 1~4 개 까지 오버로딩 되어 있으며
// 5개 이상부터 params 메소드가 호출되어 배열이 할당된다.

class Program
{
    // object 배열로 여러 타입의 인자를 받을 수 있다.
    public static void f1(params object[] arr)
    {
        foreach (object o in arr)
            Console.WriteLine(o.ToString());
    }

    public static void Main()
    {
        f1(1, 3.4, "Hello");
        f2(1, 2, 3, 4);
        //f3(1, 2, 3, 4);

        int s1 = Sum(1, 2); // params 없는 버전 사용
        int s2 = Sum(1, 2, 3, 4); // new int[]{1,2,3,4}
        int s3 = Sum(1, 2, 3); // params 없는 버전 사용
    }

    // params가 앞에있으면 어디까지가 배열의 끝인지 알 수 없기에 마지막에 써야한다.
    public static void f2(int a, params int[] arr) { }
    //public static void f3(params int[] arr, int a) { }

    // 힙 할당과 가비지에 의한 성능 저하를 막기위해 자주 사용되는 버전은 오버로딩으로 만들어 둔다.
    public static int Sum(int a, int b)
    {
        Console.WriteLine("int, int");
        return a + b;
    }

    public static int Sum(int a, int b, int c)
    {
        Console.WriteLine("int, int, int");
        return a + b + c;
    }

    public static int Sum(params int[] arr)
    {
        Console.WriteLine("params");

        int s = 0;

        foreach (int n in arr)
            s += n;

        return s;
    }
}