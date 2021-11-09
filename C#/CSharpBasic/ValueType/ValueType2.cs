using System;

// 핵심
// 1. new없이 객체를 할당 할 수 있는 단순 표기법을 제공한다.

// 2. 모든 배열은 Array로 부터 파생되기 때문에 Class이며 곧 ref 타입이다.
// + Clone() 메소드

// 3. string은 class로 ref 타입이며, 불변 클래스 이다.

// 4. struct, enum 등 모든 수치 관련 타입 == val 타입
//    class, interface, delegate, string 등 모든 클래스 == ref 타입

class Program
{
    public static void Main()
    {
        // int n = new int();

        // C#에서는 모든것이 객체이기 때문에 new로 할당해야 하지만
        // 편리한 표기법을 제공하는 것이다.
        // 1. int는 구조체이기 때문에 value 타입이다.
        int n1 = 1;
        int n2 = n1; // n2 만의 객체를 스택에 할당 후 값을 복사

        n2 = 10;
        Console.WriteLine(n1); // 1



        // 2. 모든 array는 System.Array로 부터 파생된다.
        // ★ 이때 Array는 클래스이기 때문에 ref 타입이다.
        //System.Array a;
        int[] arr1 = { 1, 2, 3 };
        int[] arr2 = arr1;

        arr2[0] = 10;

        Console.WriteLine(arr1[0]); // 10


        // 얕은 복사 vs 깊은 복사
        int[] arr1 = new int[] { 1, 2, 3, 4 };
        int[] arr2 = arr1; // arr2가 같은 배열을 가리킨다.

        int[] arr3 = (int[])arr1.Clone(); // 복사본 배열을 만들어 달라.
                                          //프로토타입 패턴의 활용



        // ★ 3. string은 class라서 ref 타입이긴 하지만 불변 클래스이다.
        string s1 = "Hello";
        string s2 = s1;

        Console.WriteLine(s1 == s2); // true 주소가 같다.

        // string은 불변클래스이기 때문에 힙에 "world"를 따로 할당 후 s2가 해당 주소를 참조하게 된다.
        s2 = "world"; // s2 = new string("world")

        Console.WriteLine(s1 == s2); // false 주소가 다르다.
        Console.WriteLine(s1);// "world"
    }
}


