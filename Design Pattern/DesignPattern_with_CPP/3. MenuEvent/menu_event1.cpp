#include "menu.hpp" // MenuItem을 제외한 코드를 이 헤더파일에 포함시켜 둠.

// Section3. 재귀적 포함
// Menu Event

// 핵심
// 1. MenuItem은 각자 저마다 하는 일이 달라야 한다.
// -> 가상함수인 command() 내에서 변해야하는 부분을 또 다시 분리해야 한다.

// 방법 1. 템플릿 메소드 패턴을 사용하자.
// -> 상속 기반이기 때문에 파생클래스를 만들라는 의미.
// -> 메뉴가 50개면 파생 클래스가 50개여야 한다.
// -> ★ 단점 : 파생 클래스의 개수가 너무 많아지는 문제가 있다.

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        // 변해야 하는 것을 가상함수로.
        doCommand();
    }
    virtual void doCommand() {}
};

class AddStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem; // 생성자 상속..
    virtual void doCommand() { cout << "Add Student" << endl; }
};

class RemoveStudentMenu : public MenuItem
{
public:
    using MenuItem::MenuItem;
    virtual void doCommand() { cout << "Remove Student" << endl; }
};

int main()
{
    AddStudentMenu    m1( "Add Student " , 11);
    RemoveStudentMenu m2( "Remove Student " , 12);

    m1.command();
    m2.command();
}














//
