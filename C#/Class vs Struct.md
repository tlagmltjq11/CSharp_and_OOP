## 🔔 Main Concept
C#에서 Class와 Struct란 **특정 대상, 객체를 나타내기 위해 서로 다른 자료형의 데이터와<br>
기능들을 하나로 묶은 자료형** ⭐을 의미한다.<br>

즉 **개념적인 측면에서는 동일한** 기능을 한다고 볼 수 있다.<br>
-> 개념뿐만 아니라 실제로 구조체를 클래스 처럼, 클래스를 구조체 처럼 사용해도 문제될 것이 없다.<br>

하지만 이러한 클래스와 구조체간에는 **여러 차이점**들이 존재한다.<br>
지금부터 알아보도록 하겠다.<br>
<br>
<br>

## 🔔 1. Class는 Heap에 Struct는 Stack에 할당 된다.
👉 **Heap** : 힙은 **런타임에 할당**되는 영역이며 new 등의 동적 할당 기능을 통해 프로그램 실행 중<br>
필요한 만큼 가변적으로 확보되어 추후 정리를 위해서는 delete 나 **가비지 컬렉션 ⭐ 등의 메모리 관리가 필요**한 반면,<br>
<br>

👉 **Stack** : 스택은 함수 내에 포함되어 있는 지역 변수 등이 저장되는 영역으로 미리 그 크기를 파악할 수 있기에<br>
**컴파일 타임에 결정**되며 함수가 종료 되는 시점에서 **자동으로 ⭐ 정리되는 영역**이다.<br>
<br>

👉 클래스는 이 중 힙의 영역에 생성되어 ⭐⭐ **메모리 크기에 좀 더 자유로운 대신<br>
가비지 컬렉션의 영향을 받기에 퍼포먼스에 영향** ⭐⭐을 줄 수 있다.<br>
-> **동적 할당을⭐ 하는 과정 자체도 성능에 영향을 다.**<br> 
<br>

👉 반면 구조체 객체의 경우는 스택 영역에 생성되어 ⭐**가비지 컬렉션의 영향을 받지 않기에<br>
성능 면에서는 상대적으로 이점**이 있지만 **메모리 크기 면에서 한정적이라는 단점이 있다.** ⭐<br>
-> 속도 면에서는 빠르지만, 메모리 측면에서 한계가 존재한다.<br>
<br>
<br>

## 🔔 2. Class는 참조 타입 Struct는 값 타입 
👉 **클래스는 참조 타입**이기 때문에 객체를 전달했을 때 그 객체는 항상 원본과 동일하다.<br>
즉, 클래스로 생성한 객체를 다른 함수에 전달 했을 때 해당 객체의 멤버 변수의 값을 변경시키면<br>
원본의 변수도 변경 되며 전달받은 함수가 종료되더라도 객체는 계속 유효하다.<br>
-> 주소를 전달하기 때문.<br>
 <br>

👉 반면 **구조체는 값 타입** 이므로 함수를 호출해서 객체를 전달하면 원본과 다른 **복사본이 생성된다.**<br>
때문에 이 객체의 멤버 변수를 변경해도 해당 함수의 스택 영역에 복사된 객체의 변수만 변경 될 뿐 **원본은 영향을 받지 않는다.**<br>
<br>

그리고 ⭐ **전달 할 때 참조 타입인 클래스는 자신의 메모리 주소 한개만 넘겨주면 되지만**<br>
값을 복사해야 하는 **구조체는 자신의 크기 만큼의 스택 공간을 할당하게 되므로<br>
크기가 클수록 메모리 사용량도 늘어난다.** ⭐<br>
(스택은 공간 제약이 있으므로 과도하게 커지면 **스택 오버플로우**가 발생할 수도 있다)<br>
<br>
<br>

## 🔔 3. 그 외 차이점
* 👉 **구조체는 상속이 불가능** 하기에 기능의 확장에 제약이 있어 아무래도 **복잡한 기능에 적용하기는 쉽지 않다.**<br>
-> **단, 인터페이스 ⭐ 상속은 가능하다.**<br>
<br>

* 👉 접근 지시자의 기본값이 클래스는 private, 구조체는 public<br>
-> **수정 : 둘다 기본값 private 임**<br>
<br>

* 👉 **구조체는 기본 생성자를 사용하려면 모든 멤버를 초기화 해주어야 한다.**<br>
```c#
StructTest obj2 = new StructTest(10,20,30); // 해당 구조체의 모든 멤버를 초기화
```
-> 구조체는 new 키워드 없이도 인스턴스화가 가능하다.<br>
-> Value 타입의 경우 내부에서 자동으로 new를 호출하기 때문임.<br>
<br>

* 👉 **구조체로 선언을 했어도 객체를 힙영역에 메모리를 할당할 때가 있다.** 
1. 모든 필드의 합이 **16byte를 넘는 경우**
2. **구조체안에 클래스 타입을 필드로 가질 경우** ⭐
<br>
<br>

## 🔔 가능하다면 구조체를 사용하자
⭐⭐ **아무래도 클래스 보다는 구조체를 자주 이용하는 것이 가비지 컬렉션의 호출 빈도를 줄이고<br>
힙 할당/해제 보다 스택 할당/해제가 훨씬 빠른 특성 등으로 봤을 때<br>
성능상으로 큰 장점을 가지고 있으므로 적극적으로 사용하는 걸 권한다.** ⭐⭐<br>
<br> 

아무리 스택 할당/해제가 빠르더라도 용량이 커지면<br>
당연히 주소만 전달하는 클래스보다 더 느려지므로 잘 판단해야 한다.<br>
<br>
 
👉 **클래스를 사용해야하는 경우**<br>
1. **상속**이 필요한 경우<br>
2. **메모리를 많이** 차지하는 경우<br>
3. **복잡**한 객체를 정의하는 경우<br>
<br>

👉 **구조체를 사용해야하는 경우**<br>
1. **짧게** 생성되고 없어지는 경우<br>
2. **단순**하고 **메모리를 적게** 차지하는 경우<br>
3. 클래스를 사용할 필요가 없는 경우<br>
ex) position, rotation 등과 같은 데이터 셋..<br>
<br>
<br>

## 🔔 ⭐⭐⭐ 추가된 부분 ⭐⭐⭐
👉 ⭐ **존재 의의** ⭐<br>
struct는 **변수를 컨트롤**하는게 주목적(Unity의 Vector와 같이)이고<br>
class는 **어떤 행위(메소드)를 하는 객체 정의**가 목적이다.<br>
struct는 변수를 컨트롤하기 위해 메소드가 있는거고 class는 메소드를 구현하기 위해 변수가 있는것.<br>
-> **애초에 이와같이 class와 struct의 존재 의의를 제대로 구분해서 사용하는 것이<br>
-> class와 struct를 사용했을 경우의 차이점 등을 고려하는 것보다 훨씬 중요하다.**<br>
<br>

아무리 스택 할당/해제가 빠르더라도 용량이 커지면<br>
당연히 주소만 전달하는 클래스보다 더 느려지므로 잘 판단해야 한다.<br>
👉 -> ⭐⭐ **ref 키워드를 사용하면 참조에 의한 전달이 가능한 부분이다.<br>
-> 하지만 ref의 본래 사용법은 변경사항이 필요할 때 쓰는 것이기에 올바른 코딩습관으로 볼 수 없다.<br>
-> 더불어 컴파일러 최적화, HW 성능이 워낙 좋아진 시대라 단순 복사로 성능 저하가 일어나는 일은<br>
-> 거의 없다고 한다. 고로 class와 struct의 존재의의를 잘 구별해서 적재적소에 사용하는 것과<br>
-> 유지보수 및 코드 설계 관점에서 바라볼 줄 아는 능력을 기르는 것이 가장 중요하다.** ⭐⭐<br>
<br>

👉 메소드 내에서 구조체의 필드를 많이 참조한다면 역으로 매개변수를 복사해오는게 빠를 수도 있다.<br>
주소로 참조하는 객체의 필드 참조는 힙 영역에서 이루어지지만, 일반적인 방식대로 복사된 구조체의 필드 참조는 스택에서 이루어지기 때문.<br>
<br>

👉 그리고 매개변수를 call by value로 넘기는 가장 큰 목적 중 하나가 또 있다.<br>
바로 caller의 context에서 값이 변할 염려가 없다는 점이다.<br>
**코드 설계에서 private와 같은 접근 제한자를 잘 설정하는게 중요한 것처럼, 매개변수를 call by value로 하느냐,<br>
call by reference로 하느냐는 매우 중요하다.**<br>
특정 엔진의 API에서 제공하는 함수로 값을 넘겼고 안에서 무슨 일이 일어나는지 잘 모르는데,<br>
그 함수가 내가 전달한 객체의 내부 값을 변경시키냐 그렇지 않느냐는 매우 중요하기 때문이다.<br>
<br>
<br>

## 🔔 참조링크
https://skuld2000.tistory.com/16 <br>
https://asta8080.tistory.com/5 <br>
https://hijuworld.tistory.com/43 <br>
https://tip1234.tistory.com/195 <br>
