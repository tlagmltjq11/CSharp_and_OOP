using System;
using System.Threading;

// 핵심
// 1. Thread의 생성자는 4가지가 존재한다.
// 매개변수가 없는 Delegate를 인자로 받는 생성자
// 매개변수가 없는 Delegate와 maxStackSize를 인자로 받는 생성자
// 매개변수가 있는 Delegate를 인자로 받는 생성자
// 매개변수가 있는 Delegate와 maxStaclSize를 인자로 받는 생성자

// 단 매개변수가 있는 Delegate는 모두 Object형 인자를 받기 때문에 주의해야 한다.
// 만약 Object형이 아닌 인자를 넘겨주거나, 여러개의 인자를 넘겨주고 싶다면
// ★ -> 람다식을 통해서 넘겨주어야 한다.
// 스레드는 람다 표현식을 실행하고, 람다 표현식에서 스레드 함수 호출

namespace CSHARP.CSharpBasic.thread
{
    class thread3
    {
        public static void F1() { } // 매개변수가 없는 메소드
        public static void F2(object obj) { } // Object를 인자로 받는 메소드
        public static void F3(string s1) { } // string을 인자로 받는 메소드
        public static void F4(string s1, int n) { } // 인자가 여러개인 메소드

        static void Main()
        {
            Thread t1 = new Thread(F1); // 매개변수가 없는 경우
            t1.Start();

            Thread t2 = new Thread(F2); // 매개변수가 obj인 경우
            t2.Start("hello");

            // 람다식 예제
            Thread t3 = new Thread(() => F3("hello")); // obj가 아닌 매개변수를 넘기는 경우 
            t3.Start();

            Thread t4 = new Thread(() => F4("hello", 5)); // 매개변수가 여러개인 경우
            t4.Start();
        }
    }
}