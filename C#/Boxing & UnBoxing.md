## Boxing
**값 형식을 참조 형식(Object)으로 변환하는 것을 말한다.**<br>
-> 힙영역에 값형식을 저장하게 된다.<br>

```c#
int i = 123;
// The following line boxes i.
object o = i;
```
<br>

위 예에서는 int의 값 형식을 Object라는 참조 형식으로 형변환을 시도한다.<br>
그 목적은 여러가지가 있을 수 있는데 보통 파라미터 전달이나, List[Object] 형식으로<br>
모든 값들을 입력받는 목적으로도 사용될 수 있다.<br>

위의 코드는 메모리상에서 아래와 같이 메모리가 할당된다.<br>

![박싱메모리](https://user-images.githubusercontent.com/43705434/129768584-0a0f72fe-7f1a-47c3-91d4-ab7fb39a5510.PNG)<br>
<br>

박싱의 과정<br>
1. 값 타입을 힙에 생성하기 위해 **메모리를 힙 영역에 생성 -> 추후 가비지가 될 것임.**
2. 값을 힙 영역에 할당된 메모리로 복사
3. 참조할 변수에 할당된 메모리 주소를 할당
<br>

스택 영역에 있는 i값이 o로 변환이 되면서 힙영역에 메모리가 할당되고, 값이 복사된다.<br>
o는 스택영역에 존재하며 boxed된 i의 주소값을 가지고 있다.<br>

**박싱은 보통 암시적**으로 되며, 명시적으로도 가능하다.<br>
<br>
<br>
  
## UnBoxing
**참조 형식(Object)에서 값형식으로 변환하는 것을 말한다.**<br>

```c#
int i = 123;      // a value type
object o = i;     // boxing
int j = (int)o;   // unboxing
```
<br>

언박싱 과정은 두가지의 절차를 거친다.<br>
1. 개체 인스턴스가 지정한 값 형식을 **boxing 한 값인지 확인**<br>
-> **즉 박싱된 것만 언박싱이 가능**<br>
2. 인스턴스의 값을 값 형식 변수에 복사<br>

![언박싱메모리](https://user-images.githubusercontent.com/43705434/129768588-c9067448-282a-4541-8c7d-3c1ee7fdaa49.PNG)<br>
<br>

위의 그림에서 보면, int를 박싱한 o의 객체를 다시 int 타입의 j 값에 넣고 있다.<br>

**언박싱을 할 때 다른 타입으로 하거나, 해당 타입보다 작은 범위로 변환을 하려면 오류(InvalidCastException)가 발생한다.**<br>
이때는 미리 같은 타입인지를 먼저 확인하는 절차를 거쳐야한다.<br>
-> is 연산자를 이용해서 미리 같은 타입인지 확인 후에 캐스팅을 해야 안전하다.<br>
또한 **언박싱은 명시적**으로 형 변환을 해주어야 한다.<br>
<br>
<br>

## 결론
**박싱과 언박싱 장점**<br>
사용상의 편의성<br>
대표적으로 System.Collections.ArrayList 클래스가 대표적인 복합자료형<br>
타입에 관계없이 추가가능 => Add의 메서드가 Object 타입의 매개변수를 취하고 있다.<br>

**박싱과 언박싱 단점**<br>
**박싱할때는 완전히 새로운 개체(메모리 할당)를 만들며**,이러한 작업에는 할당 작업보다 최대 20배의 시간이 걸린다.<br>
**언박싱할때는 언박싱 가능체크 + 캐스팅** 과정에서 할당 작업보다 4배의 시간이 걸린다.<br>
박싱한 메모리와 언박싱한 메모리 2개 존재 (가비지가 발생)<br>
-> 박싱할 때 힙영역에 할당하는 메모리 + 언박싱을 위해 필요한 변수<br>
<br>

즉 박싱과 언박싱은 단점을 끌고가면서 까지 사용할만한 기능이 아니다.<br>
되도록이면 **제네릭** 을 사용해서 박싱과 언박싱이 일어나지 않도록 구성을 해야하며,<br>
어쩔 수 없이 사용하려면 그 타입에 맞는 캐스팅을 해서 오류가 없이 처리해야한다.<br>

**그 외 박싱/언박싱을 최소화 하는 방법**<br>
enum을 .Equals 로 비교하게 되면 내부적으로 object 비교가 발생하여 boxing이 발생하는 점 주의.<br>
문자열에 값 타입의 객체를 직접 전달하지 말고, ToString()을 활용하여 문자열 인스턴스를 전달하는 방식 사용.<br>
<br>
<br>

## 참조링크
https://hongjinhyeon.tistory.com/90 <br>