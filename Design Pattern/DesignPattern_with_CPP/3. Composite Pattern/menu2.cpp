#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section3. 재귀적 포함
// Composite 패턴을 사용한 Menu 만들기

// 핵심
// 1. 모든 메뉴의 공통적인 특징이라면 구현부가 없더라도 순수 가상함수를 만들어 주어야 한다.
// -> 그래야 base 클래스 포인터로 다형성을 통해 호출 할 수 있다. (없다면 컴파일타임 에러)
// -> Command() 를 얘기하는 것임.

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
    vector<BaseMenu*> v; //팝업메뉴, 메뉴아이템 모두 담을 수 있다.
public:
    PopupMenu( string s) : BaseMenu(s) {}

    void addMenu(BaseMenu* p) { v.push_back(p);}

    virtual void command() //팝업메뉴는 선택 시, 다시 새로운 팝업을 열어주어야 한다.
    {
        while( 1 ) // 계속 출력해주어야 함
        {
            system("cls");

            int sz = v.size();

            for ( int i = 0; i < sz; i++)
            {
				// 하위 메뉴 출력
                cout << i + 1 << ". " << v[i]->getTitle() << endl;
            }

            cout << sz + 1 << ". 상위 메뉴로 " << endl;

            //------------------------------
            int cmd;
            cout << "메뉴를 선택하세요 >> ";
            cin >> cmd;

            if ( cmd < 1 || cmd > sz + 1 ) // 잘못된 입력
                continue;

            if ( cmd == sz + 1 )
                break;


            // 선택된 메뉴 실행..
            v[cmd-1]-> command(); // 핵심.. ! ★
			// 해당 아이템이 팝업메뉴인지 메뉴아이템인지 확인할 필요가 없다.
			// 가상함수 재정의로 인한 다형성★을 구현한 것이다.
        }

    }
};




int main()
{
    PopupMenu pm("화면설정");
}














//
