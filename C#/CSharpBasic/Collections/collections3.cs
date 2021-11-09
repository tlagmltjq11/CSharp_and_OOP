using System;
using System.Collections.Generic;

// 핵심
// 1. 다른 컬렉션을 쓰더라도 데이터를 조작하는 메소드명이 똑같아서 편리하다.
// -> interface를 기반으로 설계해서 "메소드명을 통일"한 것이다.

// 2. 컬렉션과 관련된 인터페이스
// IEnumerable<T> : 열거자(반복자)를 꺼내기 위한 GetEnumerator() 메소드 포함, ★ 모든 컬렉션이 구현했다.
// ICollection<T> : Add, Clear, Remove 등, 대부분의 컬렉션이 구현했다.
// IList<T> : ★ 인덱서, IndexOf, Insert, RemoveAt 등등, 일부 컬렉션이 구현했다.
// -> ★ 보통 저장한 데이터들이 메모리에 연속적으로 존재하는 컬렉션이 IList를 구현한다.

namespace CSHARP.CSharpBasic.Collections
{
    class collections3
    {
        static void Main()
        {
            List<int> c1 = new List<int>();
            c1.Add(10);
            c1.Add(20);
            c1.Clear();

            SortedSet<int> c2 = new SortedSet<int>();
            c2.Add(10);
            c2.Add(20);
            c2.Clear();
        }
    }
}
