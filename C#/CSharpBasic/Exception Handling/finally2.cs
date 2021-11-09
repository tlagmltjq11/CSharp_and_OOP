using System;
using System.IO;

// 핵심
// 1. 자원 반납

namespace CSHARP.CSharpBasic.ExceptionHandling
{
    class finally2
    {
        static void Main()
        {
            FileStream fs = null;

            try
            {
                fs = new FileStream("a.txt", FileMode.CreateNew);

                // .....

                //fs.Dispose();

            }
            catch(Exception e)
            {
                //fs.Dispose();
            }
            finally
            {
                if(fs != null)
                {
                    fs.Dispose();
                }
            }
        }
    }
}