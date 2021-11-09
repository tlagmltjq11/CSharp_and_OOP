using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Collections.Concurrent;

// Object : 타입 안정성이 안좋고, 박싱/언박싱/캐스팅, 제네릭 이전에 사용하던 것
// Specialized: 각 타입에 대한 컬렉션을 전부 만들어둬야하는 문제가 존재한다.
// Generic : 타입 안정성이 뛰어나고, 박싱/언박싱/캐스팅 문제가 없다. 또한 모든 컬렉션을 미리 만들어두지 않아도 된다.
// Concurrent : 스레드 세이프

namespace CSHARP.CSharpBasic.Collections
{
    class collections2
    {
        static void Main()
        {
            ArrayList c1 = new ArrayList();
            c1.Add(1);
            c1.Add("aaa"); // c2에 넣으려했는데 실수 -> Type에 대한 안전성이 없다.
            
            StringCollection c2 = new StringCollection(); // 특정 타입만 저장
            c2.Add("str");
            //c2.Add(1); // 타입 안정성이 뛰어나다.
            string s2 = c2[0]; //캐스팅이 필요없다.

            List<int> c3 = new List<int>();
            c3.Add(3);

            ConcurrentStack<int> c4 = new ConcurrentStack<int>();
        }
    }
}
