using System;

// 핵심
// 1. 소멸자에서 자원을 반납해도 되지만 앞서 배웠듯이 가비지가 수집된다고 해서
// 곧바로 소멸자가 호출되는것이 아니다. 고로 호출되기 전까지 해당 자원은 계속 유지되고 있다.
// 소멸자의 오버헤드 또한 문제.

// -> ★ Dispose를 사용해소 곧바로 자원을 반납할 수 있도록 해야한다.

namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class XFileStream
    {
        private IntPtr handle;

        public XFileStream(string path)
        {
            // win32 API인 CreateFile()을 사용해서 파일 오픈
        }

        ~XFileStream()
        {
            // win32 API인 CloseHandle()을 사용해서 파일 닫기
        }

        public void Dispose()
        {

        }
    }

    class dispose3
    {
        static void Main()
        {
            XFileStream xfs = new XFileStream("a.txt");
            xfs.Dispose();
            xfs = null;
        }
    }
}
