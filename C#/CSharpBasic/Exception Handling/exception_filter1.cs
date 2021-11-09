using System;
using System.Net;

// 핵심
// 1. 특정 예외 중에서도 어떠한 이유로 예외가 발생한건지 분기 할 수 있다.
// if/else 문으로도 가능하지만 "예외 필터"라는 기능을 사용할 수 있다.
// -> 예외 필터는 when 키워드로 사용할 수 있다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class exception_filter1
    {
        static void Main()
        {
            WebClient wc = new WebClient();

            try
            {
                string s = wc.DownloadString("http:\\오타www.naver.com");
            }
            catch (WebException e) when (e.Status == WebExceptionStatus.NameResolutionFailure)
            {
                Console.WriteLine("URL이 잘못 표기되었습니다.");
            }
            catch (WebException e) when (e.Status == WebExceptionStatus.Timeout)
            {
                Console.WriteLine("시간 초과");
            }

            // 아래와 같이 작성해도 되지만 위 코드처럼 when 키워드를 통해 필터링 할 수 있다.
            /*
            catch(WebException e)
            {
                if(e.Status == WebExceptionStatus.NameResolutionFailure)
                {
                    Console.WriteLine("URL이 잘못 표기되었습니다.");
                }
                else if(e.Status == WebExceptionStatus.Timeout)
                {
                    Console.WriteLine("시간 초과");
                }
                else
                {
                    Console.WriteLine("다른 문제");
                }
            }
            */

            catch (Exception e)
            {

            }

            wc.Dispose();
        }
    }
}
