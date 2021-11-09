using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// 1. Linq의 쿼리문은 "지연된 실행"을 한다.
// -> ★ 쿼리 메소드를 실제로 호출하는 시점은 "요소에 접근하는 시점" 이라는 것.

// 내 의견
// -> ★ 잘 생각해보면 MoveNext를 호출해야 메소드가 호출되어 조건자에 맞게
// 요소들을 한개씩 뽑아내어 줄테니 "요소에 접근해야지"만 쿼리 메소드가 호출되는 것이다.

namespace CSHARP.CSharpBasic.LINQ
{
    class linq_impl1
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };

            IEnumerable<int> e = arr.Select(n => n * 10);

            // 아래 코드는 위 쿼리문이 실행된 후에 실행된다.
            // 하지만 일명 "지연된 실행"으로 쿼리 메소드를 호출하는 시점이
            // foreach 문에서 "요소에 접근하는 시점에 연산이 적용" 된다.
            // 고로 출력해보면 0이 출력된다.

            // -> 잘 생각해보면 MoveNext를 호출해야 메소드가 호출되어 조건자에 맞게
            // 요소들을 한개씩 뽑아내어 줄테니 "요소에 접근해야지"만 쿼리 메소드가 호출되는 것이다.
            arr[0] = 0;

            foreach (var n in e)
            {
                Console.WriteLine(n);
            }
        }
    }
}
