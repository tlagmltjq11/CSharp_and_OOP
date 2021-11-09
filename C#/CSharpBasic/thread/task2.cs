using System;
using System.Threading;
using System.Threading.Tasks;

// 핵심
// Task 사용 Tip
// 1. t.Wait()을 사용해서 종료를 대기할 수 있다. 디폴트가 백그라운드 수행이다 !!
// 2. Run() 메소드는 인자없는 메소드만 받을 수 있어서 람다식을 사용해야 한다.
// 3. t.IsCompleted 스레드가 작업중인지 끝났는지 체크하는 속성
// 4. 만약 메소드가 반환값이 있다면 제네릭을 사용해주어야 받을 수 있다.
// -> Task<int> t ...
// 5. t.Result 즉 태스크의 반환값은 메소드로부터 반환값이 올때까지 해당 스레드를 대기시킨다.(wait)

namespace CSHARP.CSharpBasic.thread
{
    class task2
    {
        public static void F1()
        {
            Console.WriteLine("F1 Start");
            Thread.Sleep(1000);
            Console.WriteLine("F1 End");
        }

        //public static void F1(object obj)
        //{
        //    Console.WriteLine("F1 Start");
        //    Thread.Sleep(1000);
        //    Console.WriteLine("F1 End");
        //}

        public static int F1(object obj)
        {
            Console.WriteLine("F1 Start");
            Thread.Sleep(1000);
            Console.WriteLine("F1 End");

            return 100;
        }

        static void Main()
        {
            //Task t = Task.Run(F1); // 디폴트가 백그라운드 수행이라서 위 출력문이 나오지 않는다.
            //t.Wait(); // 고로 wait을 사용해서 종료를 대기하도록 해야 한다.



            //Task t = Task.Run(() => F1("hello")); // Run 메소드는 인자없는 메소드만 받을 수 있어서 람다식을 사용해야 한다.

            //Console.WriteLine(t.IsCompleted); // 스레드가 살아있는지 즉 현재 작업중인지 체크하는 속성
            //t.Wait();
            //Console.WriteLine(t.IsCompleted);



            Task<int> t = Task.Run(() => F1("hello")); // 만약 메소드가 반환값이 있다면 제네릭을 사용해주어야 받을 수 있다.

            Console.WriteLine("AAA");
            Console.WriteLine(t.Result); // F1이 아직 안끝나서 반환하지 못했을 수도 있으니 현재 상태에서 메인스레드는 대기한다.
            Console.WriteLine("BBB");
        }
    }
}
