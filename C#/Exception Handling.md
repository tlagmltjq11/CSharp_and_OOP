## 🔔 Exception Handling
C#을 포함한 모든 .NET 프로그래밍 언어는 .NET Framework의 Exception 메커니즘에 따라 Exception을 처리한다.<br>
.NET의 **System.Exception은 모든 Exception의 Base 클래스이며** ⭐, 예외 처리는 이 Exception 객체를 기본으로 처리하게 된다.<br>
만약 Exception이 발생하였는데 이를 프로그램 내에서 **처리하지 않으면 프로그램은 Crash하여 종료하게 된다.** ⭐<br>

C#에서는 try, catch, finally라는 키워드를 사용하여 Exception을 핸들링하게 되며,<br>
또한 throw라는 C# 키워드를 통해 Exception을 만들어 던지거나 혹은 기존 Exception을 다시 던질 수 있다.<br>
<br>

```c#
try
{
   // 실행하고자 하는 문장들
   DoSomething();
}
catch (Exception ex)
{
   // 에러 처리/로깅 등
   Log(ex);
   throw;
}
```
<br>
<br>

## 🔔 try-catch-finally
**try 블럭**은 실제 실행하고 싶은 프로그램 **명령문들을 갖는 블럭**이다.<br>
만약 여기서 어떤 **에러가 발생하면**, 이는 **catch 문에서 잡히게 된다.**<br>
catch문은 모든 Exception을 일괄적으로 잡거나 혹은 **특정 Exception을 선별하여 잡을 수 있다.**<br>

**모든 Exception을 잡고 싶을 때는** catch { ... } 와 같이 하거나 catch (Exception ex) { ... }처럼<br>
모든 Exception의 **베이스 클래스인 System.Exception를 잡으면 된다.**<br>
**특정 Exception을 잡기 위해서는 해당 Exception Type을 catch하면 된다.**<br>
즉, Argument와 관련된 Exception을 잡고 싶으면, catch (ArgumentException ex) { ... } 와 같이 잡게된다.<br>

catch 블럭은 하나 혹은 여러 개 일 수 있다.<br>
**여러 catch를 사용하는 이유는 각 Exception 유형에 따라 서로 다른 에러 핸들링을 하기 위함이다.** ⭐⭐<br>
-> 맨 위 Catch에 Exception을 매개변수로 지정하고 하위에 다른 Catch문을 작성하면 에러가 난다.<br>
-> **이유는 맨 위 Catch문에 모든 에러가 걸리기 때문에 하위 Catch문이 사용되지 않을 것이기 때문!** ⭐⭐<br>

**finally는 Exception이 발생했던 발생하지 않았던 상관없이 마지막에 반드시 실행되는 블럭이다.** ⭐<br>
예를 들어, try 블럭에서 SQL Connection객체를 만든 경우,<br>
finally 블럭에서 Connection 객체의 Close() 메서드를 호출하면,<br>
에러 발생 여부와 상관없이 항상 Connection객체가 닫히게 된다.<br>
<br>

```c#
try
{
   //실행 문장들
}
catch (ArgumentException ex)
{
   // Argument 예외처리
}
catch (AccessViolationException ex)
{
   // AccessViolation 예외처리
}
finally
{
   // 마지막으로 실행하는 문장들
}
```
<br>
<br>

## 🔔 throw 기초
throw는 프로그래머가 ⭐ **예외 상황을 임의로 발생시키는 역할을 하며, 예외에 대한 책임을 전가 할 수도 있다.** ⭐<br>
try 문과 그 외에서도 사용가능(if문 등) 하다.<br>

```c#
try
{
    //
    throw new Exception("예외를 던집니다.");
}
catch(Exception e)  // throw 문을 통해서 던져진 예외 객체는 catch 문으로 받습니다.
{
    Console.WriteLine(e.Message);
}
```
<br>

```c#
static void DoSomething(int age)
{
    if(age<10)
        Console.WriteLine("age: {0}", age);
    else
        // DoSomething() 안에서 예외 처리 코드가 없기 때문에 DoSomething() 호출자에게 던집니다.
        throw new Exception("age가 10보다 큽니다.");
}

static void Main()
{
    try
    {
        DoSomething(13); // 던져진 예외가 있다면 catch 블록에서 받습니다.
    }
    catch(Exception e)
    {
        Console.WriteLine(e.Message);
    }
}
```
<br>
<br>

## 🔔 throw 심화
**try 블럭에서 Exception이 발생하였는데 이를 catch 문에서 잡았다면, Exception은 이미 처리된 것으로 간주된다.<br>
때때로 catch문에서 기존의 Exception을 다시 상위 호출자로 보내고 싶을 때가 있는데, 이때 throw 를 사용한다.**<br>

throw 문은 크게 3가지로 구별될 수 있다.<br>
(1) throw 문 다음에 catch에서 전달받은 Exception 객체를 쓰는 경우<br>
(2) throw 문 다음에 새 Exception 객체를 생성해서 전달하는 경우<br>
(3) throw 문 다음에 아무것도 없는 경우 등이 있다.<br>

(1) 👉 **throw 문 다음에 catch에서 전달받은 Exception 객체를 쓰는 경우**<br>
이는 throw ex; 와 같이 catch (Exception ex) 에서 전달받은 아규먼트 ex 를 사용하는 경우이다.<br>
이러한 throw 방식은 ex 에 담긴 예외 정보를 보전하지만, Stack Trace 정보를 다시 리셋하기 때문에<br>
throw문 이전의 콜스택(Call Stack) 정보를 유실하게 된다.<br>
따라서, 일반적으로 이러한 방식은 사용하지 않는 것이 좋다.<br>
<br>

(2) 👉 **throw 문 다음에 새 Exception 객체를 생성해서 전달하는 경우**<br>
새로운 Exception 객체를 만들어 던지기 위해서는 throw new MyException();와 같이<br>
C#의 new를 사용하여 새로운 Exception 객체를 만든 후, 이 객체를 throw 하면 된다.<br>
이는 catch 에서 잡은 Exception을 Wrapping 하여 새로운 Exception을 전달할 때 사용하는데,<br>
잘못 사용하면(InnerException을 포함하지 않으면) 기존 Exception 정보를 잃을 수 있다.<br>
따라서, 이러한 방식을 사용하여 새로운 Exception 객체를 만들 때는 catch 에서 얻은<br>
Exception 객체를 새 객체의 InnerException에 포함시켜 에러 정보를 보전하는 것이 좋다.<br>
Ex) throw new MyException(msg, ex);와 같이 catch에서 전달받은 ex를 InnerException으로 전달하는 것이 좋다.<br>
InnerException의 StackTrace 속성은 어느 라인에서 에러가 발생했는지를 알려주는데,<br>
이는 에러가 다른 메서드에서 발생했을 때는 물론 동일 메서드에서 발생했다 하더라도<br>
정확히 어떤 라인에서 에러가 발생했는지를 알게 해 준다.<br>
<br>

(3) 👉 **throw 문 다음에 아무것도 없는 경우**<br>
throw; 와 같이 뒤에 어떠한 Exception 객체 없이 그냥 throw문만을 사용할 수 있는데,<br>
이는 catch문에서 잡힌 Exception을 그대로 상위 호출 함수에게 전달하는 일(rethrow)을 한다.<br>
즉, 에러를 발생시킨 콜스택 정보를 그대로 상위 호출 함수에 전달하려면 이렇게 throw; 를 호출하면 된다.<br>
한가지 주목할 점은, throw; 는 에러가 다른 메서드에서 발생했을 때는 그 에러가 발생한 다른 메서드의 위치를 포함하지만,<br>
만약 throw문과 동일한 메서드에서 에러가 발생했다면 동일 메서드의 어느 라인에서 에러가 발생했는지는 포함하지 않는다.<br>
<br>

아래 예제는 IndexOutOfRangeException이 발생한 경우 MyException이라는 사용자 정의 Exception객체를 만들어 던지게 하는데,<br>
catch에서 잡은 ex 객체를 MyException의 InnerException에 포함시키고 있다.<br>
FileNotFoundException이 발생한 경우는 throw ex 와 같이 호출하고 있는데,<br>
이는 throw ex 까지의 이전 콜스택을 제거하기 때문에 throw ex 이후부터의 콜스택 정보만을 전달하게 된다.<br>
마지막으로 그 외의 모든 Exception의 경우는 발생한 Exception을 그대로 상위 호출 함수에게 전달하기 위해 throw; 문을 사용하고 있다.<br>
<br>

```c#
try
{
    // 실행 문장들
    Step1();
    Step2();
    Step3();
}
catch(IndexOutOfRangeException ex)
{
    // 새로운 Exception 생성하여 throw
    throw new MyException("Invalid index", ex);
}
catch(FileNotFoundException ex)
{    
    bool success = Log(ex);
    if (!success)
    {
        // 기존 Exception을 throw
        throw ex;
    }
}
catch(Exception ex)
{    
    Log(ex);
    // 발생된 Exception을 그대로 호출자에 전달
    throw;
}

```
<br>
<br>

## 🔔 예외 처리 예제
아래 예제는 SQL Server에 연결하여 데이타베이스 내의 테이블,뷰 등의 SQL Objects 수를 가져온 후 이를 화면에 뿌리는 코드이다.<br>

만약 SQLException 타입의 에러가 발생하면 catch 블럭에서 잡아서 에러 메시지만 콘솔에 표시하고 Exception을 삼키게 된다.<br>
마지막의 finally 블럭은 SqlConnection의 Close() 메서드를 실행하여 Connection을 닫는다.<br>
물론 에러가 발생하지 않더라도 finally 블럭은 실행되며, 따라서 SQL Connection은 항상 닫히게 된다.<br>
<br>

```c#
string connStr = "Data Source=(local);Integrated Security=true;";
string sql = "SELECT COUNT(1) FROM sys.objects";
SqlConnection conn = null; 

try
{
    conn = new SqlConnection(connStr);
    conn.Open();
    SqlCommand cmd = new SqlCommand(sql, conn);
    object count = cmd.ExecuteScalar();
    Console.WriteLine(count);                
}
catch (SqlException ex)
{
    Console.WriteLine(ex.Message);
}
finally
{
    if (conn != null && conn.State == System.Data.ConnectionState.Open)
    {
        conn.Close();
    }
}
```
<br>
<br>

## 🔔 장점과 Tip. ⭐⭐⭐
* 👉 섬세한 예외 처리가 필요한 겨우 **Exception 클래스를 마구 남용해선 안된다.**<br>
Exception 형식은 프로그래머가 발생할 것으로 계산한 예외 말고도 다른 예외까지 받아낼 수 있기 때문이다.<br>
그 예외가 현재 코드가아닌 상위 코드에서 처리해야할 예외라면 이코드는 버그를 만들고 있는 셈이 되므로 남용해선 안된다.<br>

* 👉 try~catch 문을 이용한 예외처리는 실제 일을 하는 코드와 문제를 처리하는 **코드를 깔끔하게 분리시킴으로서**<br>
코드를 **간결하게** 만들어 주며, **예외객체의 StackTrace 프로퍼티를 통해 문제가 발상핸 부분의 소스코드 위치를<br>
알려주기 때문에 디버깅이 아주 용이하다.**<br>
**즉 예외처리를 사용한 코드는 작성하기도 쉽고, 읽기도 쉽다는 장점이 있다.**<br>

* 👉 **예외처리는 여러 문제점을 하나로 묶어내거나** 코드에서 발생할 수 있는 오류를 종류별로 **정리**하는 효과를 가진다.<br>
예를들어 try블록의 코드에서 DivideByZeroException **예외를 일으킬 수 있는 부분은 둘 이상일 수 있지만,<br>
이 형식을 받는 Catch블록은 하나면 모두 처리가 가능하다.**<br>

* 👉 사용자 정의 예외 객체를 만들어 사용할 수도 있다.<br>

* 👉 **프로그램이 Crash나서 강제 종료되는 경우를 막을 수 있다.**<br>
<br>
<br>

## 🔔 참조 링크
https://1q1w.github.io/c%23%20basic/csharp_exception/ 사용자 정의 예외 클래스 예제<br>
https://www.csharpstudy.com/CSharp/CSharp-exception.aspx<br>
https://mandy8303.tistory.com/18 (Tip)<br>
<br>
<br>
