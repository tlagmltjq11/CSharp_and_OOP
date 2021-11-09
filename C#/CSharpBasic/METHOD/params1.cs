using System;

// 핵심
// 매개변수의 개수가 가변적일 때에는, 배열을 매개변수로 받으면 될 것이다.

// 1. params : 메소드의 인자 개수를 가변 길이로 설정하는 키워드다.
// 즉 매개변수로 배열을 받긴 받을건데 params를 사용하면 일반 매개변수를 넘기듯이 넘겨도
// 자동으로 배열로 치환하여 받겠다는 의미가 된다.
// 고로 Sum(new int[] {1,2,3})과 같이 불편하게 호출하지 않고
// Sum(1,2,3)과 같이 편하게 호출할 수 있게 된다.

class Program
{
    //public static int Sum(int a, int b)
    //{
    //    return a + b;
    //}

    public static int Sum(params int[] arr)
    {
        int s = 0;

        foreach (int n in arr)
            s += n;

        return s;
    }

    public static void Main()
    {
        // 아래 두가지 표현식 모두 가능하다.
        int s1 = Sum(1,2);
        int s2 = Sum(1,2,3);

        int s3 = Sum(new int[] { 1, 2 });
        int s4 = Sum(new int[] { 1, 2, 3 });

        Console.WriteLine($"{s1}, {s2}");
    }
}