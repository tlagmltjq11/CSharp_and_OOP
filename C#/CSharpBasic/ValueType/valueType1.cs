using System;

// 핵심
// 1. 객체의 크기가 작다면 Stack, 크다면 Heap에 할당하는 것이 일반적이다.

// 2. c/c++ 은 "객체의 메모리 위치를 타입을 만드는 사람이아닌
// -> 타입을 사용하는 사람이 결정" 한다.
// -> 하지만 어떠한 타입의 크기가 클지 작을지는 설계자가 더 잘 알고 있을 것이다.
// 고로 C#은 val, ref 타입이라는 개념으로 객체를 구분하여 타입을 만드는 설계자가
// 해당 객체가 어느 메모리에 할당될 지를 결정한다.

// 3. val, ref 타입의 개념

struct SPoint
{
    public int x;
    public int y;

    public SPoint(int xPos, int yPos) 
    { 
        x = xPos; 
        y = yPos; 
    }
}

class CPoint
{
    public int x;
    public int y;

    public CPoint(int xPos, int yPos) 
    { 
        x = xPos; 
        y = yPos; 
    }
}

class Program
{
    public static void Main()
    {
        SPoint sp1 = new SPoint(1, 1); // val 타입이므로 stack에 할당
        CPoint cp1 = new CPoint(1, 2); // ref 타입이므로 heap에 할당

        // 핵심 ★
        SPoint sp2 = sp1; // 객체 2개. 객체 자체를 복사!!!
        CPoint cp2 = cp1; // 참조(주소)복사!!!, 객체 한개
        
        sp2.x = 10;
        Console.WriteLine(sp1.x); // 1

        cp2.x = 10; // 같은 객체를 참조하고 있으므로 원본까지 변경
        Console.WriteLine(cp1.x); // 10



        // 동일해 보이는 코드지만 val, ref 타입
        SPoint sp1;
        SPoint sp2 = new SPoint();
        // 위 두 코드는 모두 스택에 객체를 생성하게됨.

        CPoint cp1; // 참조변수만 스택에 할당됨. 객체가 아님
        CPoint cp2 = new CPoint(); // 힙에 객체까지 할당된 상태 즉 객체임.

        sp1.x = 10;
        sp2.x = 10;
        cp1.x = 10; // error. 참조변수만 존재함.
        cp2.x = 10;
    }
}


