## 🔔 Extension Method
확장 메서드는 C# 3.0부터 추가된 기능으로 ⭐ **미리 정의된 형식에 사용자 정의 함수를 확장(추가)시키는 작업** ⭐을 수행한다.<br>

이 글에서는 예로 string 형식에 Print라는 함수를 확장하는 것을 들것이다.<br>
일반적인 경우라면 **형식에 메서드를 추가하기 위해서는 해당 형식의 소스 코드가 필요하다.**<br>
string 형식은 mscorlib 프로젝트에 포함되어 있으며, 변경 후에는 이 프로젝트를 다시 빌드하여 어셈블리를 만들어야 한다.<br>
하지만, **확장 메서드를 사용한다면 해당 형식의 코드를 변경하지 않고 내 코드에서 어떤 형식이던지 메서드를 확장시킬 수가 있게 된다.**<br>

그럼 도대체 확장 메서드는 어떻게 사용할까?<br>
**확장 메서드는 정의는 정적으로, 사용은 인스턴스 메서드처럼 사용하게 된다.** ⭐<br>
정적 메서드는 해당 메서드를 정의하고 있는 클래스의 개체를 생성하지 않고 사용할 수 있다.<br>

개체를 생성한다는 것은 new 키워드 등을 사용하여 클래스를 초기화하는 것을 의미한다.<br>
단, new 키워드를 직접적으로 사용하지 않고 다른 메서드 등을 통해서 호출하는 경우에도<br>
내부적으로는 new 키워드를 사용하므로 이 경우에 해당한다.<br>

👉 **정적 메서드**<br>
```c#
class ExampleClass {
    public static void StaticMethod() {
        Console.WriteLine("Hello from StaticMethod");
    }

    /* 중략 */
    
    public static void Main(string[] args) {
        ExampleClass.StaticMethod();
    }
}
```
<br>
<br>

반대로 인스턴스 메서드의 경우는 반드시 클래스의 개체 생성 과정을 거친 후에만 사용할 수 있다.<br>

👉 **인스턴스 메서드**<br>
```c#
class ExampleClass {
    public void InstanceMethod() {
        Console.WriteLine("Hello from StaticMethod");
    }

    /* 중략 */
    
    public static void Main(string[] args) {
        ExampleClass.InstanceMethod(); // 호출 불가능
        
        ExampleClass exampleClass = new ExampleClass();
        exampleClass.InstanceMethod();
    }
}
```
<br>
<br>

그럼 확장 메서드는 도대체 어떻게 정의되고 사용되는걸까?<br>
위에서 말했다싶이, "정적 메서드처럼 정의하면서 사용은 인스턴스 메서드처럼 한다".<br>
한 번 코드로 먼저 살펴보도록 하자.<br>

**중요: ⭐ 확장 메서드는 정적 클래스에서만 정의할 수 있다.**<br>
사용할 땐 확장 메서드를 정의하고 있는 클래스가 포함된 네임스페이스를 포함(using)해줌으로서 가능하다.<br>
<br>

👉 **확장 메서드의 정의 및 사용**<br>
```c#
static class ExtensionMethods {
    public static void Print(this string s) {
        Console.WriteLine(s);
    }
}

class ExampleClass {
    public static void Main(string[] args) {
        string text = "Hello from ExtensionMethods";
        
        // 아래의 두 코드는 동일한 결과가 나옵니다.
        "Hello from ExtensionMethods".Print();
        text.Print();
    }
}
```
<br>

정의는 정적 메서드로, 사용은 인스턴스 메서드처럼 한다는 말의 뜻이 이해가 가는가?<br>
위의 코드를 보시면 정적 메서드로 정의하긴 했는데.. 매개변수에 평소 알고 있던 정의와는 다르게 **this가 들어가 있다.**<br>
확장 메서드는 정적 메서드처럼 정의하되, **첫번째 매개변수에는 어떤 형식의 확장 메서드인지를 결정하게 된다.<br>
⭐ this ⭐ 형식 매개변수_이름 의 형태인데, 위 코드에서는 this string s 부분이 해당된다.**<br>
확장 메서드를 추가하기 전에는 string 형식에 Print 라는 메서드가 없지만,<br>
확장 메서드를 추가한 이후에는 string 형식에 Print 라는 메서드가 생겨있는 것을 볼 수 있다.<br>
<br>

![확장메서드](https://user-images.githubusercontent.com/43705434/131138415-cfa98531-2ea6-4957-b633-38b30dfd9ebc.PNG)<br>

미리 정의된 메서드와 확장 메서드는 아이콘으로도 구분되어 있다.<br>
미리 정의된 메서드가 보라색 정육면체 아이콘이고, 확장 메서드는 아래 화살표가 추가되어 있다.<br>

그럼 여기서 의문점이 하나 생길 수 있는데, 기존 정의된 메서드와 동일한 이름을 갖는 확장 메서드는 어떻게 되는가?<br>
매개 변수의 형식과 갯수까지 같을 경우 기존 정의된 메서드가 실행된다.<br>
확장 메서드의 우선 순위는 인스턴스 메서드보다 낮기 때문에 동일한 메서드 이름을 사용하는 것은 피해야 한다.<br>

👉 **정리해서 결론을 말하자면, 확장 메서드는 기존 형식의 코드 변경 없이 사용자 임의로 만든 메서드를<br>
대상 형식에 추가시킬 수 있도록 도와주는 메서드이다. 레고 블럭처럼 이미 완성된 작품에 덧붙일 수 있는 것이다.** ⭐⭐⭐<br>
다만, 과하게 사용한다면 혼란을 야기할 수 있다.<br>
<br>
<br>

## 🔔 참조링크
https://www.csharpstudy.com/CSharp/CSharp-extension-method.aspx <br>
https://slaner.tistory.com/189 <br>
