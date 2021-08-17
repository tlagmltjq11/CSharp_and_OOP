## Const vs ReadOnly
C# 에서 const 와 readonly는 상수형 타입이다.<br>
더 자세히는 **const는 컴파일 타입의 상수**이며, **readonly는 런타임 상수**이다.<br>
<br>

**const**<br>
컴파일 타입의 상수이다.<br>
내장자료형 (정수형, 실수형, Enum, String)에 대해서만 사용 할 수 있다.<br>
변수 선언과 동시에 값을 할당 해야 한다.<br>
자동으로 static 처리 된다.<br>
<br>

**readonly**<br>
런타임 상수이다. -> **메서드 내에서 선언할 수 없는 이유**<br>
모든 자료형에 사용 할 수 있으며, 생성과 동시에 초기화 할 필요는 없다.<br>
-> 단, 생성자 단계에서 단 1번 할당을 통해 초기화 할 수 있다.<br> 
static 키워드를 사용해야 static 처리 된다. 즉 디폴트는 static이 아님.<br> 
<br>

위 내용의 런타임 상수와 컴파일 상수의 차이 중, **중요한 차이는 값이 런타임에 평가된다는 점이다.**<br> 
런타임 상수를 참조하는 코드를 컴파일하면 **컴파일 타임 상수처럼 코드를 값으로 대체하지 않고, 참조 코드를 생성한다.**<br>
**이러한 차이가 유지보수에 상당한 영향을 미친다.**<br>
<br>

```c#
public class UsefulValues
{
    public static readonly int StartValue = 5;
    public const int EndValue = 10;
}
```

위와 같이 정의하여 값을 사용하다 아래와 같이 수정할 때,<br>

```c#
public class UsefulValues
{
    public static readonly int StartValue = 105;
    public const int EndValue = 110;
}
```

수정 후, 리빌드하지 않고 사용한다면, StartValue에 대한 값은 참조 코드로 인해 런타임에 105로 읽지만,<br>
EndValue는 이전 컴파일 시점에 대체되었던 10으로 값이 유지된다.<br>
이처럼 컴파일 타임 상수의 값을 수정할 때는 신중해야 하며, **모든 코드를 재컴파일해야 한다.**<br>
하지만, 런타임 상수는 값 변경만으로도 수정이 가능하며 이진 호환성도 그대로 유지된다.<br>

const가 가지는 장점은 성능이 빠르다는 것인데, 이를 통해 얻을 수 있는 성능 개선 효과가 크지 않아,<br>
위와 같은 예외적인 상황을 제외한다면 **readonly를 사용하는 것이 좋다.**<br>
<br>
<br>

 ## 참조링크
 https://loveme-do.tistory.com/3 <br>
 https://adibong.tistory.com/entry/C-const-%EC%83%81%EC%88%98 <br>
