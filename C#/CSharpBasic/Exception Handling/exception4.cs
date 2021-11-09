using System;

// 핵심
// 1. throw 키워드를 사용해서 예외를 던지는 방식

// 장점
// 2. 오류의 전달과 메소드의 반환 값이 완전히 분리된다.
// 3. Exception 클래스의 다양한 속성과 메소드를 이용해서 오류에 대한 다양한 정보를 전달할 수 있다.
// 4. 예외를 무조건 처리하게끔 강제할 수 있다.
// 5. 정상적인 흐름의 코드와 오류 처리를 위한 코드를 분리 할 수 있다.



// 관례
// 중요하지 않은 사소한 오류 : 메소드의 반환 값으로 간단하게 처리
// 중요한 오류 : 예외처리

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class FileManager
    {
        public static int CopyFile(string srcFileName, string dstFileName)
        {
            // .....

            if(true)
            {
                throw new Exception("파일 접근 권한 없음");
            }

            return 100;
        }
    }


    class exception4
    {
        static void Main()
        {
            // 100% 성공을 가정하고 정상적인 흐름의 코드를 모아 둘 수 있다.
            try
            {
                FileManager.CopyFile("파일경로1", "파일경로2");

                // 정상 코드와 오류 처리 코드가 분리되었기 때문에 정상적인 흐름을 계속해서 진행 할 수 있다.
                Console.WriteLine("기존파일삭제");
                Console.WriteLine("신규파일오픈");

            }
            // 오류의 처리 부분을 모아 둘 수 있다.
            catch(Exception e)
            {
                Console.WriteLine(e.Message);
            }

            Console.WriteLine("프로그램은 죽지않고 계속해서 실행 중");
        }
    }
}
