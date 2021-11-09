using System;

// 핵심
// 1. 모든 예외 클래스는 Exception으로 부터 파생된다.
// 주요 멤버
// Message : 예외를 설명하는 문자열
// StackTrace : 예외의 근원지 부터 catch 블록에 도달할 때 까지의 모든 메소드에 대한 정보
// 즉 StackTrace는 Call Stack을 나타내는 것이다.

// 2. 예외는 Call Stack의 모든 과정에서 처리할 수 있다.
// 즉 Goo에서 생성된 오류를 Foo 혹은 Main에서 처리할 수 있다는 것.
// 현재는 모든 콜스택 과정의 에러를 잡기위해 Main에서 캐치했다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class catch3
    {
        public static void Goo()
        {
            int[] arr = { 1, 2, 3 };
            arr[3] = 10; // error
        }

        public static void Foo()
        {
            Goo();
        }

        static void Main()
        {
            try
            {
                Foo();
            }
            catch(IndexOutOfRangeException e)
            {
                // 아래 두가지는 자체적으로 디폴트로 출력해주긴 한다.
                Console.WriteLine(e.Message);
                Console.WriteLine(e.StackTrace);
            }
        }
    }
}
