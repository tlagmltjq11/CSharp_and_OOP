using System;
using System.Net;

// 핵심
// 1. 예외가 발생했을때 catch구문을 위에서부터 순차적으로 체크하기 때문에
// Exception이 맨 위에 존재한다면 모든 에러를 잡아버려 하위의 catch 구문으로 갈 수 없다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class catch2
    {
        static void Main()
        {
            try
            {
                WebClient wc = new WebClient();
                string s = wc.DownloadString("http:\\www.naver.com");
                Console.WriteLine(s);
            }
            catch
            {

            }

            /* 각각의 에러를 따로 처리하는 방법
            catch(ArgumentNullException e)
            {

            }
            catch (WebException e)
            {

            }
            catch (NotSupportedException e)
            {

            }
            */

            /* 모든 에러를 한번에 처리하는 방법
            catch(Exception e)
            {

            }
            */

            /* 특정 에러만 따로 처리하는 방법
            catch (WebException e)
            {

            }
            catch (Exception e)
            {

            }
            */

            /* 특정 에러만 따로 처리하는 방법의 잘못된 예제
            // Exception이 가장 위에 존재하면 모든 에러를 다 잡아버린다.
            catch (Exception e)
            {

            }
            catch (WebException e)
            {

            }
            */
        }
    }
}