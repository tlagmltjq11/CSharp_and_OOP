#include <iostream>
#include <vector>
using namespace std;

// Section6. 객체를 생성하는 방법
// Factory Pattern

// 핵심
// 1. 타입이 추가될 때 마다 코드가 수정되어야 한다.
// -> 다형적으로 사용할 수 없을까?

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

int main()
{
    vector<Shape*> v;

    while( 1 )
    {
        int cmd;
        cin >> cmd;

        // 타입이 추가될 때 마다 코드가 수정되어야 한다.
		// -> 다형적으로 사용할 수 없을까?
        if      ( cmd == 1 ) v.push_back( new Rect );
        else if ( cmd == 2 ) v.push_back( new Circle );
        else if ( cmd == 9 )
        {
            for ( auto p : v )
                p->Draw(); // 다형성
        }
    }
}
































//
