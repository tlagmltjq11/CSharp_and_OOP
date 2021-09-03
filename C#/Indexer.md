## 🔔 Indexer
C# Indexer는 **클래스 객체의 데이터를 배열 형태로 인덱스를 써서 엑세스할 수 있게 해준다.**<br>
즉, **클래스 객체는 배열이 아님에도 불구하고, 마치 배열처럼 []를 사용하여 클래스 내의 특정 필드 데이타를 엑세스하는 것이다.**<br>
다음은 Indexer를 이용하여 문자 데이타를 클래스 객체에 넣은 예이다.<br>

-> ⭐⭐ **한마디로 인덱스를 이용해서 객체 내의 데이터에 접근하게 해주는 프로퍼티!** ⭐⭐<br>
<br>

```c#
MyClass cls = new MyClass();
cls[0] = "First";
```
<br>
<br>

## 🔔 C# 인덱서 정의
C# Indexer는 **특별한 문법인 this[] 를 써서 클래스 Property 처럼 get과 set을 정의한다.** ⭐<br>
클래스 내부의 **어떤 데이터를 리턴하는지는** 클래스 디자인시 **필요에 따라** 정하게 될 것이고,<br>
리턴 데이터 타입도 여러 가지로 지정할 수 있다.<br>

입력 파라미터인 **인덱스도 여러 데이타 타입을 쓸 수 있는데,<br>
주로 int 나 string 타입을 사용하여 인덱스값을 주는 것이 일반적이다.**<br>
아래 예제는 간단한 인덱서 예로서, int 인덱스를 받아 배열의 데이타를 찾아 정수를 리턴하는 예이다.<br>
<br>

```c#
class MyClass
{
   private const int MAX = 10;
   private string name;

   // 내부의 정수 배열 데이타
   private int[] data = new int[MAX];

   // 인덱서 정의. int 파라미터 사용
   public int this[int index] 
   {
      get
      {            
         if (index < 0 || index >= MAX)
         {
            throw new IndexOutOfRangeException();
         }
         else
         {
            // 정수배열로부터 값 리턴
            return data[index];
         }
      }
      set
      {
         if (!(index < 0 || index >= MAX))
         {
            // 정수배열에 값 저장
            data[index] = value;
         }
      }
   }
}

class Program
{
   static void Main(string[] args)
   {
      MyClass cls = new MyClass();

      // 인덱서 set 사용
      cls[1] = 1024; ⭐

      // 인덱서 get 사용
      int i = cls[1]; ⭐
   }
}
```
<br>
<br>

## 참조링크
http://www.csharpstudy.com/CSharp/CSharp-indexer.aspx <br>
