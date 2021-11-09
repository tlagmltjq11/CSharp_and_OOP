using System;
using System.Collections.Generic;

// 핵심
// ★ 1. 열거자(iterator)는 컬렉션의 요소를 가리키는 객체다.
// -> 모든 열거자는 사용법이 동일하다 즉 모든 열거자는 IEnumerator<T>를 구현했다.
// -> MoveNext(), Current, Reset() 멤버로 모든 요소에 접근한다.

// 2. 열거자를 받고나서 MoveNext를 꼭 한번 호출해줘야 초기화되게 만든 이유는
// 그렇게 만들어야 while문에서 사용하기 편하기 때문이다.

namespace CSHARP.CSharpBasic.Collections
{
    class enumerator2
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };

            List<int> c1 = new List<int>(arr);
            LinkedList<int> c2 = new LinkedList<int>(arr);

            IEnumerator<int> e1 = c1.GetEnumerator();
            IEnumerator<int> e2 = c2.GetEnumerator();

            //e1.MoveNext(); // 최초호출 -> 초기화
            //Console.WriteLine(e1.Current); // 1

            //e1.MoveNext();
            //Console.WriteLine(e1.Current); // 2

            while(e1.MoveNext())
            {
                Console.WriteLine(e1.Current);
            }

            while (e2.MoveNext())
            {
                Console.WriteLine(e2.Current);
            }

            e1.Reset();
            e2.Reset();

            Console.Read();
        }
    }
}
