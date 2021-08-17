## Object
C#의 모든 클래스의 최상위에 있는 클래스이다.<br>
따라서 사용자 정의 클래스를 비롯한 모든 클래스는 Object를 상속받는다.<br>
-> 고로 모든 타입의 값을 할당할 수 있는 **다형성**을 사용할 수 있다.<br>
Object 클래스는 다음과 같은 4개의 public 메소드를 포함하고 있다.<br>

```c#
public class object
{
    public virtual bool         Equals(object obj);
    public virtual int          GetHashCode();
    public Type                 GetType();
    public virtual string       ToString;
}
```
<br>
<br>

## 참조링크
https://rpgmakerxp.tistory.com/51 <br>
https://nkcnow.tistory.com/141 한번 읽어보기.<br>
