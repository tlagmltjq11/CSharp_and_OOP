## 🔔 Casting
형변환은 데이터 타입을 변환하는 것을 의미하는데, 암묵적 형변환과 명시적 형변환으로 나뉜다.<br>
<br>

👉 암묵적 형변환<br>
컴파일러가 자동으로 형변환을 하는 것을 의미하며, 데이터가 손실될 우려가 없는 경우에 사용된다.<br>

```c#
int a = 10;
float b;

b = a;
```
<br>

👉 명시적 형변환<br>
사용자가 직접 형태를 변환하는 것으로, 주로 큰 데이터 타입을 작은 데이터 타입으로 변환할 때 사용된다.<br>
-> 데이터의 손실은 사용자의 몫.<br>

```c#
int a;
float b = 10.324f;

a = (int)b;
```
<br>

👉 Up Casting<br>
서브 클래스의 객체가 슈퍼 클래스 타입으로 형변환 되는 것을 의미한다.<br>

```c#
Student stu = new Student("shs");
Person per = stu; //업캐스팅
```
위 코드에서 슈퍼클래스 타입의 레퍼런스 per이 서브클래스 객체 stu를 가리키도록 하는 것.<br>
-> **Person 클래스 멤버만 접근 가능**<br>
<br>
<br>

👉 Down Casting<br>
업캐스팅 된 것을 다시 원상태로 돌리는 것을 의미한다.<br>

```c#
Person per = new Student("shs");
Student stu = (Student)per; 
```
다운 캐스팅은 **명시적인 형변환을 통해서 가능하며 업캐스팅이 선행되어야 한다는 점을 유의하자.**<br>
<br>
<br>
