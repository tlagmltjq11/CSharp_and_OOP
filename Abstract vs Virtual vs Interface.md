https://stackoverflow.com/questions/761194/interface-vs-abstract-class-general-oo

👉 모든 디자인 패턴의 시작은 하위(자식) 클래스 객체를 상위(부모) 클래스 객체에 대입할 수 있는, 즉 **다형성**에서 시작된다고 한다.
<br>

1. 하위 클래스 객체를 상위 클래스 객체에 대입할 수 있다.<br>
-> Sub 타입에는 Super의 모든 멤버들이 포함되어있기 때문.<br>
<br>

```c#
Super obj = new Sub();
```

이때 obj는 Sub 타입의 객체를 참조하고 있지만, Super가 물려준 멤버들만 호출 할 수 있다.<br>
-> Sub만의 고유 멤버들은 호출이 불가능함.<br>
<br>
<br>

2. 상위 클래스 객체를 하위 클래스 객체에 대입할 수 없다.<br>
-> Sub만 갖고있는 멤버들은 Super 타입의 객체인 obj1에 없기 때문<br>
<br>

```c#
Super obj1 = new Super();
Sub obj2 = obj1;   // 컴파일 에러
```

<br>
<br>

## 🔔 가상 함수
C#도 C++과 마찬가지로 부모 타입의 포인터로 자식 객체를 참조하면 재정의 한게 있더라도 부모 타입의 멤버를 호출한다.<br>
C++, C# 은 Java와 다르게 멤버 호출시 참조하는 객체가 아닌 참조하는 변수의 타입을 보기 때문.<br>
<br>

따라서 부모 타입 포인터로 자식 객체를 참조했을 때 각 자식의 오버라이딩 된 멤버 함수를 호출하게 하려면 그 멤버 함수를 **가상 함수** 로 정의해야 한다.<br>
<br>

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

abstract class SuperA
{
    public abstract void Execute();
}

class SubA : SuperA
{
    public override void Execute()
    {
        Debug.Log("A");
    }
}


class SuperB
{
    public void Execute_1()
    {
        Debug.Log("B-1");
    }

    public virtual void Execute_2()
    {
        Debug.Log("B-2");
    }
}

class SubB : SuperB
{
    public void Execute_1()
    {
        Debug.Log("C-1");
    }

    public override void Execute_2()
    {
        Debug.Log("C-2");
    }

    public void Execute_3()
    {
        base.Execute_1();  // B-1 출력
        Debug.Log("C-3");
    }
}


public class CSharpEx : MonoBehaviour
{
    void Start()
    {
        SuperA super1 = new SubA();
        super1.Execute();  // 👉 "A"출력. 'SubA' 가 오버라이딩 한 Execute()실행

        SuperB super2 = new SuperB();
        super2.Execute1();  // 👉🏻 "B-1"출력. 'SuperB'의 Execute1()실행
        super2.Execute2();  // 👉🏻 "B-2"출력. 'SuperB'의 Execute2()실행

        SuperB super3 = new SubB();
        super3.Execute1();  // 👉🏻 "B-1"출력. 'SuperB'의 Execute1()실행
        super3.Execute2();  // 👉 "C-2"출력. 'SubB' 가 오버라이딩 한 Execute2()실행

        SubB sub1 = new SubB();
        sub1.Execute1();  // 👉 "C-1"출력. 'SubB' 가 오버라이딩 한 Execute1()실행
        sub2.Execute2();  // 👉 "C-2"출력. 'SubB' 가 오버라이딩 한 Execute2()실행
        sub3.Execute3();  // 👉 "B-1", "C-3"출력. 'SubB' 가 오버라이딩 한 Execute3()실행
    }
}
```

<br>
<br>

## 🔔 Abstract vs Virtual vs Interface
1. Abstract<br>

```c#
public abstract class Animal
{
    public abstract void Speak();
    
}
 
public class Dog : Animal
{
    public override void Speak()
    {
        Console.WriteLine("멍멍!");
    }
}
 
  Dog temp = new Dog();
  temp.Speak();//멍멍!
```
<br>

abstarct 키워드를 사용하면 파생 클래스에서 구현해야하는 클래스 및 클래스 멤버를 불완전하게 만들 수 있다.<br>
<br>

-> 여러개의 **파생 클래스에서 공유할 기본 클래스의 공통적인 정의**만 하고<br>
-> 파생클래스에서 abstract 한정자가 달린 것을 모두 **재정의(⭐ 필수)** 해야 한다.<br>
<br>

⭐ **고로 사용 목적은 파생 클래스에서 공유할 기본 클래스의 공통적인 정의를 제공하는것이라 할 수 있다.**<br>
<br>
<br>

2. Virtual<br>

```c#
public class Animal
{
   public virtual void Speak()
   {
        Console.WriteLine("Nothing!");
   }
}
 
public class Dog : Animal
{
    public override void Speak()
    {
        Console.WriteLine("멍멍!");
    }
}
 
Dog temp = new Dog();
temp.Speak();//멍멍!
```
<br>

Virtual 한정자를 사용한 클래스는 **완벽한** 기능을 제공할 수 있다.<br>
고로 파생 클래스에서 ⭐ **필요에 따라서 재정의**(override) 할 수 있지만 필수적으로 재정의 할 필요는 없다.<br>

⭐ **즉 Vritual은 하나의 기능을 하는 완전한 클래스이며, 파생클래스에서 상속해서 추가적인 기능추가 및 virtual 한정자가 달린 것을 재정의해서 사용가능하다.**
<br>
<br>

3. Interface<br>

```c#
public interface Animal
{
    void Speak();
 
    string Name
    {
        get;
        set;
    }
  
}
 
class Dog : Animal
{
    private string name;
 
    public void Speak()
    {
        Console.WriteLine(name + "->멍멍!");
    }
 
    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }
}
 
Dog temp = new Dog();
temp.Name = "흰둥이";
temp.Speak(); //흰둥이->멍멍!
```
<br>

인터페이스는 보통 여러클래스에 공통적인 기능을 추가하기 위해서 사용하며, 클래스와 다르게 다중상속(구현)이 가능하다.<br>
인터페이스는 abstract와 비슷하지만 멤버필드(변수)를 사용할 수 없다. 대신에 프로퍼티는 사용이 가능하다.<br>

아이템을 획득할 때, 획득 처리를 아이템 타입별로 분기하여 작성하는것은 굉장히 비효율적.<br>
-> 각 아이템 컴포넌트들이 획득인터페이스를 구현하게 하자.<br>
<br>

⭐ **보통 Interface는 서로다른 계층이나 타입이라도 같은기능을 추가하고 싶을때 사용한다.<br>
(사람이나 기계가 말을하게(speak)하는 인터페이스를 추가할때)**<br>
(인터페이스 역시 다형성 사용 가능)<br>
<br>
<br>

## 🔔 Interface vs Abstract
둘다 추상화하여 클래스간의 관계를 생성한다는 개념은 동일하지만 사용방식은 다르다.<br> 
⭐⭐**추상 클래스는 그 추상 클래스를 상속받아서 공통 기능을 이용하고, 확장시키는 데 있다.<br>
반면 인터페이스는 함수의 껍데기만 있는데, 함수의 구현을 강제하기 위함이다.<br>
구현을 강제함으로써 구현 객체들이 같은 동작을 할 수 있도록 보장할 수 있게 된다.** ⭐⭐<br>

👉 또한 공통적인 기능을 제공하고 싶다면 구현물을 포함시킬 수 있는 추상클래스를 사용해야 할 것이다.<br>
<br>
<br>

## 🔔 Interface Diamond Problem
위에서 인터페이스는 클래스와 다르게 다중상속(구현)이 가능하다 설명했다.<br>
하지만 인터페이스도 Diamond Problem에서 완전히 자유롭다는 뜻은 아니다.<br>
-> 구현을 포함시킬 수 없기에 무조건 재정의를 하게되어 다이아몬드 문제가 없다.<br>
-> 하지만 특정 언어에서는 인터페이스도 구현물을 포함할 수 있다.<br>
-> 그렇게되면 역시나 다이아몬드 문제가 생기게된다.<br>

그렇다면 동일한 이름의 구현된 메소드를 가진 인터페이스들을 다중 상속한 경우 어떻게 대처해야 하는가?<br>
1. 구현 클래스에서 메서드를 재정의 해버린다.<br>
2. 메서드 재정의 코드에 특정 인터페이스의 메서드로 명시적 위임한다.<br>

https://siyoon210.tistory.com/125 (다이아몬드 문제 참고)<br>
<br>
<br>
