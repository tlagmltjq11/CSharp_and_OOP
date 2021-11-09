using System;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    // 아래 코드는 Run() 메소드 인자로 직접 구현한 것.
    public static Task<int> SumAsync(int first, int last)
    {
        // 아래 코드는 스레드로 실행된다.
        return Task.Run(() =>
        {
            int s = 0;
            for (int i = first; i <= last; i++)
            {
                s += i;
                Thread.Sleep(10);
            }

            return s;
        });
    }

    public static void UpdateResult()
    {
        Task<int> t = SumAsync(1, 200);

        // Task에서 awaiter 객체를 꺼냅니다.
        var awaiter = t.GetAwaiter();

        // 여기서 사용되는 스레드풀은 Task를 사용하면 자동으로 생성된다고 한다!!!

        // OnCompleted(코드) 에서 코드 부분은 새로운 스레드가 실행합니다.!!!
        awaiter.OnCompleted(() => Console.WriteLine($"{awaiter.GetResult()}"));
        // -> 주 스레드는 블락되지 않고 대기하던 스레드가 결과를 받아서 출력해줄 것이다.

        Console.WriteLine($"{t.Result}");
    }

    public static void Main()
    {
        UpdateResult();

        Console.WriteLine("Main : Run Event Loop");
        Console.ReadLine();
    }
}