#include <iostream>
#include <string.h>
using namespace std;

// Section6. 객체를 생성하는 방법
// Abstract Factory Pattern
// -> ★ 여러 객체의 군을 생성하기 위한 인터페이스를 제공한다.

// 핵심
// 1. ★ 기존 코드는 매번 버튼을 만들 때 마다 조사해야 한다.
// ★★ 또한 Edit을 만들때에도, 스타일을 조사해야 한다.. 
// window라는 스타일을 한번 조사했으면 window관련★ 객체들을 지속해서★ 모두 생성 할 수 있는
// 공장을 불러오는게 편하지 않을까?? ★★
// -> 공장을 만들자.

// ★ 스타일에 따라서 버튼이 아니라 팩토리를 만든다.(관련 스타일의 객체를 지속해서 모두 만들 수 있다.)
// -> 팩토리 공통 기반의 클래스를 만들어야 한다. -> ★ 추상 팩토리의 의미


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
struct GTKButton : public IButton{ void Draw() { cout << "Draw GTKButton" << endl;}};

struct WinEdit : public IEdit { void Draw() { cout << "Draw WinEdit" << endl;}};
struct GTKEdit : public IEdit { void Draw() { cout << "Draw GTKEdit" << endl;}};

//-------------------------------------
// Factory 의 공통의 기반 클래스
struct IFactory
{
    virtual IButton* CreateButton() = 0;
    virtual IEdit*   CreateEdit() = 0;
    virtual ~IFactory() {}
};

// public 안쓰려고 구조체를 쓴 것 뿐
struct WinFactory : public IFactory
{
    IButton* CreateButton() { return new WinButton;}
    IEdit*   CreateEdit()   { return new WinEdit;}
};

struct GTKFactory : public IFactory
{
    IButton* CreateButton() { return new GTKButton;}
    IEdit*   CreateEdit()   { return new GTKEdit;}
};

int main(int argv, char** argc)
{
    IFactory* pFactory;
    if ( strcmp(argc[1], "Windows") == 0)
        pFactory = new WinFactory;
    else
        pFactory = new GTKFactory;


    IButton* pBtn = pFactory->CreateButton();
    pBtn->Draw();

}








//
