using System;

// 핵심
// 1. Foo에서 예외에 대한 처리를 이미 했지만, 예외의 사실을 Main까지 넘기고 싶다면
// 혹은 Main에게 떠넘기고 싶다면 rethrow 방식을 사용하면 된다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class Server
    {
        public void Connect()
        {
            throw new TimeoutException();
        }
    }

    class rethrow
    {
        static void Foo()
        {
            Server wc = new Server();

            try
            {
                wc.Connect();
            }
            catch(TimeoutException e)
            {
                // ... 접속 실패 처리
                // throw e; // 해당 방식으로 rethrow 하면 Connect 부분이 콜스택에 포함되지 않는다.
                throw; // 좋은 표기법 - 예외의 근원지까지 StackTrace에 포함된다.
            }
        }

        static void Main()
        {
            try
            {
                Foo();
            }
            catch(Exception e)
            {
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
