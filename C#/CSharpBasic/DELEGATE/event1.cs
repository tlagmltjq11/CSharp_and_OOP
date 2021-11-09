using System;

// 핵심
// 1. Delegate Nullable 연산자로 체크하는 법 handler?.Invoke();

// 2. delegate에 event 키워드를 함께 사용하게 되면 이벤트 처리 전용 델리게이트가 되어
// = 과 같이 모든 메소드를 덮어씌우는 경우의 수를 차단해줄 수 있다.
// 즉 구독자의 독립성을 제공하기 위한 도구다.

// 3. event 키워드를 사용하면 private으로 접근 지정자를 설정하며 프로퍼티와 같이
// add/remove 메소드를 생성해준다.
// += -> add_handler()
// -= -> remove_handler()

// 즉 event는 Delegate를 외부에서 접근할 때 안전하게 접근하게 하기 위해서 사용하는 것이다.


delegate void HANDLER();

class Button
{
    public event HANDLER handler = null;

    public void press()
    {
        // ?.   ?[
        //handler?();
        handler?.Invoke();
    }
}

// 위 코드를 컴파일러가 아래와 같이 바꿔주는 것이다 !!!
/*
class Button
{
    private HANDLER handler = null;

    public void add_handler(HANDLER f) { handler += f; }
    public void remove_handler(HANDLER f) { handler -= f; }
    public void press()
    {
        // ?.   ?[
        //handler?();
        handler?.Invoke(); // 해당 방식이 널러블 연산자를 통해 널체크하는 방법!
    }
}
*/

class Program
{
    static void Main()
    {
        Button btn = new Button();

        //btn.handler = F1;  // A라는 사람이 등록
        //btn.handler += F2; // B라는 사람이 등록
        //btn.handler = F2; // B라는 사람이 등록 -> 앞에 등록했던 모든 메소드가 덮어 씌워진다.

        btn.handler += F1; // btn.add_handler(F1)
        btn.handler += F2; // btn.add_handler(F2)
        //btn.handler = F1;

        btn.press();
    }
    public static void F1() { Console.WriteLine("F1"); }
    public static void F2() { Console.WriteLine("F2"); }
}

