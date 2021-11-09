using System;
using System.Threading;

// 핵심
// 1. C#에서 쓰레드를 생성하는 법
// 1) Thread 객체 생성
// 2) Start() 메소드 호출

namespace CSHARP.CSharpBasic.thread
{
    class thread2
    {
        public static void Foo()
        {
            Console.WriteLine("Foo Start");
            Thread.Sleep(2000); // 2초간 sleep
            Console.WriteLine("Foo End");
        }

        static void Main()
        {
            //Foo(); // 메인 스레드가 호출하는 것

            Thread t = new Thread(thread2.Foo); // 별도의 스레드가 호출하도록 하는 것
            t.Start();

            Console.WriteLine("Main Start");
            Thread.Sleep(2000);
            Console.WriteLine("Main End");

            Console.Read();
        }
    }
}
