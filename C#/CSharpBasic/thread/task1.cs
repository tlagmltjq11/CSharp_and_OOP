using System;
using System.Threading;
using System.Threading.Tasks;

// 핵심
// 1. Task를 통해서 메소드를 호출하면 스레드 풀내에 존재하는 스레드를 통해서 작업을 수행하기 때문에
// -> ★ 즉 쓰레드 풀 방식으로 처리하기 때문에 오버헤드를 줄일 수 있다.

// 스레드의 생성/파괴에는 많은 시간이 필요하다.
// 몇개를 만들것인가에 대한 고민이 생긴다.
// 생성/파괴 하지말고
// 미리 만들어 놓고 재웠다/깨웠다를 하자. - 스레드 풀링

namespace CSHARP.CSharpBasic.thread
{
    class task1
    {
        public static void Foo()
        {
            Console.WriteLine($"Foo : {Thread.CurrentThread.ManagedThreadId}");
            Thread.Sleep(3000);
        }

        static void Main()
        {
            //Thread t = new Thread(Foo);
            //t.Start();

            // 아래는 위 코드와 동일하다. 메소드를 새로운 스레드에게 호출해달라는 의미이다.
            // 그렇다면 차이점은?  
            //Task t = Task.Run();

            // cpu가 듀얼코어라면 정말 동시에 실행되는것은 2개 뿐이다.
            // 20개의 스레드를 돌리기위해 계속해서 스위칭이 일어날텐데 이는 ★ 성능저하다
            //for (int i = 0; i < 20; i++)
            //{
            //    Thread t = new Thread(Foo);
            //    t.Start();
            //}

            // 고로 스레드로 수행시키고 싶은 작업이 있다면 잠깐 큐에 대기하도록 하고
            // 자신의 작업을 모두 끝낸 기존 스레드가 해당 작업을 도맡아 수행하는것이 효율적이다.
            // 결국 쓰레드 풀을 사용하라는 의미이다. Task를 통해 메소드를 호출하면
            // ★ 자동으로 스레드 풀에있는 스레드를 사용해서 메소드를 수행한다.
            // 즉 스레드 풀을 자동으로 사용하게 되는 것.
            for (int i = 0; i < 20; i++)
            {
                Task t = Task.Run();
            }

            Console.ReadKey();
        }
    }
}
