#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Factory Method Pattern

// 핵심
// 1. WinDialog, GTKDialog의 공통되는 부분인 Init()을 위해서 공통 기반클래스를 만들었다.
// -> BaseDialog
// -> ★ 그러나 BaseDialog의 Init() 내부에서 Btn, Edit을 생성하는 부분은 동일할 수 없다.
// -> ★ 변하지않는 코드에서 변해야하는 부분은 가상함수로 뽑아내고 파생클래스가 결정하게하자.
// -> ★ 이는 Template Method Pattern과 정확하게 일치한다.
// -> ★ 하지만 파생클래스에서 결정하는것이 알고리즘이 아닌, 어떤 객체를 생성할지만 결정하기 때문에
// -> ★ 이를 Factory Method Pattern 이라고 부른다.

// 고로 가상함수로 만들 부분은 CreateButton()과 CreateEdit()이다.
// 또한 Button과 Edit의 타입은 IButton, IEdit을 사용해서 모두 참조할 수 있다.
// 팩토리 메소드 패턴은 서브 클래스에 팩토리 메소드를 두기 때문에 강력한 유연성을 지닌다.
// 생성하는 제품을 언제든 서브 클래스로 확장하여 제공하고 마음대로 변경할 수 있기 때문이다.

// 단점
// 다만, 팩토리 메서드는 계속해서 새로운 하위클래스를 정의한다는 점이 있다.
// 이는 불필요하게 많은 클래스를 정의하게 될 수 있고
// 이로 인해 복잡해 질 수 있다는 단점이 있다.

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

class BaseDialog
{
public:
    void Init()
    {
        IButton* pBtn = CreateButton();
        IEdit*   pEdit = CreateEdit();

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
    virtual IButton* CreateButton() = 0;
    virtual IEdit*   CreateEdit() = 0;
};


class WinDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new WinButton;}
    virtual IEdit* CreateEdit()    { return new WinEdit;}
};

class GTKDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new GTKButton;}
    virtual IEdit* CreateEdit()   { return new GTKEdit;}
};

int main()
{
    WinDialog dlg;
    dlg.Init();
}




















//
