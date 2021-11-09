using System;
using System.Collections.Generic;
using System.Collections;

// 핵심
// 1. 열거자를 직접 구현해본다. 2단계

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

    // 열거자 만들기
    class IntLinkedListEnumerator : IEnumerator
    {
        public Node head = null;
        public Node current = null;

        public IntLinkedListEnumerator(Node n)
        {
            head = n;
        }

        public object Current => current.data;

        // 앞에서 최초 호출 후 초기화되던 것을 기억하자
        public bool MoveNext()
        {
            // 최초 호출 시
            if(current == null)
            {
                current = head;
            }
            else
            {
                current = current.next;
            }

            return current != null; // 실패했다면 null일 것임.
        }

        public void Reset()
        {
            current = null; // 초기화
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
            return new IntLinkedListEnumerator(head);
        }
    }

    class enumerator_impl3
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