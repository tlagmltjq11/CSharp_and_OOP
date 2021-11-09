using System;

// 핵심
// 1. 가변 배열 (jagged array) : 각 행에는 배열을 나타내는 참조값이 관리된다 ! 
// -> 즉 배열을 요소로 갖는다.

class Program
{
    static void Main()
    {
        int[]  a = new int[3];
        int[,] b = new int[3,3];


        int[][] arr = new int[3][]; // 각 행에 값이 아닌 참조를 보관한다.
        // 즉 각 행에는 행마다 배치되는 가변 배열을 나타낼 참조가 관리되는 것이다.

        arr[0] = new int[3] { 1, 2, 3 };
        arr[1] = new int[2] { 1, 2 };
        arr[2] = new int[1] { 1 };

        int[] a1 = arr[0]; // 각 행에는 배열을 나타내는 참조가 저장되기 때문에
        // 위 코드는 배열자체를 반환하는 코드가 된다.

        arr[0][1] = 10;
      
        // 바로 초기화 하는 방식
        int[][] arr2 = new int[3][] { new int[3], 
                                      new int[2], 
                                      new int[1] };  

    }
}


