using System;

// 핵심
// 1. C#은 객체를 힙에 할당할 때, C/C++과 다르게 "연속적으로 할당하기 때문에"
// 메모리의 가용 공간을 찾는 오버헤드가 없다. -> 대신 재정렬 해줘야 하는 것으로 안다.

// 2. root를 통해서 현재 객체가 사용되고 있는지 판단하여 가비지를 찾아낸다.

// 3. GC를 거쳐도 살아남는다면 더 윗 세대로 배치된다. (세대별 GC)
// -> 모든 세대에 대해서 GC를 매번 돌리면 너무 오버헤드가 크다!
// -> 고로 가비지가 많이 생겨날 확률이 높은 낮은 세대에 대해서 GC를 돌리는 것이다.
// -> 하위 세대들이 모두 가득차지 않는 이상 윗 세대들은 수집되지 않는다.

// 4. ★ 사용자가 GC를 함부로 돌리는 것은 객체들이 쓸데없이 세대가 높아질 수 있다.
// -> 고로 빠르게 수집되지 않을 가능성이 높아진다. -> 결국엔 함부로 사용하지 말라는 것.

namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class A { }
    class B { }
    class C { }

    class garbage2
    {
        static void Main()
        {
            A a1 = new A();
            B b1 = new B();
            C c1 = new C();

            Console.WriteLine(GC.GetGeneration(a1)); // 0 : 몇 세대에 존재하는지 알려준다.
            GC.Collect(0); // 0 세대에 대해서 GC를 호출한다.

            Console.WriteLine(GC.GetGeneration(a1)); // 위에서 살아남았으니 1세대에 존재할 것이다.
            GC.Collect(1); // 1 세대 이하 대해서 GC를 호출한다.

            Console.WriteLine(GC.GetGeneration(a1)); // 위에서 살아남았으니 2세대에 존재할 것이다.

            a1 = null; // 2세대에 존재하는 a1이 수집되려면 한참을 기다려야 할 것.. 하위가 모두 꽉차야함

            b1 = null; // 가비지가 된다.

            A a2 = new A();
        }
    }
}
