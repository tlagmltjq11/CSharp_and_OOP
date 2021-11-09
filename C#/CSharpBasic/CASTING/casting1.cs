using System;

// 핵심
// 1. c#은 데이터의 손실이 발생하지 않는다면 암시적 형변환이 가능하다.
// -> 그 반대는 명시적 형변환이 필요함.


class Program
{
    static void Main()
    {
        int    n = 3;
        double d = 3.4;

        d = n; // int => double. 데이타 손실 없음.
        //n = d; // error : double=> int.  데이타 손실 발생.
        n = (int)d; // 데이터의 손실이 발생하기 때문에 명시적 형변환을 진행
    }
}

