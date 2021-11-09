using System;
using System.Collections.Generic;
using System.Collections;

// 핵심
// 1. 코루틴 메소드를 만들 때 반환 타입은 IEnumerator<T> 또는 IEnumerable<T> 이어야 한다.
// -> 반환 방식은 yield return 반환값; 형식으로 사용한다.

// 2. 사용자 입장에서는 당연히 열거자 타입을 반환해주는게 편하다.
// -> LINQ는 컬렉션 인터페이스를 반환하는 타입을 사용한다 !

namespace CSHARP.CSharpBasic.Coroutine
{
    class coroutine1
    {
        // 서브루틴 - 계속해서 return 10에서 끝날 것임.
        public static int Foo()
        {
            Console.WriteLine("1"); return 10;
            Console.WriteLine("2"); return 20;
            Console.WriteLine("3"); return 30;
            Console.WriteLine("4"); return 40;
            Console.WriteLine("5"); return 50;
        }

        // 코루틴 - 열거자 타입으로 반환하는 경우
        public static IEnumerator<int> Goo()
        {
            Console.WriteLine("1"); yield return 10;
            Console.WriteLine("2"); yield return 20;
            Console.WriteLine("3"); yield return 30;
            Console.WriteLine("4"); yield return 40;
            Console.WriteLine("5"); yield return 50;
        } 
        
        // 코루틴 - 컬렉션 인터페이스 타입으로 반환하는 경우
        public static IEnumerable<int> Hoo()
        {
            Console.WriteLine("1"); yield return 10;
            Console.WriteLine("2"); yield return 20;
            Console.WriteLine("3"); yield return 30;
            Console.WriteLine("4"); yield return 40;
            Console.WriteLine("5"); yield return 50;
        }

        static void Main()
        {
            // 일반 메소드 호출
            int n1 = Foo();
            int n2 = Foo();
            Console.WriteLine($"{n1}, {n2}"); // 10 10




            // 코루틴 메소드 호출 : 열거자 타입
            // 1. 메소드 호출 후 열거자 참조 얻기
            IEnumerator<int> e = Goo();
            // 2. MoveNext() 호출 : 첫 호출이면 초기화
            e.MoveNext();
            // 3. Current로 반환값 사용
            int ret1 = e.Current;
            e.MoveNext();
            int ret2 = e.Current;

            Console.WriteLine($"{ret1}, {ret2}"); // 10 20




            // 코루틴 메소드 호출 : 인터페이스 타입
            // 1. 컬렉션 인터페이스 타입을 받아온다.
            IEnumerable<int> c = Hoo();
            // 2. 컬렉션 인터페이스에는 GetEnumerator() 메소드가 포함되어 있다.
            // 고로 열거자를 얻어온다.
            IEnumerator<int> e2 = c.GetEnumerator();
            e2.MoveNext();
            int ret3 = e2.Current;
            e2.MoveNext();
            int ret4 = e2.Current;

            Console.WriteLine($"{ret3}, {ret4}"); // 10 20

            Console.Read();
        }
    }
}
