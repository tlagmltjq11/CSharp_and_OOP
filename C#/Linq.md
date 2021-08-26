## 🔔 Linq
LINQ란 **특정 데이터들에서 Query를 하여 데이터를 빠르고 편리하게 추출하는 방식이라 할 수 있다.** ⭐<br>
해당기능은 C# 3.0부터 추가가 되기 시작한 문법이다. 기본적으로 람다표현식을 사용하여 간결하고 가독성 좋게 작성 가능하다.<br>
Query를 하는데에는 SQL을 사용한다.<br>

이 강력한 기능을 통해 **복잡한 구문을 좀 더 간단하게 필터링하거나 정렬** ⭐ 할 수 있다는 등의 특징을 지니고 있다.<br>
SQL에서 가장 많이 사용하는 문법은 다음 4가지 이다.<br>

👉 from : 어떤 데이터에서 찾을 것인가<br>
👉 where : 어떤 조건으로 찾을 것인가<br>
👉 order by : 어떤 항목을 기준으로 정렬할 것인가<br>
👉 select : 어떤 항목을 추출할 것인가<br>
이러한 쿼리식 from, where, orderby, select 등은 System.Linq에 정의되어 있는 **IEnumerable(T)의 확장 메소드**를 통해 사용가능한 것<br>
-> 그렇다는건 아마 IEnumerable 을 구현한 컬렉션으로만 Linq를 사용할 수 있다는 의미이지 않을까 싶다.<br>
<br>

문장을 서술 하듯 질의를 하기 때문에 for와 if문을 사용하는 방식보다 가독성이 좋아 실수를 줄이고 유지보수가 쉽다.<br>
-> **속도면에서는 조금 뒤쳐지지만 편리성과 간결성이 굉장히 높아 자주 사용된다.**<br>
<br>

👉 **코드의 간결성**<br>
```c#
  var women =
              from          woman in womanList   // womanList에서 (여자인가?)
              where        woman.age > 20        // 20세가 넘는 성인을 (성인인가?)
              orderby     woman.age              // 나이 순으로 정렬하여 (나이가 어린가?)
              select        woman;               // 배열 데이터로 추출한다.
```
<br>

만약 이를 LINQ없이 단순 코드로만 작성하면 다음과 같다.<br>
<br>
 
```c#
  List<Woman> women = new List<Woman>();
  
  // 여자 리스트에서 20세 이상 성인 추출
  foreach (Woman woman in womanList)
  {

       if (woman.age > 20)
          Womwn.add(woman);
  }
  
  // 어린 나이순으로 정렬
  Women.Sort( (w1, w2) => w1.age - w2.age; );

  // 추출된 성인여자 데이터를 출력
  foreach (var woman in Women)
        Console.WriteLine("{0}, {1}", woman.name, woman.age);
```
<br>

상당히 많은 코드를 생략했는데도 이정도다.<br>
**LINQ를 쓰면 얼마나 코드가 간결해지는지 실감할 수 있을 것이다.**<br>
<br>
<br>

👉 자세한 문법과 사용법은 다음 링크 참조.<br>
https://blog.hexabrain.net/262<br>
<br>
<br>

## 🔔 참조링크
https://hijuworld.tistory.com/56 <br>
https://cnk24.tistory.com/22 <br>
https://blog.hexabrain.net/262 <br>
