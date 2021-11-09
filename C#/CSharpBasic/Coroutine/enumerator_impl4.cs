using System;
using System.Collections.Generic;
using System.Collections;

// 핵심
// 1. 모든 컬렉션은 열거자를 반환할 수 있어야 한다.
// -> 컬렉션 자신만의 "열거자 타입을 설계" 해야 한다.

// 2. ★ Coroutine을 사용해서 열거자를 만들 수 있다.
// -> ★ 별도의 열거자 타입이 필요없다.
// -> ★ GetEnumerator() 메소드에서 "컬렉션이 가진 모든 요소에 대해 yield return 수행"

namespace CSHARP.CSharpBasic.Coroutine
{
    class Node
    {
        public int data;
        public Node next;

        public Node(int data, Node next)
        {
            this.data = data;
            this.next = next;
        }
    }

    class IntLinkedList : IEnumerable
    {
        public Node head = null;

        public void AddFirst(int data)
        {
            head = new Node(data, head);
        }

        // -> GetEnumerator() 메소드에서 "컬렉션이 가진 모든 요소에 대해 yield return 수행"
        public IEnumerator GetEnumerator()
        {
            Node current = head;

            while(current != null)
            {
                yield return current.data; // 열거자를 만드는 법이 너무 쉬워졌다.
                current = current.next;
            }
        }
    }

    class enumerator_impl4
    {
        static void Main()
        {
            IntLinkedList st = new IntLinkedList();

            st.AddFirst(10);
            st.AddFirst(20);
            st.AddFirst(30);
            st.AddFirst(40);
            st.AddFirst(50);

            IEnumerator e = st.GetEnumerator();

            while (e.MoveNext())
            {
                Console.WriteLine(e.Current);
            }

            Console.Read();
        }
    }
}
