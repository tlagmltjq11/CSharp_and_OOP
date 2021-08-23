## IEnumerable
컬렉션을 반복하는 열거자를 반환하는 메서드를 정의하도록 하는 인터페이스다.<br>
즉 컬렉션 내부를 반복하는데 사용할 수 있는 **열거자 IEnumerator 개체를 반환하는 메서드를 구현해야 한다.**<br>
-> `foreach를 사용할 수 있게됨.`<br>
<br>

**Interface** 👉 열거자를 리턴하는 Getter의 Getter 역할<br>
```c#
public interface IEnumerable
{
    //게터를 반환하는 게터같은 느낌의 메소드이다.
    IEnumerator GetEnumerator();
}
```
<br>
<br>

## IEnumerator
컬렉션 내부를 **반복할 수 있는 열거자의 역할**을 할 수 있도록 다음과 같은 메서드를 정의하도록 하는 인터페이스다.<br>

👉 Current<br>
읽기 전용 프로퍼티로 **현재 위치의 데이터**를 object 타입으로 리턴한다.<br>

👉 MoveNext<br>
**다음 위치로 이동**하는데 다음 위치에 데이터 있으면 true, 없으면 false.<br>
그래서 보통 컬렉션 인덱스를 1씩 증가 시켜 컬렉션의 끝에 도달 했는지 여부를 나타내는 bool을 반환하는 식으로 구현한다.<br>

👉 Reset
**인덱스를 초기 상태 위치로 초기화한다.**<br>
보통 컬렉션의 인덱스를 -1로 설정하는식으로 구현<br>
<br>

**Interface** 👉 현재 데이터를 리턴(Getter)하는 열거자<br>
```c#
public interface IEnumerator

{

    object Current { get; }

    bool MoveNext();

    void Reset();

}
```
<br>
<br>

## 예제

**예제 1**<br>
```c#
// Simple business object.
public class Person
{
    public Person(string fName, string lName)
    {
        this.firstName = fName;
        this.lastName = lName;
    }

    public string firstName;
    public string lastName;
}

// Collection of Person objects. This class
// implements IEnumerable so that it can be used
// with ForEach syntax.
public class People : IEnumerable
{
    private Person[] _people;
    public People(Person[] pArray)
    {
        _people = new Person[pArray.Length];

        for (int i = 0; i < pArray.Length; i++)
        {
            _people[i] = pArray[i];
        }
    }

// Implementation for the GetEnumerator method.
    IEnumerator IEnumerable.GetEnumerator()
    {
       return (IEnumerator) GetEnumerator();
    }

    public PeopleEnum GetEnumerator()
    {
        return new PeopleEnum(_people);
    }
}

// When you implement IEnumerable, you must also implement IEnumerator.
public class PeopleEnum : IEnumerator
{
    public Person[] _people;

    // Enumerators are positioned before the first element
    // until the first MoveNext() call.
    int position = -1; // 👉 _people 배열 인덱스로 활용할 것.

    public PeopleEnum(Person[] list)
    {
        _people = list;
    }

    public bool MoveNext()
    {
        position++;
        return (position < _people.Length);
    }

    public void Reset()
    {
        position = -1;
    }

    object IEnumerator.Current
    {
        get
        {
            return Current;
        }
    }

    public Person Current
    {
        get
        {
            try
            {
                return _people[position];
            }
            catch (IndexOutOfRangeException)
            {
                throw new InvalidOperationException();
            }
        }
    }
}

class App
{
    static void Main()
    {
        Person[] peopleArray = new Person[3]
        {
            new Person("John", "Smith"),
            new Person("Jim", "Johnson"),
            new Person("Sue", "Rabon"),
        };

        // ⭐⭐⭐⭐⭐
        People peopleList = new People(peopleArray);
        foreach (Person p in peopleList)
            Console.WriteLine(p.firstName + " " + p.lastName);
    }
}
```
<br>
<br>

**예제 2**<br>
사실 아래처럼 두 인터페이스를 한번에 다중 상속해서 해결하는 것이 훨씬 간결하다.<br>
```c#
namespace ConsoleEnum
{
    public class cars : IEnumerator,IEnumerable  // 👉다중 상속
    {
       private car[] carlist;
       int position = -1;
       //Create internal array in constructor.
       public cars()
       {
           carlist= new car[6]
           {
               new car("Ford",1992),
               new car("Fiat",1988),
               new car("Buick",1932),
               new car("Ford",1932),
               new car("Dodge",1999),
               new car("Honda",1977)
           };
       }
       //IEnumerator and IEnumerable require these methods.
       public IEnumerator GetEnumerator()
       {
           return (IEnumerator)this;  // 👉이 클래스는 IEnumerator를 상속받기도 하므로 (IEnumerator)this 형변환만 해주면 땡
       }
       //IEnumerator
       public bool MoveNext()
       {
           position++;
           return (position < carlist.Length);
       }
       //IEnumerable
       public void Reset()
       {
           position = 0;
       }
       //IEnumerable
       public object Current
       {
           get { return carlist[position];}
       }
    }
  }
```
<br>
<br>

## 결론
* IEnumerable를 구현하여 열거자를 반환 할 수 있어야하고, IEnumerator 인터페이스를 통해 열거자를 구현해야만<br>
foreach와 같은 구문을 사용할 수 있게 된다.<br>

* foreach문은 컴파일러가 아래처럼 변경해 실행하는 것이나 마찬가지다.<br>
```c#
IEnumerator enumerator = peopleList.GetEnumerator();
while(enumerator.MoveNext())
    Console.WriteLine(Current.firstName + " " + Current.lastName);
```

* 당연히 **제네릭 버전의 인터페이스를 사용하는 것이 더 좋다.**<br>
<br>
<br>

## 참조링크
https://ansohxxn.github.io/c%20sharp/enumerate/ <br>
https://ehpub.co.kr/c-8-2-1-ienumerable-ienumerator-%EC%9D%B8%ED%84%B0%ED%8E%98%EC%9D%B4%EC%8A%A4/ <br>
