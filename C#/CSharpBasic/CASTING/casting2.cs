using System;

// 핵심
// 1. is 연산자 : 참조 변수가 가리키는 실제 타입이 무엇인지 조사하는 연산자

// 2. as 연산자 : 캐스팅 실패 시 null 반환
// -> (Dog)obj; 와 같이 캐스팅하면 실패 시 예외를 발생해 프로그램이 죽는다. 
// 혹은 try - catch 구문으로 잡아주어야 한다.

class Animal { }
class Dog : Animal
{
    public void Cry() { Console.WriteLine("Dog Cry"); }
}

class Program
{
    public static void foo(Animal a)
    {
        //a.Cry();

        // Animal 참조 타입을 Dog 참조타입으로 캐스팅 == 다운캐스팅
        //Dog d = (Dog)a; 
        //d.Cry();

        // 안전하게 다운 캐스팅하는 예제 1 : is
        /*
        if ( a is Dog ) // a가 Dog인지 Check
        {
            Console.WriteLine("Dog 맞음");
            Dog d = (Dog)a;
            d.Cry();
        }
        */

        // 안전하게 다운 캐스팅하는 예제 2 : as
        //Dog d = (Dog)a; // 실패시 예외 -> 프로그램이 죽는다.
        Dog d = a as Dog; // ★ 실패시 null 반환 -> 프로그램이 죽지 않는다.

        if ( d == null)
        {
            Console.WriteLine("null");
        }
    }

    static void Main()
    {
        //foo(new Dog());
        foo(new Animal()); // Animal로 넘겨주면 Dog로 다운캐스팅이 불가능해 에러를 뿜을 것이다.
        // 고로 형변환 이전에 변환이 가능한지 Check 해야 한다.

        int n = 3;
        object obj = n;

        //int n1 = obj as int; // error -> 실패 시 null을 반환하는데 값 타입이라서 받을 수 없다.

        int? n1 = obj as int?; // ok
        Console.WriteLine(n1);
    }
}

