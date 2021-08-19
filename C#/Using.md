## Using
c#에서 Using 키워드의 사용 용도는 2가지가 있다.<br>

1.전처리기 지시문(Directive)<br>
다른 네임스페이스에 정의된 타입을 Import 하거나, 네임스페이스에 대한 별칭을 만들때 사용한다.<br>

```c#
using System.Text; //코드 상단에 네임스페이스 정의
using Project = PC.MyCompany.Project; // 별칭
```
<br>
<br>

2.문장(Statement)<br>
개체의 범위를 정의할때 사용한다. 그 범위를 벗어나면 자동으로 Dispose 된다.<br>
File이나 Font, DB Connection 관련 클래스들은 관리되지 않는 리소스에 액세스 한다.<br>
즉 사용후 적절하게 Dispose해서 자원을 반납해야 한다.<br>
하지만 종종 Dispose를 하지 않아서 리소스가 낭비되거나<br>
DB Connection 같은 것을 Open만하고 Close하지 않아 문제가 발생하는 경우가 있다.<br>
이때 일일이 Close하지 않고 Using을 이용하면, 해당 범위를 벗어날때 자동으로 Dispose 돼서 관리가 쉬워진다.<br>

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
using 문은 개체의 메서드를 호출하는 동안 예외가 발생하는 경우에도 Dispose가 호출되도록 한다.<br> 
try 블록 내에 개체를 배치한 다음 finally 블록에서 Dispose를 호출해도 동일한 결과를 얻을 수 있다.<br> 
<br>

실제로 이 방식은 컴파일러에서 using 문이 변환되는 방식이다.<br>
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

## 참조링크
https://hongjinhyeon.tistory.com/92 <br>
