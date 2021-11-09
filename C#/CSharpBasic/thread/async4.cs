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

    // c# 5.0에서 소개된 async/await 개념..
    // 8_async3에서 만들어둔 코드를 아래와 같이 줄일 수 있게됨.
    // 요즘 언어들이 핵심으로 지원하는 기술 !!
    // 3번의 GetAwaiter()를 사용하기 쉽게 한 것.
    public static async void UpdateResult()
    {
        /*
         주 스레드는 await를 만나면 새로운 스레드에게 
         하위 코드를 위임한다고 생각하면 된다.
         */
        Task<int> t = await SumAsync(1, 200);

        Console.WriteLine($"{t.Result}");
    }

    public static void Main()
    {
        UpdateResult();

        Console.WriteLine("Main : Run Event Loop");
        Console.ReadLine();
    }
}