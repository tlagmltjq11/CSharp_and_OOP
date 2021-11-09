using System;

// 핵심
// 1. 즉 프로그램 세계에서는 생성된지 오래된 변수들이 앞으로도 오래살 가능성이 높다고 판단한다.
// -> 인간의 수명과 변수의 수명은 정반대 !


namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class garbage1
    {
        public static void Foo()
        {
            int n2 = 0; // 1시간 뒤 2번째로 생성된다.

            // .. 블록을 나가는 순간 n2는 파괴된다.
        }

        static void Main()
        {
            int n1 = 0; // 먼저 생성된다.

            // 이 사이에서 1시간이 지났다고 가정

            Foo(); // n2는 파괴됐지만 n1은 아직 살아있다.

            // 즉 프로그램 세계에서는 생성된지 오래된 변수들이 앞으로도 오래살 가능성이 높다고 판단한다.
        }
    }
}
