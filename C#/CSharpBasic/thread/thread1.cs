using System;
using System.Threading;

// 핵심
// 1. 프로세스 내에서 하나의 실행의 흐름을 쓰레드라고 한다. (프로세스 내 작업단위)
// 프로세스 내에서 여러가지 일을 동시에 하고 싶다면 멀티스레딩을 사용하면 된다.


namespace CSHARP.CSharpBasic.thread
{
    class thread1
    {
        public static void Foo()
        {
            Console.WriteLine("Foo Start");
            Thread.Sleep(10000);
            Console.WriteLine("Foo End");
        }

        static void Main()
        {
            Foo();
        }
    }
}
