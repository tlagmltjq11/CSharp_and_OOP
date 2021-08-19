## Exception Handling
어떠한 수를 0으로 나눈다던가, 음수의 제곱근을 구하는 경우라던가, 어떤 인수의 값이 텅텅 비어있던가 등 논리적으로 어긋난 상황에 마주치면 프로그램은 어김없이 예외를 내보내고 프로그램이 종료되어버릴 것입니다.
이러한 예외 발생으로 프로그램이 종료되는 것을 막기위해 예외를 처리하는 것을 '예외 처리(Exception handling)이라고 합니다. 이제 앞으로 배울 try~catch문을 이용하여 예외를 우리가 받아 처리할 수 있습니다.


예외 처리에 쓰이는 try문과 catch는 언제나 함께 붙어다니는 녀석들입니다. try문 내의 코드에서 예외가 발생하면 catch문이 예외를 잡아 처리합니다. 아래는 try~catch문의 기본 형식입니다.

try
{
    // ...
}
catch (Exception e)
{
    // 예외 발생 시 처리부분
}

try 내에서 코드를 작성하고 만약 프로그램을 실행했는데, 그 코드에서 예외가 발생하면 catch가 그 예외를 잡아서 처리하여 줍니다. 한가지 더 알아두셔야 할게 있는데, catch문은 하나만 쓰이는게 아닌 두개 이상이 올 수 있습니다. 그러면, 한번 나눈 결과를 반환하는 메소드를 정의하고, 두번째 인자값에 0을 넣어보도록 해봅시다. 그리고 0으로 나눌때 DivideByZeroException 예외를 잡아 처리하여 프로그램이 비정상 종료되는것을 해결해봅시다.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication35
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(Division(5, 0));
            Console.WriteLine(Division(10, 2));
            Console.WriteLine(Division(49, 7));
        }

        static int Division(int a, int b)
        {
            try
            {
                return a / b;
            }
            catch (DivideByZeroException e)
            {
                Console.WriteLine(e.Message);
                return -1;
            }
        }
    }
}

결과:

0으로 나누려 했습니다.

-1

5

7

계속하려면 아무 키나 누르십시오 . . .



코드를 보시면 13~15행에서 Division 메소드가 3번 호출되었습니다. 그런데 2, 3번째는 문제없이 출력될 것 같은데, 1번째를 보니 5를 0으로 나누는 코드가 등장합니다. Division 메소드를 한번 보시면 메소드 내에 try~catch문이 쓰였다는 것을 알 수 있습니다. 예를 들어서, a에 4가 b에 0이 들어왔다고 해봅시다. 그 후에 a를 b로 나누고 결과값을 출력하는 코드를 만나 4를 0으로 나누려고 합니다. 그러면 어떠한 수를 0으로 나눌수는 없기에 예외를 발생시키는데 catch문이 이것을 잡아 예외가 발생한 이유를 출력하고 -1를 리턴합니다. 참고로 발생한 예외에 대한 처리 부분이 없다면, 예외를 처리하지 못해 프로그램은 비정상 종료됩니다. (만약에 DivideByZeroException(0으로 나눌 경우) 객체가 아닌 IndexOutOfRangeException(배열 범위를 벗어날 경우) 객체를 사용했다면 예외를 처리하지 못합니다)



3. finally



finally 블럭은 try 블럭 내에서 예외가 발생하던 말던 마지막에 무조건 실행되는 영역입니다. 이 영역에는 자원을 해제하는 용도로, 열려 있는 파일 등을 닫을때 사용됩니다. finally의 사용 형식은 아래와 같습니다.

try
{
   // ...
}
catch (Exception e)
{
   // ...
}
finally 
{
   // 반드시 실행되는 코드
}
아래는 finally문에 관한 예제입니다. 파일을 Open하여, A에 있는 내용을 B에 한줄한줄 적는 코드입니다.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading.Tasks;

namespace ConsoleApplication35
{
    class ClassFinally
    {
        public static void Main()
        {
            StreamReader sreader = null;
            StreamWriter swriter = null;

            try
            {
                sreader = new StreamReader(File.Open("A.txt", FileMode.Open));
                swriter = new StreamWriter(File.Open("B.txt", FileMode.Append, FileAccess.Write));

                while (sreader.Peek() != -1)
                {
                    swriter.WriteLine(sreader.ReadLine());
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                if (sreader != null) sreader.Close();
                if (swriter != null) swriter.Close();
            }
        }
    }
}
이 코드 내에서 파일이 열려있는 상태에서 예기치 않은 상황이 벌어진다면 메세지를 띄우고 finally 영역에 의해 파일이 닫힙니다. 



4. throw



throw는 예외를 던지는 역할을 하는 키워드입니다. 자세히 말하자면, throw는 상위 호출 메소드로 Exception 객체를 전달하는데에 쓰입니다. throw는 try~catch 내에서 사용될 수 있지만, 독립적으로 쓰일 수도 있습니다.

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication35
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                Console.WriteLine(Division(10, 2));
                Console.WriteLine(Division(49, 7));
                Console.WriteLine(Division(5, -1));
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static int Division(int a, int b)
        {
            if (a <= 0 || b <= 0)
                throw new Exception("0 또는 음수가 오는 것을 허용하지 않습니다.");
            else
                return a / b;
        }
    }
}
결과:

5

7

0 또는 음수가 오는 것을 허용하지 않습니다.

계속하려면 아무 키나 누르십시오 . . .



코드의 27~28행을 보시면 a 또는 b가 0과 같거나 0보다 작으면 throw 키워드로 인해 예외를 던집니다. 그 뒤에, 상위 호출 메소드에서 예외를 받아 처리합니다. 17행의 코드에서 예외가 발생하므로 17행은 실행되지 않습니다.



이번 강좌는 여기서 마치도록 하겠습니다. 수고하셨습니다.

 .NET의 System.Exception은 모든 Exception의 Base 클래스이며, 예외 처리는 이 Exception 객체를 기본으로 처리하게 된다.



섬세한 예외 처리가 필요한 겨우 Exception 클래스를 마구 남용해선 안된다.
익셉션 형식은 프로그래머가 발생할 것으로 계산한 예외 말고도 다른 예외까지 받아낼 수 있기 때문이다.
그 예외가 현재 코드가아닌 상위 코드에서 처리해야할 예외라면 이코드는 버그를 만들고 있는 셈이 되므로
남용해선 안된다.
throw 관련 추가

https://1q1w.github.io/c%23%20basic/csharp_exception/ 사용자 정의 예외 클래스 예제

https://www.csharpstudy.com/CSharp/CSharp-exception.aspx
https://mandy8303.tistory.com/18
출처: https://blog.hexabrain.net/149 [끝나지 않는 프로그래밍 일기]
