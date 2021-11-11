#include <iostream>
#include <vector>
#include <map>
#include "Singleton.hpp"
using namespace std;

// Section6. 객체를 생성하는 방법
// Factory Pattern

// 핵심
// 1. ★ 해쉬테이블을 이용해서 Factory 클래스에 도형과, 도형을 생성하는 함수를 매칭시키는 방식
// 도형을 생성하는 함수는 각 도형 클래스에 존재.
// -> ★ 유틸성이 굉장히 좋아졌으며, if~else 분기문이 사라진다.

// -> 하지만 현재는 타입이 추가되면 도형을 등록하는 Register 코드가 추가된다.
// -> 다음 코드에서 해당 코드도 자동화 시킬 수 있다.

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}
};

class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Draw Rect" << endl;}

    static Shape* Create() { return new Rect;}
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}

    static Shape* Create() { return new Circle;}
};


// new Circle;
// Circle::Create()




class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)

    typedef Shape* (*CREATOR)();

    map<int, CREATOR> create_map; // ★ 도형의 번호와, 해당 도형을 만드는 메소드를 매칭

public:
    void Register( int type, CREATOR f )
    {
        create_map[type] = f;
    }

    Shape* CreateShape(int type )
    {
        Shape* p = 0;
        auto ret = create_map.find( type );
        if ( ret == create_map.end() )
            return 0;
        p = create_map[type]();

        return p;
    }
};



int main()
{
    ShapeFactory& factory = ShapeFactory::getInstance();

    // 공장에 제품을 등록한다.
    factory.Register( 1, &Rect::Create);
    factory.Register( 2, &Circle::Create);

    //factory.ShowProduct();

    vector<Shape*> v;

    while( 1 )
    {
        int cmd;
        cin >> cmd;

        //
        if ( cmd >=1 && cmd <= 5 )
        {
            Shape* p = factory.CreateShape(cmd);

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
