#include <iostream>
#include <vector>
using namespace std;

// 핵심
// 1. 모든 도형을 타입으로 설계한다.
// 2. 모든 도형의 공통 기반 클래스를 설계한다. Shape
// 3. 모든 도형의 공통의 특징은 반드시 기반 클래스에도 있어야 한다. : Draw
// -> 이는 사실 공통 특징은 기반 클래스로부터 물려받아야 한다는게 맞는 소리같다.
// 4. 파생클래스에서 재정의하게 되는 함수는 반드시 가상 함수로 만들어야 한다.


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
    virtual void Draw() { cout << "Draw Circle" << endl;}
};

int main()
{
    vector<Shape*> v;

    while( 1 )
    {
        int cmd;
        cin >> cmd;

        if      ( cmd == 1 ) v.push_back( new Rect );
        else if ( cmd == 2 ) v.push_back( new Circle );
        else if ( cmd == 9 )
        {
            for ( auto p : v )
                p->Draw();
        }
    }
}
































//
