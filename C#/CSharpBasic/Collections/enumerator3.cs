using System;
using System.Collections.Generic;

// 핵심
// 1. 모든 컬렉션은 foreach를 사용해서 열거 할 수 있다.
// -> 사실 내부적으로는 열거자를 사용해서 열거하는 것이다.

namespace CSHARP.CSharpBasic.Collections
{
    class enumerator3
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };
            List<int> c1 = new List<int>(arr);

            foreach(int n in c1)
            {
                Console.WriteLine(n);
            }

            // ★ 사실 위 foreach 코드는 아래와 같이 변경되어 동작한다. 
            for(IEnumerator<int> iter = c1.GetEnumerator(); iter.MoveNext(); )
            {
                Console.WriteLine(iter.Current);
            }

            Console.Read();
        }
    }
}
