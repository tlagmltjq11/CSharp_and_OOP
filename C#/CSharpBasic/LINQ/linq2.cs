using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// 컬렉션에 있는 요소 중 3의 배수만 얻고 싶은 상황.
// 1. Linq는 컬렉션에 대한 다양한 연산을 위한 Query 문이다.
// -> 컬렉션에 대한 다양한 연산을 편리하게 만들 수 있다.

// 2. Query에 대한 반환 값 타입
// -> ★ 보통은 IEnumerable<T>이다. 즉 결과값을 모두 담은 컬렉션을 반환해주는 것이다.
// -> 보통은 편하게 var를 사용해서 받는다.

namespace CSHARP.CSharpBasic.LINQ
{
    class linq2
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            // 직접 구현하여 얻어내는 방식
            foreach (var n in arr)
            {
                if(n%3 == 0)
                {
                    Console.WriteLine(n);
                }
            }



            // Linq를 이용해 얻어내는 방식
            // ★ IEnumerable<T>를 반환한다는 것은 결과값을 담은 컬렉션을 반환했다는 것
            IEnumerable<int> e = arr.Where(n => n % 3 == 0);

            foreach (var n in e)
            {
                Console.WriteLine(n);
            }
        }
    }
}
