using System;
using System.Collections.Generic;
using System.Collections;

// 핵심
// 1. ★ 폴더 내에 yield(코루틴)를 이용해 열거자를 만들었을 때 작동방식 이미지 참고하기 !!!

// 2. ★ 실제로 메소드가 호출되어 실행되는 시점은 MoveNext()가 호출된 시점이다 !!!
// -> 현재 파일 실행해보면 제대로된 순서를 파악 할 수 있다 !

// 3. 즉 yield (코루틴)은 열거자를 만들 때 굉장히 유용하게 사용할 수 있다는 점.

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

        public IEnumerator GetEnumerator()
        {
            Console.WriteLine("GetEnumerator Start");
            Node current = head;

            while (current != null)
            {
                Console.WriteLine("yield return");

                // 반환형은 IEnumerator 이지만 int를 반환하고 있다. yield 때문에 가능한 것.
                yield return current.data;
                current = current.next;
            }
        }
    }

    class enumerator_impl5
    {
        static void Main()
        {
            IntLinkedList st = new IntLinkedList();

            st.AddFirst(10);
            st.AddFirst(20);
            st.AddFirst(30);
            st.AddFirst(40);
            st.AddFirst(50);

            // GetEnumerator() 메소드가 호출되어 동작되는 순간이 아니다.
            IEnumerator e = st.GetEnumerator();
            Console.WriteLine("AAA");

            // 실제로 메소드를 호출시키는 순간은 MoveNext()를 호출한 순간이다. !!!
            while (e.MoveNext())
            {
                Console.WriteLine("BBB");
                Console.WriteLine(e.Current);
            }

            Console.Read();
        }
    }
}
