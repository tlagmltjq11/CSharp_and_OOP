using System;
using System.Collections.Generic;
using System.Collections;

// 핵심
// 1. 직접 열거자를 구현해보기 위해 IntLinkeList를 구현해본다. 1단계

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
            return new 열거자();
            //throw new NotImplementedException();
        }
    }

    class enumerator_impl2
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

            while(e.MoveNext())
            {
                Console.WriteLine(e.Current);
            }
        }
    }
}
