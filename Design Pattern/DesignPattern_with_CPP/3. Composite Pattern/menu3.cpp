#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section3. 재귀적 포함
// Composite 패턴을 사용한 Menu 만들기

// 핵심
// 1. main 사용자 코드를 보면 메뉴추가 과정, 메뉴수정 과정과 사용 과정이 매우 간편함.

// PopupMenu : 복합 객체로 다른 객체를 보관할 수 있으므로 Node 혹은 Composite라고 표현
// MenuItem : 개별 객체로 Leaf이라고 표현

// ★ Composite Pattern
// ★ 객체들을 트리 구조로, 즉 계층구조로 만들어 관리하는 패턴.
// 개별 객체와 복합 객체를 구별하지 않고 동일한 방법★으로 다룰 수 있다.
// 팝업메뉴가 팝업메뉴를 보관하는 것 처럼 재귀적인 특성을 갖는다.

class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    string getTitle() const { return title;}

    virtual void command() = 0;
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

            cout << sz + 1 << ". 상위 메뉴로" << endl;

            //------------------------------
            int cmd;
            cout << "메뉴를 선택하세요 >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 )
                continue;

            if ( cmd == sz + 1 )
                break;



            v[cmd-1]-> command();
        }

    }
};

int main()
{
    PopupMenu* menubar = new PopupMenu("mebuBar");
    PopupMenu* pm1 = new PopupMenu("화면설정");
    PopupMenu* pm2 = new PopupMenu("소리설정");
    MenuItem*  m1  = new MenuItem("정보 확인", 11);

    menubar->addMenu( pm1 );
    pm1->addMenu( pm2 );
    menubar->addMenu( m1 );

    pm1->addMenu( new MenuItem("AAAA", 20));
    pm1->addMenu( new MenuItem("해상도변경", 21));
    pm1->addMenu( new MenuItem("명암 변경", 22));

    pm2->addMenu( new MenuItem("음량 조절", 31));

    // 시작하려면
    menubar->command();

}














//
