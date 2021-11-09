using System;

// 핵심
// 1. catch 구문에 들어가는 과정이 성능을 떨어뜨리기 때문에 최소로 해야한다.
// 이때 필터링을 사용하면 적어도 rethrow 하기 위해 들어가는 한번을 덜 들어가게 할 수 있다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class Server
    {
        public void Connect()
        {
            throw new TimeoutException();
        }
    }

    class exception_filter3
    {
        static void Foo()
        {
            int retryCount = 0;
            bool bSuccess = false;

            Server wc = new Server();

            while(bSuccess == false)
            {
                try
                {
                    wc.Connect();
                    bSuccess = true;
                }
                // 필터링에서 걸려서 에러를 캐치하지 않기 때문에 에러가 Main으로 넘어간다.
                catch (TimeoutException e) when(++retryCount < 4) 
                {
                    Console.WriteLine("One More Try");
                }

                // 아래 코드를 위처럼 필터링을 사용해 간결하고 효율적으로 사용할 수 있다.
                /*
                catch (TimeoutException e)
                {
                    if (++retryCount < 4)
                    {
                        Console.WriteLine("One More Try");
                    }
                    else
                    {
                        throw;
                    }
                }
                */
            }
        }

        static void Main()
        {
            try
            {
                Foo();
            }
            catch (Exception e)
            {
                Console.WriteLine("Main 예외처리");
            }

            Console.Read();
        }
    }
}
