using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// 1. where, select, skip

namespace CSHARP.CSharpBasic.LINQ
{
    class linq3
    {
        public static bool IsOdd(int n)
        {
            return n % 2 == 1;
        }

        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

            // 배열에서 홀수만 얻고 싶다.
            //IEnumerable<int> e = arr.Where<int>(IsOdd);

            // ★ 보통 람다식으로 넘기는것이 보통이며 아래처럼 .을 맞춰 정렬하는것이 관례이다.
            IEnumerable<int> e = arr.Where<int>(n => n%2 == 1)
                                    .Select(n => n * 10)
                                    .Skip(3);

            foreach (var n in e)
            {
                Console.WriteLine(n);
            }

            Console.Read();
        }
    }
}
