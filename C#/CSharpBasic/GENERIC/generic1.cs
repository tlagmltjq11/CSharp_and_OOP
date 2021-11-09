using System;
using System.Collections.Generic;

// 핵심
// 1. 타입을 사용하는 사람이 자료형을 정하는 것이 가장 효율적이다.

// ★ T는 임의의 타입이기 때문에 0으로 디폴트를 설정할 수 없다.
// -> default(T)를 사용하면 된다.
// -> T가 수치 관련 타입이면 0이 될 것이고
// -> 사용자 정의 타입이라면 디폴트 생성자로 생성할 것이다.

// 2. 컬렉션에서 가장 많이 사용된다.
class Point<T>
{
    private T x;
    private T y;

    // C++ : T a = T()
    // 디폴트 설정 법
    public Point( T xPos = default(T), T yPos = default(T))
    {
        x = xPos;
        y = yPos;
    }
}

class Program
{
    static void Main()
    {
        Point<int> pt = new Point<int>(1, 1);
        Point<double> pt2 = new Point<double>(1.1, 1.1);

        LinkedList<int> s = new LinkedList<int>();
    }
}
