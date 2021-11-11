#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Factory Method Pattern

// 핵심
// 1. 현재 WinDialog와 GTKDialog의 Init은 타입만 다를 뿐 정확히 같은 코드다.
// -> 중복되는 코드를 공통의 기반 클래스로 뽑아야 하지 않을까?
// 다음 코드에서 계속..

struct IEdit
{
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};

struct IButton
{
    virtual void Draw() = 0;
    virtual ~IButton() {}
};

struct WinButton : public IButton { void Draw() { cout << "Draw WinButton" << endl;}};
struct GTKButton : public IButton { void Draw() { cout << "Draw GTKButton" << endl;}};

struct WinEdit : public IEdit { void Draw() { cout << "Draw WinEdit" << endl;}};
struct GTKEdit : public IEdit { void Draw() { cout << "Draw GTKEdit" << endl;}};

//---------------------------------------------------
// -style 옵션에 상관없이 무조건 windows 스타일 사용한다고 가정.
class WinDialog
{
public:
    void Init()
    {
        WinButton* pBtn = new WinButton;
        WinEdit*   pEdit = new WinEdit;

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
};

class GTKDialog
{
public:
    void Init()
    {
        GTKButton* pBtn = new GTKButton;
        GTKEdit*   pEdit = new GTKEdit;

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
};

int main()
{
    WinDialog dlg;
    dlg.Init();
}




















//
