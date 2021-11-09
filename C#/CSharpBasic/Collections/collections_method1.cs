using System;
using System.Collections.Generic;

// 핵심
// 1. 검색과 관련된 컬렉션 메소드들
// IndexOf, FindIndex, FindAll

// 2. ★ 매개변수 Predicate(조건자)는 Delegate 라는 점! -> bool을 반환한다.

namespace CSHARP.CSharpBasic.Collections
{
    class collections_method1
    {
        public static bool Divide3(int n)
        {
            return n % 3 == 0;
        }

        static void Main()
        {
            List<int> c1 = new List<int>() {1,2,3,1,2,3,1,2,3,9};

            // 값 검색
            Console.WriteLine(c1.IndexOf(3)); // 2 : 첫번째 인덱스부터 시작해 3을 찾아라
            Console.WriteLine(c1.IndexOf(3, 5)); // 5 : 5번째 인덱스부터 시작해 3을 찾아라
            Console.WriteLine(c1.IndexOf(3, 6, 2)); // -1 : 6번째 인덱스부터 2개까지만 3을 찾아라

            // 조건 검색 : 3의 배수 찾기
            // 매개변수가 Predicate(조건자) 인데 이는 델리게이트이다. 즉 조건을 정의한 메소드를 넘겨주면 된다.
            Console.WriteLine(c1.FindIndex(Divide3)); // 2 : 메소드를 외부에 직접 구현해서 넘겨주는 방식
            Console.WriteLine(c1.FindIndex(n => n%3==0)); // 2 : 람다식으로 무명 메소드를 넘겨주는 방식

            // 조건을 만족하는 모든 요소 찾기
            List<int> c2 = c1.FindAll(n => n % 3 == 0);

            foreach (var n in c2)
            {
                Console.WriteLine(n);
            }
        }
    }
}
