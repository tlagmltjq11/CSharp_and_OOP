#include "menu.hpp"

// Section3. 재귀적 포함
// Menu Event

// 핵심
// 1. MenuItem은 각자 저마다 하는 일이 달라야 한다.
// -> 가상함수인 command() 내에서 변해야하는 부분을 또 다시 분리해야 한다.

// 방법 3. 전략 패턴처럼 인터페이스를 구현한 객체를 전달하지 말고, ★ 함수를 연결하자
// -> 함수포인터로 함수를 받아서 호출하자는 것.

// c#(Delegate)과 다르게 c++의 함수 포인터는 멤버함수/일반함수 모두를 담을 수 없다.
// 고로 다음 소스에서 객체지향 편법을 이용해서 해결 한다.

// ★ C#이었다면 Delegate로 모든 리스너 역할의 메소드를 받아와 호출해주면 될 것 같다.
// -> 분기문이 없어질 것 같다.

// ★ 여기서 Menu Event section 마무리 지어도 된다. 뒤는 굳이 안봐도 된다. (뒤 코드들 지웠음)

class MenuItem : public BaseMenu
{
    int id;

    void (Dialog::*handler)();
    Dialog* target;

public:
    void setHandler( void(*f)() ) { handler = f;}

    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        handler();
    }
};


class Dialog : public IMenuListener
{
public:
    virtual void doCommand(int id)
    {
        //cout << "Dialog doCommand" << endl;
        switch( id )
        {
        case 11: cout << "11" << endl; break;
        case 12: cout << "12" << endl; break;
        }
    }
};

int main()
{
    Dialog dlg;
    MenuItem m1( "Add Student " , 11);
    MenuItem m2( "Remove Student " , 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);


    m1.command();
    m2.command();
}














//
