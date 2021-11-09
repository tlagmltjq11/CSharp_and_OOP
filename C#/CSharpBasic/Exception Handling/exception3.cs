using System;

// 핵심
// 1. Out 파라미터를 활용해 오류를 전달하는 방식
// -> 메소드는 bool을 반환해 성공/실패만 나타내고
// -> 연산의 수행 결과는 Out 파라미터를 사용하는 방식이다.

// 장점
// 2. exception2.cs 코드와 다르게 반환값의 모호성이 사라진다!!! -> 성공/실패 여부와 반환값이 분리되어있기 때문이다.
// 3. 메소드의 반환값을 int나 여러 객체를 사용하면 오류에 대한 세부적인 정보를 전달할 수 있다.

// 단점
// 4. 하지만 여전히 실패를 처리하도록 강제할 수 없다. -> 오류처리 부분을 사용자가 빼먹을 수 있다.
// 5. 정상적인 흐름의 코드와 오류를 처리하는 코드가 분리되지 않는다.

// 6. C#에서 Try.. 로 시작하는 메소드가 해당 방식을 많이 사용한다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class FileManager
    {
        public static bool CopyFile(string srcFileName, string dstFileName, out int len)
        {
            // .....

            len = 100; // 결과값을 담는다.
            return false; // 성공여부를 반환한다.
        }
    }


    class exception3
    {
        static void Main()
        {
            int len;
            bool ret = FileManager.CopyFile("파일경로1", "파일경로2", out len);

            if (ret == false)
            {
                //.. error 처리
            }
        }
    }
}
