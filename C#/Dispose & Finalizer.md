## 🔔 Unmanaged Resource

**헷갈리는 부분**<br>
헷갈렸던 부분이 알고있기로 Unmanaged Resource는 GC의 대상이 아니기 때문에<br>
직접 릴리즈 해주지 않으면 안되는 것으로 알았는데..<br>
결국 언젠가는 GC에 의해 소멸자가 호출되어 (이때 소멸자 내부에서 Dispose를 호출해줌) <br>
해제가 된다는 점이다. 알아보자!!<br>
<br>

**내 답변**<br>
-> 결국 Unmanaged Resource의 객체 자체는 GC의 대상이기 때문에 소멸자(Dispose를 호출하는)를 언젠가 호출당하기 때문에<br>
-> 자원의 반납 자체는 **언젠가는** 된다는 것이 맞는 답변같다.<br>
<br>

**강사님 답변**<br>
네 맞습니다. GC 대상이 아닙니다. 그래서 FileStream 클래스 제작자가 소멸자 에서 닫아 주고 있습니다.<br>
만약 GC의 대상이라면 FileStream 클래스 제작자가 굳이 소멸자에서 닫는 작업을 하지 않아도 되겠지요 ??<br>
언제가는 닫힌다는 것은 "언젠가는 FileStream 클래스의 소멸자가 호출된다" 라는 의미 겠지요 ..<br>
<br>

링크 참조<br> 
https://velog.io/@jihoson94/C-Memory-Management-Releasing-unmanaged-resources- <br>
<br>
<br>
<br>

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
즉, 사용자가 Dispose()메서드를 항상 올바르게 호출할 것이라고 가정할 수 없다.<br>
비관리 리소스가 어떠한 경우에도 누수되지 않도록 올바르게 정리될 수 있도록 finalizer를 구현해야 한다.<br>
(물론 Finalizer를 추가하면 [문제#24](https://www.csharpstudy.com/algo/qa.aspx?Id=24&pg=0)에서 소개한 성능저하 부작용이 생길 수 있다)<br>

* finalizer사용시 성능 이슈 ⭐<br>
finalizer를 포함한 객체의 경우엔 finalizer를 호출해야하기 때문에<br>
가비지로 판단된 이후에도 즉시 메모리에서 해제하지 않는다.<br>
그렇기 때문에 finalizer를 포함하고 있는 객체를 사용하면 가비지 컬렉트 과정이 더 길어진다.<br>
가비지 컬렉터는 객체에 대한 참조를 다른 큐에 삽입하여 나중에 finalize가 호출될 수 있도록 준비하는데<br>
이 과정에서 finalizer가 없는 객체는 메모리로부터 즉각 제거된다.<br>
그러나 finalizer가 있는 객체는 다른 큐에 넣어두었다 일정시간이 지난뒤 객체를 꺼낸 후 finalizer를 호출하며 메모리를 해제한다.<br>
<br>
<br>

👉 **위의 Dispose()메서드 안의 GC.SuppressFinalize를 왜 호출하는가? ⭐⭐⭐<br>
클래스가 Finalizer 메서드와 Dispose메서드를 가지고 있을 때, Dispose() 메서드 호출한 후에는 Finalizer코드를 다시 실행할 필요가 없다.<br>
즉, 리소스를 두번 해제할 필요가 없다. 이 경우 GC.SuppressFinalize를 호출하여 Finalization Queue안의 해당 객체에 플래그를 표시하여<br>
Garbage Collection시 이 객체가 Freachable Queue로 이동하지 않게 한다. 따라서, Finalize()메서드가 호출되지 않게 하는 것이다.**<br>
<br>
<br>
