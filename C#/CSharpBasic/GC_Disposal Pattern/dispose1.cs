using System;
using System.IO;

// 핵심
// 1. Unmanaged Resource 같은 경우 GC의 수거 대상이 아니기 때문에 명시적으로 반납을 해야한다.
// -> Disposal Pattern을 사용해서 반납하도록 한다.

namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class dispose1
    {
        static void Main()
        {
            int[] arr = new int[5] { 1, 2, 3, 4, 5 };

            FileStream fs = new FileStream("a.txt",
                FileMode.CreateNew,
                FileAccess.ReadWrite,
                FileShare.None);

            // .... working ....

            fs.Dispose();
        }
    }
}
