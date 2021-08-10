## 🔔 Generic 
일반적으로 클래스를 정의할 때, 클래스 내의 모든 데이타 타입을 지정해 주게 된다.<br>
하지만 어떤 경우는 클래스의 거의 ⭐ **모든 부분이 동일한데 일부 데이타 타입만이 다른 경우**가 있을 수 있다.<br>
예를 들어, 사칙연산을 하는 클래스 A가 있다고 가정하자. 이 클래스 A에는 int 타입의 필드들이 있고,<br>
int 타입을 파라미터로 받아 계산하는 메서드들도 있다. 그러면 이 클래스 A를 double 타입의 데이타를 가지고 사용할 수 있을까?<br>
그렇 수 없다. 왜냐하면 이미 모든 필드 및 파라미터가 int로 설정되어 있기 때문이다.<br>
<br>

이런 경우 C#의 제네릭 타입(Generic Type)을 사용할 수 있는데, 제네릭 타입에서는 int, float, double 같은<br>
**데이터 요소 타입을 확정하지 않고 이 데이터 타입 자체를 타입 파라미터(Type Parameter)로 받아들이도록 클래스를 정의한다.**<br>
이렇게 정의된 클래스 즉 C# 제네릭 타입을 사용할 때는 클래스명과 함께 구체적인 데이타 타입을 함께 지정해 주게 된다.<br>
이렇게 하면 일부 상이한 데이타 타입 때문에 여러 개의 클래스들을 따로 만들 필요가 없어지게 된다.<br>
C# 제네릭은 이렇게 클래스 이외에도 **인터페이스나 메서드에도 적용될 수 있다.**<br>
<br>

📜 <br>
```c#
// 어떤 요소 타입도 받아들 일 수 있는
// 스택 클래스를 C# 제네릭을 이용하여 정의
class MyStack<T>
{
    T[] _elements;
    int pos = 0;

    public MyStack()
    {
        _elements = new T[100];
    }

    public void Push(T element)
    {
        _elements[++pos] = element;
    }

    public T Pop()
    {
        return _elements[pos--];
    }
}

// 두 개의 서로 다른 타입을 갖는 스택 객체를 생성
MyStack<int> numberStack = new MyStack<int>();
MyStack<string> nameStack = new MyStack<string>();
```
<br>
<br>

👉 **제네릭 타입 제약**<br>
C# 제네릭 타입을 선언할 때, 타입 파라미터가 Value Type인지 Reference Type인지, 또는 어떤 특정 Base 클래스로부터 파생된 타입인지,<br>
어떤 인터페이스를 구현한 타입인지 등등을 지정할 수 있는데, 이는 where T : 제약조건과 같은 식으로 where뒤에 제약조건을 붙이면 가능하다.<br>
아래는 다양한 제약을 가한 예제들이다.<br>
<br>

📜 <br>
```c#
// T는 Value 타입
class MyClass<T> where T : struct 

// T는 Reference 타입
class MyClass<T> where T : class

// T는 디폴트 생성자를 가져야 함
class MyClass<T> where T : new() 

// T는 MyBase의 파생클래스이어야 함
class MyClass<T> where T : MyBase

// T는 IComparable 인터페이스를 가져야 함
class MyClass<T> where T : IComparable

// 좀 더 복잡한 제약들
class EmployeeList<T> where T : Employee,
   IEmployee, IComparable<T>, new()
{
}

// 복수 타입 파라미터 제약
class MyClass<T, U> 
    where T : class 
    where U : struct
{
}
```
<br>
<br>

👉 **제네릭의 장점**<br>

* 제네릭의 핵심은 패턴 구현 코드를 작성하고 패턴이 나타나면 ⭐ **구현 코드를 재사용** ⭐ 하는 것에 있다.<br>
-> 즉, 형식 패턴이 바뀐다고 여러번 코드를 작성할 필요를 줄여준다.<br>

* 클래스 내에서 명시적으로 의도한 것을 제외한 데이터 형식을 막을 수 있다.<br>

* ⭐ **Object 사용으로 인한 Boxing 차단하며 메모리를 덜 소모한다.** ⭐<br>

* 가독성 증가<br>
<br>
<br>
<br>

-----------------------------------------------<br>
참고 : http://www.csharpstudy.com/CSharp/CSharp-generics.aspx <br>
