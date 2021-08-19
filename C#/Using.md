## 🔔 Using
c#에서 Using 키워드의 사용 용도는 2가지가 있다.<br>

* 전처리기 지시문 (Directive)<br>
👉 **다른 네임스페이스에 정의된 타입을 Import** 하거나, **네임스페이스에 대한 별칭**을 만들때 사용한다.<br>

```c#
using System.Text; //코드 상단에 네임스페이스 정의
using Project = PC.MyCompany.Project; // 별칭
```
<br>
<br>

* 문장 (Statement)<br>
👉 **개체의 범위를 정의할때 사용한다. 그 범위를 벗어나면 자동으로 Dispose(처분하다) 된다.**<br>
File이나 Font, DB Connection 관련 클래스들은 **unmanageed 리소스**에 액세스 한다.<br>
-> 관리되지않는 리소스란 **IDisposable** 을 구현하고있는 클래스들로 **외부 자원**들을 의미한다.<br>
-> 데이터베이스라던지 파일IO라던지  stream 등등.<br>
-> 이러한 **unmanaged resource는 ⭐ GC에 의해 관리되지 않기 ⭐ 때문에 직접 release해야한다.**<br>
-> 정확히는 Dispose 내에 메모리해제를 위한 작업을 구현해야 한다.<br>
-> C#에서 제공하는 IDisposable를 상속받은 클래스들은 당연히 이미 구현되어있다.<br>
-> 그에 반해 managed resource 는 .NET 에서 생성한 모든 객체를 말하는 것이다.<br>

👉 **즉 사용후 적절하게 자원을 직접 반납해야 한다.**<br>
C++의 경우 소멸자가 유용하게 사용되는데, C# 역시 소멸자를 제공하지만,<br>
IDisposeable 인터패이스를 상속하여 ⭐ **Dispose라는 메서드를 override하여<br>
Unmanagement 메모리 해제나 Stream Close를 구현하도록 권장**을 하고 있다.<br>
-> [소멸자보다 Dispose 패턴을 사용해야하는 이유](http://www.simpleisbest.net/post/2011/05/12/Finalizer-Usage-Pattern.aspx)<br>
<br>

👉 **자원을 반납하지 않는다면** <br>
1. DB Connection Open만하고 Close하지 않아 메모리 낭비와 에러 발생 가능성<br>

2. memory stream에 데이터를 넣고 Dispose 해주지 않아 계속 메모리를 잡아먹고있는 경우 등.<br>
<br>
<br>

👉 **위와 같은 상황이 없도록 Using을 사용하자는 것.<br>
이때 일일이 Close하지 않고 ⭐⭐ **Using을 이용하면, 해당 범위를 벗어날때 자동으로 Dispose** ⭐⭐ 돼서 관리가 쉬워진다.<br>
(물론 커스텀 객체라면 IDisposable을 상속받아 Dispose를 구현해야 할 것.)<br>
<br>

```c#
using (SqlConnection connection = new SqlConnection(connectionString))
{
    SqlCommand command = new SqlCommand(queryString, connection);
    command.Connection.Open();
    command.ExecuteNonQuery();
}
```
<br>

위처럼 Connection을 Using 구문으로 사용하면 {} 범위를 벗어날 때 자동으로 Dispose가 된다.<br>
using 문은 개체의 메서드를 호출하는 동안 ⭐ **예외가 발생하는 경우에도 Dispose가 호출되도록 한다.**<br> 
try 블록 내에 개체를 배치한 다음 finally 블록에서 Dispose를 호출해도 동일한 결과를 얻을 수 있다.<br> 
<br>

👉 **실제로 이 방식은 컴파일러에서 using 문이 변환되는 방식이다.**<br>
이전의 코드 예제는 컴파일 타임에 다음 코드로 확장된다.<br>

```c#
{
    SqlConnection connection = new SqlConnection(connectionString);
 
    try 
    {            
        SqlCommand command = new SqlCommand(queryString, connection);
        command.Connection.Open();
        command.ExecuteNonQuery(); 
    }
    finally
    {
        if (connection != null)
            ((IDisposable)connection).Dispose();
    }
}
```
<br>
<br>

## 🔔 참조링크
https://hongjinhyeon.tistory.com/92 <br>
https://magpienote.tistory.com/65 <br>
https://velog.io/@jihoson94/C-Memory-Management-Releasing-unmanaged-resources- <br>
