## 🔔 NameSpace

![네임스페이스](https://user-images.githubusercontent.com/43705434/130056997-999740e4-fd2b-446f-abd2-2582ab471075.PNG)<br>
<br>

네임스페이스란 ⭐ **Type들을 필드로 갖는 큰 영역의 틀** ⭐ 이라고 생각하면 좋다.<br>
A클래스에 int a;를 선언하고, B클래스에 int a;를 선언해서 사용할 수 있는 것 처럼<br>
**네임스페이스가 다르다면 동일한 이름의 Type을 선언해서 사용할 수 있게된다.**<br>
이러한 네임스페이스를 사용하는 이유는 **수많은 Type들의 이름을 충돌없이 보다 편리하게 사용하기 위해서** ⭐ 사용되며<br>
또한 **유사한 클래스들을 그룹 짓기 위해서도 사용한다.** ⭐<br>
비록 클래스가 네임스페이스 없이도 정의 될 수는 있지만, 거의 모든 경우 네임스페이스를 정의하는 것이 일반적이다.<br>
(c#에는 헤더파일이 따로 존재하지 않음)<br>
<br>
<br>

👉 **사용법**<br>
네임스페이스를 사용하기 위해서는 두가지 방식이 있다.<br>

* 첫째는 클래스명 앞에 네임스페이스 전부를 적는 경우와<br>

* 둘째는 프로그램 맨 윗단에 해당 using을 사용하여<br>
C# (.cs) 파일에서 사용하고자 하는 네임스페이스를 한번 설정해 주고,<br>
이후 해당 파일 내에서 네임스페이스 없이 직접 클래스를 사용하는 경우이다.<br>
실무에서는 주로 두번째 방식을 사용한다.<br>
<br>

```c#
//첫번째 방식
static void Main(string[] args)
{
    System.Console.WriteLine();
}

//두번째 방식
using System; //System 네임스페이스 지정

static void Main(string[] args)
{
    Console.WriteLine();
}
```
<br>
<br>

네임스페이스 내에 네임스페이스를 정의하는것도 가능하며<br>
만약 두 네임스페이스에 동일한 클래스를 선언하고 전혀 다른 제3의 네임스페이스에서<br>
다음과 같이 사용하게되면 모호성 에러가 발생할 수 있다.<br>

```c#
        // 두개의 네임스페이스를 모두 using 키워드로 선언한다.
        using Ex1;
        using Ex2;
 
        class TipsExam
        {
            static void Main(string[] args)
            {
                // 모호성 에러 발생
                Exam exam = new Exam();
                exam.Test();
            }
        }
 
        namespace Ex1
        {
            class Exam
            {
                public void Test()
                {
                    System.Console.WriteLine("Ex1 - Hello World");
                }
            }
        }
 
        namespace Ex2
        {
            class Exam
            {
                public void Test()
                {
                    System.Console.WriteLine("Ex2 - Hello World");
                }
            }
        }
```
<br>
<br>

## 🔔 참조링크
http://xamarin.woobi.co.kr/CSharp/Grammar.htm <br>
