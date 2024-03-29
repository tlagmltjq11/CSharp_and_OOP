#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// visitor

// 핵심
// 1. 새로운 가상 함수를 추가하는 것은 사이드이펙트가 커서 쉽지 않은 방식이다.
// -> ★ 방문자 패턴을 사용해서 새로운 오퍼레이션을 추가하자.
// -> 단 방문자 패턴을 위한 시스템을 구현해야 한다.

class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    string getTitle() const { return title;}

    virtual void command() = 0;

    // 함수 추가 = 0
};

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};


class PopupMenu : public BaseMenu
{
    vector<BaseMenu*> v;
public:
    PopupMenu( string s) : BaseMenu(s) {}

    void addMenu(BaseMenu* p) { v.push_back(p);}

    virtual void command()
    {
        while( 1 )
        {
            system("cls");

            int sz = v.size();

            for ( int i = 0; i < sz; i++)
            {
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". << back " << endl;

            //------------------------------
            int cmd;
            cout << "choose menu >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 ) // 잘못된 입력
                continue;

            if ( cmd == sz + 1 )
                break;


            // 선택된 메뉴 실행..
            v[cmd-1]-> command(); // 핵심.. !
        }

    }
};


int main()
{
    PopupMenu* p1 = new PopupMenu("MENUBAR");

    p1->addMenu( new PopupMenu("SCREEN"));
    p1->addMenu( new PopupMenu("SOUND"));
    p1->addMenu( new MenuItem("power off", 11));

    // [ SCREEN ]
    // p1은 복합객체..

    // 방법1. 타이틀을 변경하는 멤버 함수
    // 방법2. 방문자 패턴.
    MenuTitleChangeVisitor mtcv;
    p1->accept(&mtcv);

    //MenuColorChangeVisitor mccv;
    //p1->accept(&mccv    );
    p1->command();

}























//
