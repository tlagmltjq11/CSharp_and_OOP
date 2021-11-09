using System;
using System.Collections.Generic;
using System.Linq;

// 핵심
// Linq의 구현 원리를 이해 하려면
// 확장메소드, 델리게이트, 람다식, 코루틴의 개념을 알아야 한다.

// 1. 실제로 Linq가 어떻게 구현되어있는지 파악하자.
// -> 제공되는 Select는 호출 후 실제로 요소에 접근하는 즉 foreach문을 만났을 때
// -> 실제로 쿼리 메소드가 실행되어 컬렉션을 반환했다.
// -> 위 내용은 MoveNext가 호출되어야만 현재 리턴할 요소를 계산해서 내어주는 열거자와 동일하다.

// 위를 실제로 구현해보기 위해서 컬렉션 라이브러리에 확장메소드를 통해 MySelect 메소드를 추가하고
// 람다식으로 predicate를 받아온다. 그 후 yield 구문을 사용해서 즉 코루틴을 사용해서
// 열거자를 갖는 컬렉션을 반환한다. 사용자는 해당 컬렉션에서 열거자를 뽑아내어
// MoveNext나 foreach를 통해서 실제 요소에 접근할 때 ★ predicat가 실행되어 실제 요소를
// 순차적으로 반환해주는 구조가 되는 것이다.

namespace CSHARP.CSharpBasic.LINQ
{
    class linq_impl2
    {
        static void Main()
        {
            int[] arr = { 1, 2, 3, 4, 5 };

            IEnumerable<int> e = arr.MySelect<int>(n => n * 10); // 코루틴이니까 이때 메소드가 호출되는게 아니다.

            IEnumerator<int> p = e.GetEnumerator(); // 열거자를 뽑느다.

            Console.WriteLine("1");

            while(p.MoveNext()) // MoveNext가 호출되는 시점에 메소드가 실제로 호출된다.
            {
                Console.WriteLine("2");
                Console.WriteLine(p.Current);
            }

            Console.Read();
        }
    }

    //public static class MyLinq
    //{
    //    // 확장메소드
    //    public static IEnumerable<int> MySelect(this Array arr, Func<int, int> predicate)
    //    {
    //        foreach (int n in arr)
    //        {
    //            Console.WriteLine("MySelect");
    //            yield return predicate(n);
    //        }
    //    }
    //}

    // 모든 컬렉션에 적용할 수 있는 MySelect 버전 !!!
    public static class MyLinq
    {
        // 확장메소드
        public static IEnumerable<T> MySelect<T>(this IEnumerable<T> arr, Func<T, T> predicate)
        {
            foreach (T n in arr)
            {
                Console.WriteLine("MySelect");
                yield return predicate(n);
            }
        }
    }
}
