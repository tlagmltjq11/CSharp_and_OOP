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
        Task<int> t = SumAsync(1, 200); // 스레드로 실행되므로 block 되지 않는다.

        // 스레드로 실행한 결과를 화면에 출력하고 싶다고 생각해보자.
        Console.WriteLine($"{t.Result}"); // 그런데, 여기서 결과를 기다릴때 block 된다. !!!
                                          // 결국, blocking 없이 대기 하려면
                                          // 대기 자체를 새로운 스레드로 해야 한다.!!!
    }

    public static void Main()
    {
        UpdateResult();

        Console.WriteLine("Main : Run Event Loop");
        Console.ReadLine();
    }
}