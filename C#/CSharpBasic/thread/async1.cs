using System;
using System.Threading;
using System.Threading.Tasks;

class Program
{
    public static int Sum(int first, int last)
    {
        int s = 0;
        for (int i = first; i <= last; i++)
        {
            s += i;
            Thread.Sleep(10); // 복잡한 연산이라는 의미로 시간지연
        }
        return s;
    }

    public static Task<int> SumAsync(int first, int last)
    {
        return Task.Run(() => Sum(1, 200));
    }

    public static void Main()
    {
        int ret = Sum(1, 200); // 동기호출 : sum이 값을 뱉기전까지 멈춰있음.

        //아래 코드는 task1에 있는것과 동일한 표현식임
        Task<int> t = Task.Run(() => Sum(1, 200)); // 스레드로 수행 : 비동기 호출

        //위 코드 대신 SumAsync를 만들었다.
        Task<int> t2 = SumAsync(1, 200); // 역시나 비동기 호출

        int n = t2.Result;
    }

}