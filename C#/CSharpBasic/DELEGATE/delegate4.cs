using System;

// 핵심
// 1. static method 등록 법
// 클래스이름.메소드이름

// 2. 객체 메소드 등록 법
// 객체.메소드이름

// 3. ★ 확인하기

delegate void FUNC(int arg);

class Test
{
    public static void static_method(int arg) { }
    public void instance_method(int arg) { }
}

class Program
{
    public static void static_method(int arg) { }
    public void instance_method(int arg) { }

    public static void Main()
    {
        // static 메소드 등록법
        FUNC f1 = Test.static_method;
        //FUNC f2 = Program.static_method;
        FUNC f2 = static_method; // 자신의 메소드니까 Program 생략가능

        // 객체 메소드 등록법
        Test t = new Test();
        FUNC f3 = t.instance_method;

        // ★ Main 이라는 static 메소드 내부이기 때문에 this가 없는 상황이라서
        // 객체를 직접 생성해서 넣어주어야 한다.
        Program p = new Program();
        FUNC f4 = p.instance_method;

        p.foo();
    }

    public void foo()
    {
        // ★ static 메소드가 아니기 때문에 현재 객체가 이미 생성되어 있을 상황이니까
        // this 키워드만으로도 등록해줄 수 있다.
        FUNC f1 = this.instance_method;
        FUNC f2 = instance_method;
    }
}


