#include <iostream>
#include <vector>
#include "TextView.h"
using namespace std;

// Section4. 간접층의 원리
// Adapter

// 핵심
// 1. 어댑터는 클래스 어댑터, 객체 어댑터로 나뉜다.

// 클래스 어답터 ★
// 클래스의 인터페이스를 변경한다.
// 다중 상속 또는 값으로 포함하는 경우가 많다.
// 이미 존재하던 객체의 인터페이스는 변경할 수 없다.

// 객체 어답터 ★
// 객체의 인터페이스를 변경한다.
// 포함을 사용하는 경우가 많다.
// 기존 객체를 참조로 포함!

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
};

// TextView 클래스의 인터페이스를 도형편집기에 맞도록 수정
// 클래스 어댑터 ★ : 기존의 객체를 변경할 수는 없고 새로운 객체만 가능하다.
class Text : public TextView, public Shape
{
public:
    Text( string s) : TextView(s) {}

    virtual void Draw() { TextView::Show(); }
};

/*
class Text :  public Shape
{
    TextView tv;
public:
    Text( string s) : tv(s) {}

    virtual void Draw() { tv.Show(); }
};
*/

// 객체 어댑터 ★
class ObjectAdapter :  public Shape
{
    TextView* pView; // 포인터가 핵심
public:
    ObjectAdapter( TextView* p) : pView(p) {}

    virtual void Draw() { pView->Show(); }
};

int main()
{
    vector<Shape*> v;

    TextView tv("world"); // 이미 존재 하던 객체..
    //v.push_back(&tv); // error. Shape 의 파생클래스가 아니라 못들어간다.

    v.push_back( new ObjectAdapter(&tv)); //감싸서 넣는 것

    v.push_back( new Text("hello"));

    for ( auto p : v)
        p->Draw();
}








































//
