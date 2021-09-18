## 🔔 as & is
결론부터 말하자면 부모 클래스를 자식 클래스에 대입하는 경우가 발생하고,<br>
그러한 행위를 도와주는 것이 AS, IS 연산자다.<br>
<br>

👉 **as 연산자는 객체를 캐스팅 할 때 사용하는 연산자이다.** ⭐<br>
캐스팅에 성공하면 캐스트 결과를 리턴하고, 실패하면 null을 리턴한다.<br>

이와는 대조적으로 캐스팅(Casting)을 사용하면,<br>
변환이 실패했을 때 Exception을 발생시키게 되는데,<br>
이를 catch하지 않으면 프로그램을 중지하게 된다.<br>

**고로 as 연산자를 이용하여 캐스팅함으로써, 에러의 발생을 막을 수 있다.** ⭐⭐<br>
<br>

**단 as 연산자는 참조타입간의 캐스팅에만 사용 가능하다.** ⭐⭐⭐<br>
<br>
<br>

👉 **is 연산자는 캐스팅 성공유무를 확인할 수 있는 연산자이다.<br>
고로 캐스팅이 가능하다면 true, 그렇지 않다면 false를 리턴한다.** ⭐<br>
<br>

```c#
Mammal mammal = new Dog();
Dog dog;

//is로 먼저 검사 후 안전하게 캐스팅
if(mammal is Dog)
{
  dog = (Dog)mammal;
  dog.Bark();
}


Mammal mammal2 = new Cat();

//as로 먼저 형변환 시도 후 null 검사
Cat cat = mammal2 as Cat;
if(cat != null)
{
  cat.Meow();
}
```
<br>
<br>

## 🔔 참조링크
https://dybz.tistory.com/94 <br>
https://www.csharpstudy.com/CSharp/CSharp-inheritance.aspx <br>
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=beaqon&logNo=221301069327 <br>
