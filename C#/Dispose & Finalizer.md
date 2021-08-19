## 🔔 Unmanaged Resource
**C#클래스에 파일 핸들이나 DB Connection같은 Unmanaged 리소스를 가지고 있을 때, 어떻게 이들 리소스를 해제할 수 있는가?**<br>
-> 여기서 Unmanaged Resource란 file, DB connection, stream 등 IDisposable 을 구현하고있는 클래스들로 **외부 자원**들을 의미한다.<br>
-> 이러한 unmanaged resource는 **⭐ GC에 의해 관리되지 않기 ⭐ 때문에 직접 release해야한다.**<br>
-> 정확히는 Dispose 내에 메모리해제를 위한 작업을 구현해야 한다.(스트림 닫기, 연결 끊기 등)<br>
-> C#에서 제공하는 IDisposable를 상속받은 클래스들은 당연히 이미 구현되어있다.<br>
-> 그에 반해 managed resource 는 .NET 에서 생성한 모든 객체를 말하는 것이다.<br>
<br>

👉 **즉 사용후 적절하게 자원을 직접 반납해야 한다.**<br>
C++의 경우 소멸자가 유용하게 사용되는데, C# 역시 소멸자를 제공하지만,<br>
IDisposeable 인터패이스를 상속하여 **⭐ Dispose라는 메서드를 override하여<br>
Unmanagement 메모리 해제나 Stream Close를 구현하도록 권장을 하고 있다.**<br>
<br>

**이러한 Dispose 패턴은 [Using](https://github.com/tlagmltjq11/CSharp_and_OOP/blob/main/C%23/Using.md)과 함께 사용되는 것이 일반적이다.** ⭐<br>
<br>
<br>

## 🔔 해제 방식
파일 핸들이나 네트워크 연결 같은 Unmanaged 리소스를 가지고 있는 경우, 이를 해제해 주기 위해 다음과 같은 방법을 사용할 수 있다.<br>
1. 👉 Finalizer (Destructor),<br>
2. 👉 Dispose 패턴을 사용할 수 있다.<br>
<br>

(1) Finalizer는 Garbage Collector(GC)에 의해 객체 소멸 전에 호출되는 코드 블력으로 이 안에 파일 핸들을 닫거나 연결을 닫는 코드를 넣는다.<br>

```c#
~MyClass() {
   if (file != null) { 
      file.Close(); 
   }
}
```
<br>

⭐⭐⭐ **이 방식의 문제점은 실행이 GC에 의해 자동으로 결정되기 때문에 언제 이 코드가 실행될 지 모른다는 점이다.<br>
즉, 객체가 다 사용되었는데, 파일은 계속 열려 있는 상태가 되고, GC가 언제 이를 Close할지도 모른다는 것이다.<br>
이러한 문제점을 해결하기 위해 Dispose 패턴을 사용한다.** ⭐⭐⭐<br>
<br>
<br>

(2) Unmanaged 리소스가 있는 클래스는 일반적으로 IDisposable이라는 인터페이스를 추가하고, IDisposable.Dispose() 메서드를 구현한다.<br>

```c#
public void Dispose() {
   if (file != null) { 
      file.Close(); 
   }
   //클래스에 Finalizer가 있을 경우
   GC.SuppressFinalize(this);
}
```
<br>

클래스 사용자는 이 Dispose()메서드를 실행하여 **GC를 기다리지 않고 리소스를 즉시 해제한다.** ⭐<br>
Dispose가 있더라도 클래스 사용자가 이를 호출하지 않았을 경우, 최후의 보루로 리소스를 해제하고 싶으면 개발자는 Finalizer를 추가할 수 있다.<br>
(물론 Finalizer를 추가하면 [문제#24](https://www.csharpstudy.com/algo/qa.aspx?Id=24&pg=0)에서 소개한 성능저하 부작용이 생길 수 있다)<br>
<br>

👉 **위의 Dispose()메서드 안의 GC.SuppressFinalize를 왜 호출하는가? ⭐⭐⭐<br>
클래스가 Finalizer 메서드와 Dispose메서드를 가지고 있을 때, Dispose() 메서드 호출한 후에는 Finalizer코드를 다시 실행할 필요가 없다.<br>
즉, 리소스를 두번 해제할 필요가 없다. 이 경우 GC.SuppressFinalize를 호출하여 Finalization Queue안의 해당 객체에 플래그를 표시하여<br>
Garbage Collection시 이 객체가 Freachable Queue로 이동하지 않게 한다. 따라서, Finalize()메서드가 호출되지 않게 하는 것이다.**<br>
<br>
<br>
