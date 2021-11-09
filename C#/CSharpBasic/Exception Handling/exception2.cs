using System;

// 핵심
// 1. 반환값을 사용해서 오류를 전달하는 방식
// -> 반환값과 오류가 모호할 수 있다.
// -> -1이 실제 연산의 결과값인지 오류를 나타내는 값인지 모호하다.

// 2. 오류에 대한 자세한 정보를 알려줄 수 없다.
// -> 단순히 음수값으로 오류의 발생만 알릴 수 있다.

// 3. 사용자가 함수 실패를 반드시 처리하도록 강제할 수 없다.
// -> 음수값을 반환해도 사용자가 음수값에 대한 처리를 안할 수 있다.

// 4. 정상적인 흐름의 코드와 오류를 처리하는 코드가 분리되지 않고 섞여 있다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class FileManager
    {
        // 해당 작업은 성공햇을 때 항상 0보다 클 것이다. (파일 길이)
        // 하지만 -1 자체가 연산의 결과인 경우도 있을 수 있어 모호하다.
        public static int CopyFile(string srcFileName, string dstFileName)
        {
            // .....

            return -1; // 실패 시 음수 반환
        }
    }


    class exception2
    {
        static void Main()
        {
            int ret = FileManager.CopyFile("파일경로1", "파일경로2");

            if(ret < 0)
            {
                //.. error 처리
            }
        }
    }
}