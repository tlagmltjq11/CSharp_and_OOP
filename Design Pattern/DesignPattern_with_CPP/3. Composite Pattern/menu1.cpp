#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section3. 재귀적 포함
// Composite 패턴을 사용한 Menu System 만들기


// 팝업메뉴 : 메뉴아이템을 갖는 팝업
// 메뉴아이템 : 각 메뉴아이템
// 팝업메뉴는 팝업메뉴, 메뉴아이템 둘 다를 저장할 수 있어야 한다. -> 묶자.

// 팝업메뉴, 메뉴아이템을 묶어주는 상위 클래스
class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}

    string getTitle() const { return title;}

	// 팝업메뉴는 새로운 팝업을 띄워야하고, 메뉴아이템은 일을 해야하므로
	// (추상)순수 가상함수로 만든다.
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

int main()
{
    MenuItem m("sound", 11); // ok..

}




//









//
