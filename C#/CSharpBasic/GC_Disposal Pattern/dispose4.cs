using System;
using System.IO;

// 핵심
// 1. Dispose를 사용하지 않으면 파일이 언제 닫히거나 반납될지 알 수 없기 때문에
// 예제와 같이 파일에 접근할 수 없는 경우 등이 생기게 된다.
// 고로 Disposal Pattern을 사용해 주어야 한다.

// 2. Using문을 사용하는게 제일 간편하다.

// 헷갈렸던 부분이 알고있기로 Unmanaged Resource는 GC의 대상이 아니기 때문에
// 직접 릴리즈 해주지 않으면 안되는 것으로 알았는데..
// 결국 언젠가는 GC에 의해 소멸자가 호출되어 (이때 소멸자 내부에서 Dispose를 호출해줌) 
// 해제가 된다는 점이다. 알아보자!!

// -> 추측하기로 Unmanaged Resource 객체 자체는 GC의 대상이기 때문에
// 언젠가는 수거되어 소멸자를 호출당할 것 같다. 그래서 호출자 내부에서 Dispose가
// 호출되어 자원이 반납되지 않을까 생각한다.

namespace CSHARP.CSharpBasic.GC_Disposal_Pattern
{
    class dispose4
    {
        public static void Foo()
        {
            FileStream fs1 = new FileStream("a.txt", FileMode.OpenOrCreate,
                FileAccess.ReadWrite, FileShare.None);

            // 최종 해결법
            fs1.Dispose(); // Dispose 호출 시 곧바로 파일이 닫히며 자원이 반납된다.
            // 호출 안해도 언젠간 소멸자가 호출되어 닫힐것이지만 그 시기를 알 수 없다.
        }

        static void Main()
        {
            Foo();

            // 해결법 : 아래 문제를 해결하기 위해 강제로 소멸자를 호출해 파일을 닫아주는 것.
            // 정말 좋지 않은 코드이다.
            GC.Collect();
            GC.WaitForPendingFinalizers();

            Console.WriteLine("Finish Foo");

            // ★ Foo() 내에서 "a.txt"를 열어서 사용했는데 수집되지않아 파일이 닫히지 않은 상태이므로
            // (정확히는 파일을 닫는 코드는 소멸자에 있어서 소멸자가 호출되지 않았기 때문이다.)
            // ★ 아래 코드에서 파일이 이미 다른 프로세스에서 사용중이라며 에러를 뿜는다.
            FileStream fs2 = new FileStream("a.txt", FileMode.Open, FileAccess.ReadWrite,
                FileShare.None);
        }
    }
}
