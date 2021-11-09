using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// 1. Query Syntax 형식으로 사용하면 컴파일러가 Fluent Syntax로 바꿔서 작동한다.
// 어쨌든 두가지 사용방식이 있다는 것.

namespace CSHARP.CSharpBasic.LINQ
{
    class linq_query_exp1
    {
        static void Main()
        {
            string[] arr = { "kim", "lee", "park", "choi", "rober" };

            // 아래 Fluent Syntax를 쿼리문처럼 사용할 수 있다.
            // Query Syntax
            var e = from s in arr
                    where s.Contains("o")
                    orderby s.Length
                    select s.ToUpper();

            /*
            // Fluent Syntax
            var e = arr.Where(s => s.Contains("o"))
                       .OrderBy(s => s.Length)
                       .Select(s => s.ToUpper());
            */

            foreach (var n in e)
            {
                Console.WriteLine(n);
            }
        }
    }
}
