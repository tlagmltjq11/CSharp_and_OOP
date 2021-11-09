using System;

// 핵심
// 1. 예외 필터링을 통해서 로깅을 만드는 기법
// Foo()에서 로그를 출력하고 로그는 false만 반환하기 때문에 캐치내부로 진입하지 못한다.
// 결국 에러는 Main에서 잡히게 된다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class Server
    {
        public void Connect()
        {
            throw new TimeoutException();
        }
    }

    class exception_filter2
    {
        static void Foo()
        {
            Server wc = new Server();

            try
            {
                wc.Connect();
            }
            // 실제로 예외를 잡으려고 만든 것이 아닌 로깅만 하기 위한 기법
            catch (Exception e) when (Logging(e))
            {
                Console.WriteLine("Foo Catch");
            }
        }

        static bool Logging(Exception e)
        {
            Console.WriteLine($"LOG : {e.Message}");
            return false;
        }

        static void Main()
        {
            try
            {
                Foo();
            }
            catch (Exception e)
            {
                Console.WriteLine("예외처리");
            }
        }
    }
}
