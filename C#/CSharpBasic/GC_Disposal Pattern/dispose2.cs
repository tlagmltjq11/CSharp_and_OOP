using System;
using System.IO;

// 핵심
// 1. 가비지는 메모리가 부족하거나 사용자가 강제로 GC를 돌렸다거나 특정 조건을 만족해야 수거된다.

// 2. 소멸자는 GC에 의해서 수거되었다고 해서 곧바로 호출되는 것이 아니라 다른 스레드를 만들어 수행한다.

namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class Car
    {
        public void Go() { Console.WriteLine("Car Go"); }
        
        // finalizer
        ~Car() { Console.WriteLine("~Car"); }
    }

    class dispose2
    {
        static void Main()
        {
            Car c1 = new Car();
            Car c2 = new Car();

            c2 = null;

            // 결코 좋은 코드는 아니다.
            GC.Collect(); // 강제로 GC call
            GC.WaitForPendingFinalizers(); // 소멸자를 강제로 호출하는 방법 

            c1.Go();

            Console.Read();
        }
    }
}
