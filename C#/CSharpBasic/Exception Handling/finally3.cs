using System;
using System.IO;

// 핵심
// 1. 자원 반납에 대해서 finally2.cs 와 같이 너무나도 많이 사용하기 때문에
// -> c#에서는 using 구문을 통해서 간편하게 사용할 수 있도록 축약 표기법을 제공한다.

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class finally3
    {
        static void Main()
        {
            using (FileStream fs = new FileStream("a.txt", FileMode.CreateNew))
            {
                try
                {
                    // .....
                }
                catch(Exception e)
                {

                }
            }

            // 위 using문은 결국 아래와 같은 코드로 변환되는 것이다. !!!
            /*
            FileStream fs = new FileStream("a.txt", FileMode.CreateNew);
            try
            {
                fs = new FileStream("a.txt", FileMode.CreateNew);

            }
            finally
            {
                if (fs != null)
                {
                    fs.Dispose();
                }
            }
            */
        }
    }
}
