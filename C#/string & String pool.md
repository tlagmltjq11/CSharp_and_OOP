## string
C#에서는 다른 언어에서와 마찬가지로 문자열을 문자배열(char[])로 사용할 수 있다.<br>
하지만 C#에서 기본 제공하는 string 키워드를 사용하여 문자열 변수를 선언할 수도 있다.<br>
string 키워드는 System.String 클래스와 동일<br>
<br>
<br>

1. string 객체 만들기
string 객체를 만드는 방법은 여러가지 존재한다.<br>
**string은 참조 타입이지만 new 를 사용하지않고도 생성 할 수 있다.**<br>
<br>

```c#
namespace MyStringApplication {
    class MyString {
        static void Main(string[] args) {
            string str1 = "HELLO";
            Console.WriteLine("str1 = {0}", str1);
            
            string str2 = new string("HELLO2");
            Console.WriteLine("str2 = {0}", str2);
            
            char[] letters = {'H', 'E', 'L', 'L', 'O', '3');
            string str2_2 = new string(letters);
            Console.WriteLine("str2_2 = {0}", str2_2);
 
            string str3 = str1 + str2;
            Console.WriteLine("str3 = {0}", str3);
            
            string arr = {"HELLO", "SEMOG", "!!");
            string str4 = String.Join(" ", arr);
            Console.WriteLine("str4 = {0}", str4);
        }
    }
}
```
<br>

2. String 클래스 속성<br>
- String 클래스에는 다음 두가지의 속성이 존재한다.<br>
1) Chars : 현재 String 객체의 지정된 위치에 있는 Char 객체를 반환한다.<br>
2) Length : 현재 String 객체의 문자 수(길이)를 반환한다.<br>
<br>

3. String 클래스 메소드<br>
- String 클래스에는 문자열 객체를 작업하는데 도움이 되는 다양한 메소드(함수)들이 존재한다.<br>
- 다음 메소드들은 가장 일반적으로 사용되는 메소드들의 리스트다.<br>

1) Compare()<br>
```c#
public static int Compare(string srt1, string str2);
```
<br>

- 두 String 객체를 비교하여 정렬 순서에 따라 상대위치를 나타내는 정수를 반환한다.<br>
- 정렬 순서는 ABC 순이며, 가장 앞 문자부터 비교한다.<br>
<br>

2) Concat()<br>
```c#
public static string Concat(string str1, string str2);
```
<br>

- 두 문자열 객체를 연결하여 반환한다.<br>
<br>

3) Contains()<br>
```c#
public bool Contatins(string str);
```
<br>

- 문자열 내에서 지정된 String 객체가 존재하는지 여부를 나타내는 값을 반환한다.<br>
<br>

4) Copy()<br>
```c#
public static string Copy(string str);
```
<br>

- 지정된 문자열의 복사값으로 새 String 객체를 반환한다.<br>
<br>

5) Equals()<br>
```c#
public static bool Equals(string str1, string str2);
```
<br>

- 지정된 두 String 객체가 동일한지 여부를 반환한다.<br>
<br>

6) IndexOf()<br>
```c#
public int IndexOf(char ch);
```
<br>

- 현재 문자열에서 지정된 문자(유니코드)중 처음으로 나타나는 위치의 인덱스를 반환한다.<br>
- 매개변수가 문자열(string) 객체인 함수도 오버로딩되어있다.<br>
<br>

7) Replace()<br>
```c#
public string Replace(string str1, string str2);
```
<br>

- 현재 문자열 객체에 있는 지정된 문자열을 모두 지우고 새로운 문자열로 변경한 문자열 객체를 반환한다.<br>
<br>

8) Split()<br>
```c#
public string[] Split(params char[] seperator);
```
<br>

- 현재 문자 배열 요소로 구분된 문자열 객체의 하위 문자열을 포함하는 문자열 배열을 반환한다.<br>
- 매개변수 기준으로 문자열을 쪼갠다고 생각하면 된다.<br>
<br>

9) Trim()<br>
```c#
public string Trim();
```
<br>

- 현재 String 객체에서 앞, 뒤 공백문자를 모두 제거한다.<br>
- 문자열 사이의 공백은 제거되지 않는다.<br>
<br>
<br>

## string은 불변클래스(Immutable Class)다
**즉 string은 참조형식을 이용하지만 불변 클래 기반으로 이루어진 클래스이다.**<br>
불변클래스란 인스턴스 생성 후 인스턴스가 가지는 **값을 변경하지 못하는 클래스를 의미한다.**<br>
즉 객체에 넣은 값은 인스턴스가 없어질 때 까지 값을 계속 유지하게 되는 클래스라는 것이다.<br>

다음은 string 클래스의 메모리를 처리하는 방식이다.<br>
```c#
class Program
{
  static void Main()
  {
    string s = "Hello"; // 1번 과정
    string ss = s; // 2번 과정
    
    s = s + " " + "and Welcome"; // 3번 과정
  }
} 
```
<br>

위의 코드에서 1번 과정을 거치게 되면 스택에는 s변수의 값(Hello)에 대한 메모리 주소를 갖고<br>
Heap에는 해당 주소에 맞게 Hello라는 값이 들어가게 된다.<br>

1번 이미지

2번 과정을 거치면 ss변수에 대한 스택메모리에는 Hello의 값을 갖고 있는 주소를 갖게되고<br>
이에 따라 ss의 값은 s의 값과 동일한 위치를 참조하게 된다.(stack 메모리 주소 단순 복사)<br>

이미지 2

**하지만 s에 새로운 값을 넣게되면 어떨까? s에 새로운 값을 넣으면 힙 메모리의 새로운 장소에 값이<br>
할당되고 s에 대한 스택 메모리 값은 새로 생긴 힙 메모리의 주소를 참조하게 된다.**<br>
아래의 그림을 통해 확인할 수 있듯이 s는 6000번지를 참조하게 되고 힙 메모리의 6000번지에는<br>
"Hello and Welcome"이라는 문자열이 저장되게 된다. 따라서 s는 새로운 문자열을<br>
ss는 기존의 "Hello" 문자열에 대한 주소를 참조하고 있는 것이다.<br>

이미지 3

## string은 왜 불변클래스일까?
그러면 이제 본론으로 들어와서, Java에서 String은 왜 불변일까?에 대한 이야기를 해보겠습니다.
자바가 String을 불변으로 처리하면서 얻는 이점에 대해 파악한다면, 왜 불변성을 갖게 하는지에 대해 이해할 수 있을 것 같습니다.
앞서 언급한 바와 같이 Java는 String을 String constant pool에서 관리를 합니다. 그리고 이것이 가능한 이유가 바로 Java에서 String이 불변이기 때문입니다. String pool을 통해 String을 관리함으로써 Java는 Runtime에서 Heap 영역의 많은 메모리를 절약할 수 있습니다. 왜냐면 같은 값을 갖는 String에 대해 같은 메모리를 참조하게 할 수 있기 때문입니다. 만약 String이 불변이 아니었다면, 해당 메모리에 값이 언제 바뀔지 알 수 없기 때문에 String pool 형태로 관리할 수 없게 됩니다. 예를 들어 a, b, c라는 String 변수가 모두 같은 메모리를 가리킬 때 a의 값을 바꿔버리면 b와 c의 값도 바뀌는 문제가 발생할 수 있습니다.
String이 불변이 아니라면 보안상의 문제를 야기할 수 있습니다. 예를 들어, DB의 username과 password 라던가, 소켓 통신에서 host와 port에 대한 정보가 String으로 다루어지기 때문에 String이 불변이라야 해커의 공격으로부터 값이 변경되는 것을 예방할 수 있습니다.
String이 불변이기 때문에 멀티 쓰레딩 환경에서 안전(thread-safe)합니다. 값의 변경 가능성이 없기 때문에 멀티 쓰레딩 환경에서 동기화 문제를 걱정하지 않아도 됩니다.
Java는 String의 hashcode를 생성 단계에서부터 캐싱합니다. 따라서 String의 hashcode는 쓰일 때마다 매번 계산되지 않습니다. 이 특징은 특히 객체의 hashCode를 Key로 사용하는 HashMap의 경우에 효과를 발휘합니다. 다른 객체는 키로 쓰일 때마다 hashCode를 계산하는데 비해 String은 캐싱을 하고 있기 때문에 다른 객체를 Key로 했을 때보다 String을 Key로 했을 때 더 빠른 속도로 사용할 수 있습니다. Java에서 String의 hashcode가 캐싱될 수 있는 이유가 바로 String이 불변이기 때문에 가능한 것입니다.
이처럼 Java는 String을 불변으로 관리함으로써 많은 이점을 얻습니다. 그리고 이는 Java의 String이라는 클래스의 특별함이기도 한데요. 결국엔 String도 하나의 클래스이기 때문에 우리는 우리가 정의한 커스텀 클래스를 불변 클래스로 만들 수도 있습니다. 이에 관해서도 추후에 포스팅하도록 하겠습니다.


하지만 문자열에 새로운 값을 넣을 때 마다 메모리가 새로 할당되어 값이 저장되기 때문에<br>
자칫 남발했다가는 수많은 가비지를 생성하고 성능에 문제를 끼쳐 속도를 저하시킬 수 있다.<br>
이러한 불변 타입의 string 클래스가 발생시키는 가장 큰 문제는 문자열을 더할 때다.<br>

```c#
string txt = "Hello World";

for(int i = 0; i < 300000; i++)
{
	txt = txt + "1";
}
```
<br>

위와 같은 코드를 실행하는데 대략 27초가 걸린다고 한다.<br>
1. Heap 영역에 "Hello World" 문자열을 담은 공간을 할당한다.<br>
2. 스택에 있는 txt 변수에 1번 과정에서 할당된 Heap의 주소를 저장한다.<br>
3. txt + "1" 동작을 수행하기 위해 txt.Length + "1".Length에 해당하는 크기의 메모리를 힙에 할당한다.<br>
->그 메모리에 txt 변수가 기리키는 힙의 문자열과 "1" 문자열을 복사한다.<br>
4. 다시 스택에 있는 txt 변수에 3번 과정에서 새롭게 할당된 힙의 주소를 저장한다.<br>
5. 3번과 5번의 과정을 30만 번 반복한다.<br>
-> 런타임시에 생성되는 문자열은 기본 Heap 메모리에 할당된다.<br>
<br>

문제는 3번 과정에 있다. 끊임없이 메모리를 할당하고 이전의 문자열을 다시 복사하는 과정을<br>
거치기 때문에 실행 시간이 27초나 걸린 것이다.<br>
-> 심지어 가비지가 되어 GC의 호출을 야기한다.<br>

이러한 문제를 해결하기 위해서는 StringBuilder 클래스를 사용해야 한다.<br>
```c#
string txt = "Hello World";

StringBuilder sb = new StringBuilder();
sb.Append(txt);

for(int i = 0; i<300000; i++)
{
	sb.Append("1");
}

string newText = sb.ToString();
```
<br>

이 코드를 실행하는 데는 3ms가 채 걸리지 않는다.<br>

1. StringBuilder는 내부적으로 일정한 양의 메모리를 미리 할당한다.<br>
2. Append 메서드에 들어온 인자를 미리 할당한 메모리에 복사한다.<br>
3. 2번 과정을 30만번 반복한다. Append로 추가된 문자열이 미리 할당한 메모리보다 많아지면<br>
-> 새롭게 여유분의 메모리를 할당한다.<br>
4. ToString 메서드를 호출하면 연속적으로 연결된 하나의 문자열을 반환한다.<br>

즉, 잦은 메모리 할당과 복사가 없어졌기 때문에 그만큼 성능이 향상된 것이다.<br>
-> **StringBuilder는 수정할 수 있는 클래스이기 때문에 값이 추가/수정/삭제 되는 형태이기 때문이다.**<br>
이 때문에 문자열을 연결하는 작업이 많을 때는 반드시 StringBuilder를 사용하는 것을 권장한다고 한다.<br>
<br>
<br>

## Global String Pool (Literal String Pool)
컴파일하고 빌드를 하면 많은 정보들이 생성된다.<br>
특히 문자열은 메모리 관리차원에서 Intern Pool(Heap Memory에 존재)이라는 곳에 등록되는데,<br>
이곳에 등록되는 문자열은 ‘리터럴 문자열’만 저장된다.<br>

리터럴 문자열이란, 직접 소스 코드에서 “Hello World” 처럼 쌍따옴표로 묶어서 코딩한 문자열 들이다.<br>
이 문자열들만 골라서 Runtime시 Intern Pool에 등록해놓고, 문자열 객체를 여러개생성하지 않도록 한다.<br>
-> 즉 new 키워드를 이용해서 런타임시에 생성하는 문자열은 포함이 되지 않는다.<br>
-> 메모리는 힙에 할당되고 문자열 값 자체만 인턴풀에 등록하기도 함. 혹은 Intern 메소드로 직접 등록가능<br>

```c#
string s1 = "Hello";
string s2 = "Hello";
string s3 = "Hello";
string s4 = "Hello";
string s5 = "Hello";
```
<br>

위와 같이 코딩하면 Hello 객체는 런타임에서 5개가 생성되지 않고<br>
모두 참조하는 주소가 Intern Pool을 가리킨다.<br>
ReferenceEqual 메서드를 통해 주소 비교를 할 수 있으며, 실행하면 모두 참조 주소가 같다고 나온다.<br>
<br>

하지만 런타임에서 생성해낸 똑같은 문자열일 경우 리터럴 문자열 취급을 하지 않고v
새로운 객체를 만든 것이기에 다른 주소를 참조한다. 아래의 코드를 보자.<br>

```c#
string s1 = "Hello World";
string s2 = string.Concat("Hello", " World");
```
<br>

이 경우 ReferenceEquals(s1, s2)는 false 결과이다.<br>
s1의 경우 코딩을 쌍따옴표로 묶은 리터럴 문자열 취급이며,<br>
s2 문자열은 새로 문자열을 조합해서 새로운 객체를 리턴했으므로<br>
리터럴 문자열이 아닌 일반적인 런타임 문자열 객체가 된다.<br>
따라서 이 경우에는 Hello World 문자열 객체가 2개가 생긴다.<br>

또한 Intern Pool에 등록되는 리터럴 문자열은 Managed Heap에 할당되지 않으며,<br>
그렇기 때문에 당연히 Garbage Collector의 대상이 아니다.<br>
따라서 프로그램이 끝나는 순간까지 해제되지 않는다.<br>

리터럴 문자열은 아니지만 자주 사용될 것 같은 문자열을 Intern Pool에 등록하는 방법이 있는데,<br>
string.Intern 메서드를 사용하는 것이다. 자주 사용하는 문자열 객체를 Intern Pool 에 등록하고 사용한다면<br>
임시 문자열 객체가 지속적으로 생성되는 일은 없을 것이며 따라서 가비지 컬렉션이 그만큼 할 일이 줄게 될 것이다.<br>
그렇다고 Intern Pool에 문자열을 엄청나게 등록해놓고 사용하는 행동은 안하는 것이 좋은 것이, 언급한대로<br> Garbage Collection의 대상이 아니기 때문에 쓸데없이 메모리를 차지하는 것이고, 메모리를 차지하고 있는만큼<br> Garbage Collector가 메모리 부족현상을 빨리 느껴, Garbage Collection을 그만큼 더 빈번하게 할 것이다.<br>
그럼 Garbage Collection Thread가 동작하는 동안 모든 Thread가 일시 정지하게 되고, 이는 곧 성능저하다.<br>
<br>

Java7 이후에 String Pool은 Heap 영역에 저장되어 GC 대상이 되었습니다.
-> c#도?
출처: https://jinseongsoft.tistory.com/365 [진성 소프트]

이렇게 Global Pool에 String List를 저장하는 장점은 두가지 이다.

1) 메모리 절약 / 매번 String Literal이 생성될 때마다 메모리를 생성시키지 않아도 되고, 동일 String Literal에 대해서 하나의 String Literal만 가지면 된다. (Immutable이기 때문에 변경 될 경우 새로 생성한다.)

2) Compare 연산이 빠르다. (String Pool의 String Literal을 저장하고 있는 String 변수들은  Reference가 동일하기 때문에 Deep Comparison을 하지 않고 그냥 Refrence만 비교하는 Shallow Comparison만 필요 하므로 결과 값을 빠르게 알 수 있다.)

## 참조링크
https://yeolco.tistory.com/140 <br>
https://guslabview.tistory.com/187 <br>
https://andjjip.tistory.com/197 <br>
https://readystory.tistory.com/139 <br>
https://christian289.github.io/dotnet/Intern-Pool(Literal-String-Pool)/ <br>
