using System;
using System.Collections.Generic;

// 핵심
// 1. 정렬과 관련된 컬렉션 메소드들
// Sort

// 2. ★ Sort의 매개변수 중 Comparison<T>은 int를 반환하는 Delegate 라는 점 !!
// 3. ★ Sort의 매개변수 중 IComparer<T>는 인터페이스로 구현한 객체를 보내주어야 한다.

namespace CSHARP.CSharpBasic.Collections
{
    class MyCompare : IComparer<int>
    {
        public int Compare(int a, int b)
        {
            return a < b ? 1 : ((a == b) ? 0 : -1);
        }
    }

    class collections_method2
    {
        static void Main()
        {
            List<int> c1 = new List<int>() { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };

            c1.Sort(); // 디폴트 오름차순

            // 내림차순으로 변경
            // Comparison<T> 델리게이트에 람다식 무명 메소드를 전달
            c1.Sort((a, b) => { return a < b ? 1 : ((a == b) ? 0 : -1); });

            // 내림차순으로 변경
            // IComparer<T>를 구현한 객체를 넘겨주어 Compare 메소드를 기준으로 정렬하도록 한다.
            c1.Sort(new MyCompare());

            foreach (var n in c1)
            {
                Console.WriteLine(n);
            }

            Console.Read();
        }
    }
}
