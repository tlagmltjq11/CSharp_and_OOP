using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// 1. 모든 컬렉션은 IEnumerable<T> 인터페이스를 구현했기 때문에
// -> ★ 모든 컬렉션을 IEnumerable<T> 인터페이스로 참조 할 수 있다 !!!

// 2. IEnumerable<T> 인터페이스가 GetEnumerator() 메소드를 제공하기 때문에
// -> ★ 해당 인터페이스 타입의 참조 변수를 foreach에 사용할 수 있다 !!!

namespace CSHARP.CSharpBasic.LINQ
{
    class linq1
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };

            foreach (var n in arr) // 실제로는 arr.GetEnumerator()를 통해서 열거자를 꺼내어 사용하는 것
            {
                Console.WriteLine(n);
            }

            IEnumerable<int> col = arr; // 인터페이스로 컬렉션 참조하기

            foreach (var n in col) // 인터페이스가 GetEnumerator()를 제공하기에 foreach에도 사용할 수 있다.
            {
                Console.WriteLine(n);
            }
        }
    }
}
