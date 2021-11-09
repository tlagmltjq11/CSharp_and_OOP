using System;

// 핵심
// 1. 다차원 배열 선언 법

class Program
{
    static void Main()
    {
        int[] arr = new int[3];

        int[,] arr1 = new int[3, 2];
        int[,] arr2 = new int[3, 2] { { 1, 1 }, 
                                      { 2, 2 }, 
                                      { 3, 3 } };

        int[,] arr3 = new int[,] { { 1, 1 }, 
                                   { 2, 2 }, 
                                   { 3, 3 } };

        int[,] arr4 = { { 1, 1 }, { 2, 2 }, { 3, 3 } }; // 단순 표기법

        arr1[0, 0] = 10;
        arr1[0, 1] = 20;

        foreach (int n in arr2) // foreach는 몇차원의 배열이든지 차례대로 꺼내줌
            Console.WriteLine(n);

        int[,,] arr5 = new int[2, 2, 2];
    }
}
    




// 5.  다차원 배열