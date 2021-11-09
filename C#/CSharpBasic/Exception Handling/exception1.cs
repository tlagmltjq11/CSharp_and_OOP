using System;

// 핵심
// 1. 파일을 복사하는 작업은 항상 성공하는 것이 아니라 실패할 수도 있다.

// 2. 어떤 작업을 실패했을 때 처리법 3가지
// 1) 반환값을 사용해서 오류를 전달
// 2) Out 파라미터를 사용해서 전달
// 3) 예외를 사용하는 방법

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class FileManager
    {
        public static int CopyFile(string srcFileName, string dstFileName)
        {
            // .....

            return 100;
        }
    }


    class exception1
    {
        static void Main()
        {
            FileManager.CopyFile("파일경로1", "파일경로2");
        }
    }
}
