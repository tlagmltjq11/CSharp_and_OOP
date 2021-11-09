using System;

// 핵심
// 1. nullable 개념을 이용해서 val 타입도 null과 같이 "값이 없음"을 나타낼 수 있다.
// nullable은 내부적으로 bool 값을 갖고 값이 존재하는지 여부를 판단한다.

class Program
{
    //public static int foo()
    public static Nullable<int> foo()
    {
        if (실패)
            return null; // 실패를 위한 값을 정하는 것이 문제였다. -1 자체가 결과의 값일 수도 있기 때문.
        return 100;
    }

    public static void Main()
    {
        // string : reference type
        string s1 = "Hello";
        string s2 = null;  // 객체는 없고, 참조타입만 존재
        // -> 참조타입은 null을 사용해 객체가 없다는 것을 표현할 수 있다.

        // int : value type
        //int n1 = 10;
        //int n2 = ?;  // 값이 없음을 나타내고 싶다.

        Nullable<int> n1 = 10;
        Nullable<int> n2 = null;

        if (n2 == null) { }

        // Nullable 단축 표기법!!
        int? n3 = null; // Nullable<int> n3 = null;
    }
}