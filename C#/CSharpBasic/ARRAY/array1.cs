using System;

// 핵심
// 1. 배열은 Array로 부터 파생되기 때문에 ref 타입이다.

// ★ 2. Array에서 제공하는 Clone() 메소드는 값이 동일한 완전히 새로운 객체를 할당해서 반환한다.

class Program
{
    static void Main()
    {
        int[] arr1; // 참조변수만.
        int[] arr2 = new int[5];
        int[] arr3 = new int[5] { 1, 2, 3, 4, 5 };
        int[] arr4 = new int[] { 1, 2, 3, 4, 5 }; // 초깃값이 있다면 크기 생략 가능
        int[] arr5 = { 1, 2, 3, 4, 5 }; // 컴파일러가 알아서 처리해준다.

        Type t = arr5.GetType();
        Console.WriteLine(t.FullName); // System.Int32[]
        Console.WriteLine(t.BaseType.FullName); // System.Array
        Console.WriteLine(t.BaseType.BaseType.FullName); // System.Object

        Console.WriteLine(arr5.Length);         // 5
        Console.WriteLine(arr5.GetLength(0));   // 5 : 1차의 크기를 반환
        Console.WriteLine(arr5.GetValue(3));    // == arr5[3]
        Console.WriteLine(arr5.GetLowerBound(0));// 0 : 인덱스의 최솟값
        Console.WriteLine(arr5.GetUpperBound(0));// 4 : 인덱스의 최댓값


        int[] arr6 = { 1, 2, 3, 4, 5 };
        int[] arr7 = arr6; // 같은 주소를 참조 중
        int[] arr8 = (int[])arr6.Clone(); // 완전히 새로운 객체를 복사해서 해당 객체를 가리키게 한다.

        Console.WriteLine(arr6 == arr7);   // true            
        Console.WriteLine(arr6 == arr8);   // false
    }
}






// 1. 배열의 기본 모양