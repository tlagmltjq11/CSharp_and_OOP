using System;
using System.Net;

// 핵심
// 1. Library 메소드들은 정의로 이동을 해보면 처리해야 할 Exception들이 나와있다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class catch1
    {
        static void Main()
        {
            WebClient wc = new WebClient();

            string s = wc.DownloadString("http:\\www.naver.com");

            Console.WriteLine(s);
        }
    }
}
