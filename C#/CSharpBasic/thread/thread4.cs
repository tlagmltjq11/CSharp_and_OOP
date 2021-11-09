using System;
using System.Threading;

// 핵심
// 1. ManagedThreadId, Priority, IsThreadPoolThread, IsAlive
// 2. IsBackground, Join()
// 3. Thread.CurrentThread

namespace CSHARP.CSharpBasic.thread
{
    class thread4
    {
        public static void F1()
        {
            Thread t = Thread.CurrentThread; // 스레드내에서 자신의 스레드 객체를 얻어오는 방법
            // 얻어왔으니 여러 속성값을 확인할 수 있다.

            Console.WriteLine("F1 Start");
            Thread.Sleep(1000);
            Console.WriteLine("F1 End");
        }

        static void Main()
        {
            Thread t1 = new Thread(F1); 
            t1.Start();

            Console.WriteLine($"{t1.ManagedThreadId}"); // 스레드의 고유 ID
            Console.WriteLine($"{t1.Priority}"); // 우선순위 - 변경하지않으면 Normal
            Console.WriteLine($"{t1.IsThreadPoolThread}"); // 스레드풀에 있는 스레드인가 조사 - Task로 만들었느냐 아니냐와 동일하다.
            Console.WriteLine($"{t1.IsAlive}"); // 현재 살아있는지 체크

            t1.IsBackground = true; // 메인스레드가 종료되면 새로운 스레드가 강제로 종료된다.
            // 고로 메인스레드가 종료되어도 계속 작업을 하도록 설정해줘야 한다.
            // Foreground 스레드 : 메인스레드가 종료 되어도 계속 작업 수행
            // Background 스레드 : 메인스레드가 종료 되면 강제 종료

            t1.Join(); // 메인스레드가 t1 스레드가 종료될때까지 종료하게끔 유도하는 기능

            Console.Read();
        }
    }
}
