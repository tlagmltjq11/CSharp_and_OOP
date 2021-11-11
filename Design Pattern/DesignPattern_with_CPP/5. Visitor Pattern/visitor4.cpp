#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// visitor

// 핵심
// 1. 메뉴 (복합객체)는 accept 가 필요..
// 2. 방문자 인터페이스 필요..

// ★ 단점 
// 1. 방문자 패턴은 캡슐화/정보 은닉을 위반하게 된다.
// -> 전혀 별개의 객체들이 내부로 들어와서 데이터를 바꿔야하기 때문.

// 2. 방문자 패턴을 도입하면 오퍼레이션을 추가하기는 쉽지만 타입을 추가하기는 어렵게 된다.
// -> 새로운 타입을 넣는순간 모든 방문자가 전부 수정된다.
// -> ★ 위 단점은 방문자 패턴을 도입한 이유인 새로운 함수를 추가하기 어렵다는 점과 정 반대의 단점이다.

// ★결론★
// 새로운 타입이 계속 추가되면 쓰면 안되고,
// 새로운 타입은 추가되지 않고 새로운 함수가 많이 추가된다면 사용하자!

//---------------------------
class BaseMenu;
class MenuItem;
class PopupMenu;

// 방문자의 인터페이스
struct IMenuVisitor
{
    virtual ~IMenuVisitor() {}

    virtual void visit(BaseMenu* p) = 0;
    virtual void visit(MenuItem* p) = 0;
    virtual void visit(PopupMenu* p) = 0;
    virtual void visit(PopupMenu* p) = 0;
};

struct IAcceptor
{
    virtual ~IAcceptor() {}
    virtual void accept(IMenuVisitor* p) = 0;
};
//-----------------------------------------------

class BaseMenu : public IAcceptor
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    void setTitle(string s) { title = s;}
    string getTitle() const { return title;}

    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;
public:
    virtual void accept(IMenuVisitor* p)
    {
        p->visit(this);
    }

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
    virtual void accept(IMenuVisitor* p)
    {
        p->visit(this);

        for ( auto m : v)
            m->accept(p);
    }
};

class MenuTitleChangeVisitor : public IMenuVisitor
{
public:
    virtual void visit(BaseMenu* p) {}
    virtual void visit(MenuItem* p) {}
    virtual void visit(PopupMenu* p)
    {
        // popupmenu 의 타이틀을 변경한다.
        string s = p->getTitle();
        s = "[ " + s + " ]";

        p->setTitle(s);
    }
};

class EraseTitleChangeVisitor : public IMenuVisitor
{
public:
    virtual void visit(BaseMenu* p) {}
    virtual void visit(MenuItem* p) {}
    virtual void visit(PopupMenu* p)
    {
        p->setTitle("...");
    }
};

int main()
{
    PopupMenu* p1 = new PopupMenu("MENUBAR");

    p1->addMenu( new PopupMenu("SCREEN"));
    p1->addMenu( new PopupMenu("SOUND"));
    p1->addMenu( new MenuItem("power off", 11));

    //---------------------
    MenuTitleChangeVisitor mtcv;
    p1->accept(&mtcv);

    EraseTitleChangeVisitor etcv;
    p1->accept(&etcv);
    // 1. 메뉴 (복합객체)는 accept 가 필요
    // 2. 방문자 인터페이스 필요..

    p1->command();
}
























//
