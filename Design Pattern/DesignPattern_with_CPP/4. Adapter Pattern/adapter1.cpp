#include <iostream>
#include <vector>
#include "TextView.h"
using namespace std;

// Section4. 간접층의 원리
// Adapter

// 핵심
// 1. 도형 편집기 예제에서 문자기능도 사용하고 싶다고 가정
// -> 도형 편집기에서 사용되려면 Shape로 부터 파생 되어야 한다. 도형과 무관..
// -> 또한 Draw() 메소드를 통해서 글자를 출력해야 한다. 현재 Show()..

// TextView 라는 기존 라이브러리를 이용해서 문자기능을 사용하고 싶다고 가정.
// -> TextView, Shape 모두 상속받고 TextView의 Show() 메소드를
// -> ★ Draw()라는 이름으로 변경만 해주면 된다..

// ★ TextView의 모든 기능을 도형편집기 예제에서 사용할 수 있도록
// 인터페이스만 수정해 주는 것이다.

// ★ Adapter Pattern ★ : 한 클래스(또는 객체)의 인터페이스를 클라이언트가 사용하고자 하는
// 다른 인터페이스로 변환하여, 호환성 때문에 사용할 수 없었던 클래스들을 연결해
// 사용할 수 있게 하는 패턴이다.


// 클래스 어댑터 예제임.

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
};

// ★ Text의 역할은 TextView 를 도형편집기에서 사용하기 위해
// 인터페이스 변경(즉 함수 이름 변경해준 것 뿐이다.)
class Text : public TextView, public Shape
{
public:
    Text( string s) : TextView(s) {}

    virtual void Draw() { TextView::Show(); }
};


class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Draw Rect" << endl;}
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}
};

int main()
{
    vector<Shape*> v;
    v.push_back(new Rect);
    v.push_back(new Circle);
    v.push_back(new Text("hello") );

    for ( auto p : v)
        p->Draw();

}
























//
















//
