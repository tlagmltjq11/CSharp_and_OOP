// Factory3.cpp => Factory5.cpp 로 복사
#include <iostream>
#include <vector>
#include <map>
#include "Singleton.hpp"
using namespace std;

// Section6. 객체를 생성하는 방법
// Prototype Pattern

// 핵심
// 1. ★ 팩토리에 클래스(사각형)을 등록하지않고, 객체(빨간사각형, 파란사각형)을 등록하는 방식
// -> 특정 객체를 리턴해야하므로 모든 도형은 Clone★을 갖고 있어야 한다.

// -> 이 패턴은 견본을 복사해주는 것이므로 ★ Prototype Pattern 이다.

// 사실 Factory는 패턴이 아니라 자주 사용되는 관용구? 정도로 생각해야 하고
// 실제 패턴은 추상팩토리, 팩토리메소드 패턴 등이 존재한다.

class Shape
{
public:
    virtual void Draw() { cout << "Draw Shape" << endl;}

    virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
    virtual void Draw() { cout << "Draw Rect" << endl;}

    static Shape* Create() { return new Rect;}

    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle : public Shape
{
public:
    virtual void Draw() { cout << "Circle Rect" << endl;}

    static Shape* Create() { return new Circle;}

    virtual Shape* Clone() { return new Circle(*this);}
};



class ShapeFactory
{
    MAKE_SINGLETON(ShapeFactory)


    map<int, Shape*> protype_map;

public:
    void Register( int type, Shape* sample )
    {
        protype_map[type] = sample;
    }

    Shape* CreateShape(int type )
    {
        Shape* p = 0;
        auto ret = protype_map.find( type );
        if ( ret == protype_map.end() )
            return 0;

		// 견본 복사
        p = protype_map[type]->Clone();

        return p;
    }
};



int main()
{
    ShapeFactory& factory = ShapeFactory::getInstance();

    // 공장에 제품을 등록한다.
    //        클래스 등록
    //factory.Register( 1, &Rect::Create);
    //factory.Register( 2, &Circle::Create);

    Rect* r1 = new Rect;// 빨간색 크기 5
    Rect* r2 = new Rect;// 파란색 크기 10

    // 공장에 객체 등록
    factory.Register( 1, r1);
    factory.Register( 2, r2);

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
