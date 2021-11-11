#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section3. 재귀적 포함
// Composite 패턴을 사용한 Menu 만들기

// 하위 메뉴를 얻는 getSubMenu()를 추가한다.

// 핵심
// 1. getSubMenu()는 BaseMenu를 반환한다.
// -> BaseMenu에는 AddMenu, getSubMenu, RemoveMenu 등이 없다.
// -> error : 해당 기능들은 PopupMenu에만 정의되어 있기 때문이다.

// 그렇다면 getSubMenu와 같이 MenuItem에게는 전혀 해당사항이 없는 기능을
// BaseMenu에 넣을 것인가?
// YES : 개별/복합 객체에 구별을 두지 않고 사용하기 위해서 넣는다.
// -> ★ 유연성

// ★ 나의 의문
// 우선 팝업메뉴에게만 필요한 기능들을 인터페이스와 같은 것으로 따로 빼내지 않는 이유가
// 개별/복합 객체에 구별을 두지 않고 사용해 유연성을 늘리기 위함이라는 것은 이해했다.
// 하지만 과연 유연성을 위해서 쓸모없는 기능을 몽땅 물려받는게 이점이 있는가?

// ★ 강사님 답변
// 구별을 두지않고 편리하게 사용하려고 기반 클래스에 두는데, ,
// 이 디자인이 싫은 경우가 있습니다.
// 그런경우는 어쩔수 없이 캐스팅이 필요 합니다.
// 그런데, 캐스팅 없이 할수 없을까 ? ? 라는 고민이 들수 있는데..이것을 가능하게 해주는 것이 "동적 언어(dynamic language)" 입니다.
// 파이썬이 동적언어이고, C#은 동적언어는 아니지만 dynamic 키워드로 동적 언어 기능을 제공합니다
// Menu 예제를 파이썬으로 만들어 보거나, C# 의 dynamic 키워드를 사용해서 구현해 보세요..
// 그럼..깔끔하게 디자인이 가능해 진다는 것을 알수 있습니다.  (동적언어의 장점, 하지만 성능의 손해가 있습니다.)

class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}
    string getTitle() const { return title;}

    virtual BaseMenu* getSubMenu(int idx)
    {
        //throw "unsupported function.."
        return 0;
    }

    void addMenu(BaseMenu* p)
    {
         throw "unsupported function..";
     }

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

    BaseMenu* getSubMenu(int idx)
    {
        return v[idx];
    }
};

int main()
{
    PopupMenu* menubar = new PopupMenu("mebuBar");
    PopupMenu* pm1 = new PopupMenu("화면설정");
    PopupMenu* pm2 = new PopupMenu("소리설정");
    MenuItem*  m1  = new MenuItem("정보 확인", 11);
    menubar->addMenu( pm1 );
    menubar->addMenu( pm2 );
    menubar->addMenu( m1 );
    pm1->addMenu( new MenuItem("해상도변경", 21));
    pm1->addMenu( new MenuItem("명암 변경", 22));
    pm2->addMenu( new MenuItem("음량 조절", 31));

    BaseMenu* p = menubar->getSubMenu(1)->getSubMenu(0);

    menubar->getSubMenu(1)->addMenu( new MenuItem("AA", 100));


    // 시작하려면
    menubar->command();

}














//
