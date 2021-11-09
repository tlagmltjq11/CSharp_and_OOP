using System;

// 핵심
// 1. Comparison<in T>, Array.sort가 존재한다는 사실

// 아래 델리게이트는 이미 C# 표준에 존재한다.
//delegate int Comparison<in T>(T arg1, T arg2); // 제네릭을 도입하자

class Program
{
    public static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    // sort도 사실 Array 클래스에 존재함.
    public static void Sort(int[] arr, Comparison<int> cmp)
    {
        int sz = arr.GetLength(0);

        for (int i = 0; i < sz - 1; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {

                if (cmp(arr[i], arr[j]) > 0)
                    Swap(ref arr[i], ref arr[j]);
            }
        }
    }


    static void Main()
    {
        int[] x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

        //  Sort(x,
        //      delegate (int a, int b) { return a < b ? 1 : -1; });

        //Array.Sort(x);

        Array.Sort(x,
            delegate (int a, int b) { return a < b ? 1 : -1; }
            );

        foreach (int n in x)
            Console.WriteLine(n);
    }
}

