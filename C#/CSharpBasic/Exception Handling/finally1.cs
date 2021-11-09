using System;

// 핵심
// 1. finally 구문은 try 블록을 벗어나기만하면 무조건 실행된다.
// -> catch 구문은 try 안에서 예외가 발생해야만 실행된다.

// 메모리 자원 등을 반납할때 finally를 자주 사용한다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class finally1
    {
        static void Main()
        {
            //return; //try 블록에도 갈 수 없으므로 finally가 실행되지 않는다.

            try
            {
                throw new Exception();
            }
            catch(Exception e)
            {
                Console.WriteLine("Catch");
            }
            finally
            {
                Console.WriteLine("Finally");
            }
        }
    }
}
