using System;

// 핵심
// 1. Boxing : c#에서 참조변수는 오로지 힙만 가리킬 수 있기 때문에 스택에 있는 객체를 곧바로 가리킬 수 없다.
// -> 고로 힙에 val 타입 객체에 대한 복사본이 생성되고 해당 객체를 o1이 가리키게 된다. Boxing
// -> 힙에 객체 할당 + 값 복사 과정에 의해 일반 단순 복사에 비해 굉장히 큰 성능 저하를 야기한다.

// 2. UnBoxing : 힙에 존재하는 객체의 값을 스택에 존재하는 객체에 복사하는 과정이다.
// -> 명시적 캐스팅을 필요로하며, 메모리상에 먼 주소를 왔다갔다 하기 때문에 성능의 저하를 야기한다.

class Program
{
    static void Main()
    {

        int[] a1 = { 1, 2, 3 };
        object o1 = a1;
        a1[0] = 10;

        int[] a2 = (int[])o1;

        Console.WriteLine(a2[0]); // 10



        int n1 = 1;

        object o2 = n1; // ref 변수는 힙을 가리키게만 되어있으므로 boxing이 일어난다.

        n1 = 10; // 스택 객체만 변경됨.

        int n2 = (int)o2; // UnBoxing

        Console.WriteLine($"{n1}, {n2}"); // 10, 1
    }
}
