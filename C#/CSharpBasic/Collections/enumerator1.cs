using System;
using System.Collections.Generic;

// 핵심
// 1. 비연속적 메모리를 사용하는 컬렉션은 인덱서제공x -> 즉 IList<T>를 구현하지 않았다는 것.
// -> ★ 고로 컬렉션이 무엇이냐에 따라서 열거하는 방식이 상이할 수 있다.

// 2. 열거자(iterator) 패턴
// -> 모든 컬렉션은 IEnumerable<T>을 구현했기 때문에 열거자를 사용할 수 있다.
// -> ★★ 모든 컬렉션이 동일한 방식으로 내부 데이터를 열거할 수 있게된다.

namespace CSHARP.CSharpBasic.Collections
{
    class enumerator1
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };

            //List<int> c1 = new List<int>(arr); // 연속된 메모리
            LinkedList<int> c1 = new LinkedList<int>(); // 비연속이므로 인덱서제공x -> 즉 IList<T>를 구현하지 않았다는 것.

            for(int i=0; i < c1.Count; i++)
            {
                Console.WriteLine(c1[i]);
            }
        }
    }
}
