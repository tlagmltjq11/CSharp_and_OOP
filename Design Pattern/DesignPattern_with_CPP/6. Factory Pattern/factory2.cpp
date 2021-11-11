#include <iostream>
#include <vector>
#include "Singleton.hpp"
using namespace std;

// Section6. 객체를 생성하는 방법
// Factory Pattern

// 핵심
// 1. 만드는 과정을 외부가아닌 한 곳에 집중시키자.
// -> ShapeFactory 생성

// 하지만 여전히 타입이 추가되면 ShapeFactory 내부가 수정되어야 한다.
// -> 그렇다면 장점은?
// ★★★ 장점 : 객체의 생성을 공장을 통해서만 진행하기 때문에, 새로운 도형이 추가되어도
// 팩토리 한 곳만 수정하면 된다. -> 외부에서 진행했다면 곳곳을 전부 수정해야 할 것이다.

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
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

class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)
public:
    Shape* CreateShape(int type )
    {
        Shape* p = 0;
        if      ( type == 1 ) p = new Rect;
        else if ( type == 2 ) p = new Circle;

        return p;
    }
};

int main()
{
    ShapeFactory& factory = ShapeFactory::getInstance(); // 싱글턴 객체를 얻어온다.
    vector<Shape*> v;

    while( 1 )
    {
        int cmd;
        cin >> cmd;

        //
        if ( cmd >=1 && cmd <= 5 )
        {
            Shape* p = factory.CreateShape(cmd); // 공장을 통해서 도형 생성

            if ( p != 0 )
                v.push_back( p );
        }
        else if ( cmd == 9 )
        {
            for ( auto p : v )
                p->Draw(); // 다형성
        }
    }
}
































//
