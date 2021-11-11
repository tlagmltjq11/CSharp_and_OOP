#include "menu.hpp"

// Section3. 재귀적 포함
// Menu Event

// 핵심
// 1. MenuItem은 각자 저마다 하는 일이 달라야 한다.
// -> 가상함수인 command() 내에서 변해야하는 부분을 또 다시 분리해야 한다.

// 방법 2. 전략 패턴을 사용하자.
// -> 인터페이스 선언 후 구현 -> ★ java/c# 에서 사용하는 Listener 개념 ★
// ★ 정책을 갖고있는 객체를 연결해주는 형식
// m1, m2 모두 동일한 doCommand를 부르고 있으니 id값을 받아서
// 분기문을 통한 일처리를 진행해 주어야 한다.
// 고로 리스너는 꼭 매개변수를(ID값 등) 받아야 한다.
// -> ★ 단점 : Dialog안에 버튼이 30개있다면 분기문이 30개 만들어 질 것임.


// 메뉴 메세지를 처리하려면 아래 인터페이스를 정의 해야 한다.
struct IMenuListener
{
    virtual void doCommand( int id) = 0;
    virtual ~IMenuListener() {}
};

class MenuItem : public BaseMenu
{
    int id;
    IMenuListener* pListener = 0;

public:
    void setListener(IMenuListener* p) { pListener = p;}
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        // 변하는 것을 다른 클래스로..!
        if ( pListener != 0 )
            pListener->doCommand( id );
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
