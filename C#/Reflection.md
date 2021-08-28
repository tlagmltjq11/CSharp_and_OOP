## Refleciton
.NET Reflection은 .NET **객체의 클래스 타입, 메서드, 프로퍼티, 필드 등의 메타 정보를 런타임 중에 알아내는 기능을 제공한다.**<br>
또한, 이러한 메타 정보를 얻은 후, **직접 메서드를 호출하거나 프로퍼티를 변경하는 등의 작업도 가능하다.**<br>
물론 객체에서 메서드를 직접 호출하는 경우가 더 빠르겠지만, 어떤 경우는 런타임중에 이런 메타 정보가 동적으로 알아낼 필요가 있다.<br>
예를 들어, 테스트 어셈블리에 있는 테스트 클래스들의 Public **메서드를 선별해서 이를 동적으로 호출**하는 경우라든가,<br>
특정 클래스 안에 **지정된 이름의 멤버가 있는지 판단하는 경우** 등등에 .NET Reflection이 활용될 수 있다.<br>

타입 정보는 보통 컴파일 중에만 사용되며 컴파일러에 의해 기계어로 바뀌고 사라지는 것이 일반적이지만<br>
**C#은 컴파일된 결과 코드뿐만 아니라 타입에 대한 메타 데이터를 실행 파일에 같이 기록해놓기 때문에<br>
런타임 중에도 정보를 조사할 수 있다.**<br>
<br>
<br>

## Type 얻기
리플렉션을 **이용하기 전에 타입을 얻어야 하는데** 다음 코드와 같은 방법으로 타입(Type) 객체를 얻을 수 있다.<br>
```c#
//1. 객체로 접근하는 방법
string s = "jabook";
Type t1 = s.GetType();
Console.WriteLine(t1);           //결과 : System.String
 
//2. 런타임 시 지정된 이름으로 접근하는 방법
Type t2 = Type.GetType("System.String");
Console.WriteLine(t2);       //결과 : System.String
        
//3. 클래스 타입으로 접근하는 방법
Type t3 = typeof(System.String);
Console.WriteLine(t3);       //결과 : System.String
```
<br>

GetType() 메서드를 이용해서 객체의 형식 정보를 얻어낼 수 있다.<br>
GetType() 메서드는 Type 형식의 결과를 반환한다.<br>

Type 형식은 다음과 같은 데이터 형식의 정보를 담고있다.<br>
* 형식 이름
* 소속되어 있는 어셈블리 이름
* 프로퍼티 목록
* 메서드 목록
* 필드 목록
* 이벤트 목록
* 인터페이스의 목록
<br>
<br>

## Reflection을 이용한 프로퍼티 설정
.NET 클래스를 GetType() 등의 메서드를 써서 알아낸 후,<br>
클래의 특정 속성정보를 알기 위해 **Type.GetProperty()** 라는 메서드를 호출한다.<br>
클래스가 가진 모든 프러퍼티를 가져오기 위해서는 **GetProperties()** 라는 메서트를 호출하면 된다.<br>
```c#
class Program
{
    static void Main(string[] args)
    {
        MyClass1 m1 = new MyClass1();
        SetDefaultName(m1);
        Console.WriteLine(m1.Name);
    }
    
    static void SetDefaultName(object myObject)
    {
        // Name이라는 속성이 있는지?
        PropertyInfo pi = myObject.GetType().GetProperty("Name");

        // 있으면 속성값 설정
        if (pi != null)
        {
            pi.SetValue(myObject, "Lee", null);
        }
    }

}

class MyClass1
{
    public string Name { get; set; }
}
```
<br>
<br>

## Reflection을 이용한 메서드 호출
특정 메서드 정보를 얻기 위해서 **Type.GetMethod()** 를 호출하고,<br>
모든 메서드 정보를 가져오기 위해서는 **GetMethods()** 를 호출한다.<br>
invoke로 호출함.<br>
```c#
class Program
{
    static void Main(string[] args)
    {
        MyClass1 m1 = new MyClass1();
        MyClass2 m2 = new MyClass2();
        MyClass3 m3 = new MyClass3();

        MyFunc(m1);
        MyFunc(m2);
        MyFunc(m3);
    }

    static void MyFunc(object myObject)
    {
        // 해당 객체가 MyMethod라는 메서드를 가지고 있는지
        MethodInfo mi = myObject.GetType().GetMethod("MyMethod");
        if (mi != null)
        {
            // 만약 메서드가 있으면, 호출
            mi.Invoke(myObject, null);
        }
        else
        {
            Console.WriteLine(myObject.GetType().Name +
             ": MyMethod not found");
        }
    }

}

// 아래는 테스트 클래스들
class MyClass1
{
    public void MyMethod()
    {
        Console.WriteLine("MyClass1.MyMethod");
    }
}

class MyClass2
{
    public void MyMethod()
    {
        Console.WriteLine("MyClass2.MyMethod");
    }
}

class MyClass3
{
    public void DifferentMethod()
    {
        Console.WriteLine("MyClass3.DifferentMethod");
    }
}
```
<br>
<br>

## Reflection을 이용한 클래스 객체 생성
**클래스 타입을 알 때 .NET Reflection을 이용해서 해당 클래스의 객체를 생성할 수 있다.**<br>
이는 컴파일시에 직접 new를 사용하는 방식이 아니라, 클래스 타입명을 문자열로 받아들여<br>
런타임시에 해당 클래스의 객체를 생성할 수 있는 것을 뜻한다.<br>
또한, 어떤 객체를 받아들여 해당 타입을 얻은 후에 (ex: obj.GetType()),<br>
이 타입의 또 다른 객체를 생성하는 것도 가능하다.<br>

아래의 예제는 해당 Customer라는 클래스명을 사용하여 런타임시에 해당 객체를 생성하는 예이다.<br>
Type.GetType()을 이용하여 해당 타입을 알아내고 (주의: 클래스명 앞에 네임스페이스를 붙여야 한다),<br>
이어 **Activator의 CreateInstance()를 사용하여 실제 클래스 객체를 생성한다.**<br>
```c#
namespace MyNamespace
{
    using System;
    using System.Diagnostics;

    public class Class1
    {
        public void Run()
        {
            // 네임스페이스와 클래스명 함께 
            Type customerType = Type.GetType("MyNamespace.Customer");

            // Type으로부터 클래스 객체 생성
            object obj = Activator.CreateInstance(customerType);

            // 생성된 객체 사용예
            string name = ((Customer)obj).Name;
            Debug.WriteLine(name);  // No name
        }
    }

    public class Customer
    {
        public Customer()
        {
            this.Name = "No name";
        }
        public int Id { get; set; }
        public string Name { get; set; }
    }
}
```
<br>
<br>

**Generic 타입으로부터 객체 생성**<br>
클래스 타입이 확정되지 않은 Generic Type인 경우에는 (ex: MyFilter<T>) 파라미터 T가 정해지지 않으면 Activator로 객체를 생성할 수 없다.<br>
그것은 Generic Type 자체로는 클래스가 되지 못하기 때문인데, 이 경우 먼저 Generic의 T 파라미터 타입을 GetGenericArguments()를 써서 알아낸 후,<br>
MakeGenericType(T)을 사용하여 구체적인 클래스를 만들어야 한다.<br>
  
아래 예제는 MyFilter라는 Generic 타입이 object로 Run()함수에 전달되었을 때, T 파라미터를 알아내고 Generic으로부터 객체를 생성하는 예를 보여주고 있다.<br>
```c#
  using System;
using System.Collections.Generic;
using System.Diagnostics;

public class Class2
{
    public Class2()
    {
        MyFilter<int> filter = new MyFilter<int>();
        Run(filter);
    }

    public void Run(object filter)
    {
        // Type명 비교
        if (filter.GetType().Name == typeof(MyFilter<>).Name)
        {
            // Generic의 T 파라미터 타입 가져오기 : int
            Type genArgType = filter.GetType().GetGenericArguments()[0];

            // MyFilter<>에 int를 적용하여 실제 타입 확정
            Type actualType = typeof(MyFilter<>).MakeGenericType(genArgType);

            // 실제 타입으로부터 객체 생성
            object obj = Activator.CreateInstance(actualType, true);

            Debug.WriteLine(obj.GetType().Name); //MyFilter`1
        }
    }
}

public class MyFilter<T>  where T : struct
{
    private List<T> _elements;        

    public MyFilter()
    {
        _elements = new List<T>();
    }

    public MyFilter(List<T> elements)
    {
        _elements = elements;
    }
}
```
<br>
<br>

## 추가 예제
아래 코드는 객체로 접근하여 타입을 얻은 다음, Animal 클래스의 런타임 중에 리플렉션을 사용한 예시다.<br>
```c#
using System; 
using System.Collections.Generic; 
using System.Linq; 
using System.Text; 
using System.Reflection; 
using System.Threading.Tasks; 
 
namespace ConsoleApplication43 
{ 
    class Animal 
    { 
        public int age; 
        public string name; 
        
        public Animal(string name, int age) 
        { 
            this.age = age; 
            this.name = name; 
        } 
        
        public void eat() 
        { 
            Console.WriteLine("먹는다!"); 
        } 
 
        public void sleep() 
        { 
            Console.WriteLine("잔다!"); 
        } 
    } 
 
    class Program 
    { 
        static void Main(string[] args) 
        { 
            Animal animal = new Animal("고양이", 4); 
            Type type = animal.GetType(); 
            
            ConstructorInfo[] coninfo = type.GetConstructors(); 
            Console.Write("생성자(Constructor) : "); 
            foreach (ConstructorInfo tmp in coninfo) 
                Console.WriteLine("\t{0}", tmp); 
            Console.WriteLine(); 
 
            MemberInfo[] meminfo = type.GetMethods(); 
            Console.Write("메소드(Method) : "); 
            foreach (MethodInfo tmp in meminfo) 
                Console.Write("\t{0}", tmp); 
            Console.WriteLine(); 
 
            FieldInfo[] fieldinfo = type.GetFields(); 
            Console.Write("필드(Field) : "); 
            foreach (FieldInfo tmp in fieldinfo) 
                Console.Write("\t{0}", tmp); 
            Console.WriteLine(); 
        } 
    } 
}
```
<br>

결과<br>
생성자(Constructor) : Void .ctor(System.String, Int32)<br>
메소드(Method) :  Void eat()      Void sleep()    System.String ToString()<br>
        Boolean Equals(System.Object)   Int32 GetHashCode()     System.Type GetType()<br>
필드(Field) :   Int32 age       System.String name<br>
계속하려면 아무 키나 누르십시오 . . .<br>
<br>
<br>

## 참조링크
https://blog.daum.net/save_us_222/71 <br>
http://www.csharpstudy.com/Practical/Prac-reflection.aspx <br>
https://www.csharpstudy.com/Practical/Prac-reflection2.aspx <br>
