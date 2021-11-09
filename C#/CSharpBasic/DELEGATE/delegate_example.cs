using System;

// 핵심
// 1. ★ 공통성과 가변성의 분리
// 변하지 않는 코드 내에 있는 "변하는 코드는 분리" 한다.
// 알고리즘은 변경되지 않는데, "정책을 변경" 하고 싶은 경우
// 변하는 부분을 함수 인자로 변경한다 => Delegate
// 즉 오름차순/내림차순을 함수인자를 통해서 사용자가 결정할 수 있게 하자는 것이다.
// 코드를 직접 바꿀 수 없으니, 해당 부분을 Delegate로 분리해내서 사용하자.

delegate int Comparison(int arg1, int arg2);

class Program
{
    public static void Swap(ref int a, ref int b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    

    public static void Sort(int[] arr, Comparison cmp)
    {
        int sz = arr.GetLength(0);

        // 버블소트
        for (int i = 0; i < sz - 1; i++)
        { 
            for (int j = i + 1; j < sz; j++)
            {
                //if ( arr[i] > arr[j] )           

                if ( cmp( arr[i], arr[j]) > 0)
                    Swap(ref arr[i], ref arr[j]);
            }
        }
    }


    static void Main()
    {
        int[] x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

        // 밖에 직접 메소드를 구현해서 넘겨줘도 되고
        // 익명메소드 or 람다식으로 넘겨줘도 된다.
        // 내림차순
        Sort(x, 
            delegate(int a, int b) { return a < b ? 1 : -1; } );

        foreach (int n in x)
            Console.WriteLine(n);
    }
}

