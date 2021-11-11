#include <iostream>
#include <vector>
using namespace std;

// 핵심
// 1. 다형성 : 동일한 함수 호출이 상황에 따라 다르게 동작하는 것
// 2. 다형성은 OCP 원칙을 만족하는 좋은 코딩 스타일이다.

// Copy & Paste 기능 추가하기
// int type을 이용한 방식은 OCP를 만족하지 못한다.
// 고로 가상함수를 이용한 다형성을 사용하자 !!!

// ★ 자신의 복사본을 제공하는 가상함수를 만드는 패턴을 "Prototype" 패턴이라 한다.

class Shape
{
public:
    int type;
    virtual void Draw() { cout << "Draw Shape" << endl;}

    // 자신의 복사본을 만드는 가상함수.
    virtual Shape* Clone() { return new Shape(*this);}
};


class Rect : public Shape
{
public:
    Rect() { type = 1;}
    virtual void Draw() { cout << "Draw Rect" << endl;}

    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle: public Shape
{
public:
    Circle() { type = 2;}
    virtual void Draw() { cout << "Draw Circle" << endl;}

    virtual Shape* Clone() { return new Circle(*this);}
};

class Triangle : public Shape
{
public:
    virtual void Draw() { cout << "Draw Triangle" << endl;}
};

int main()
{
    vector<Shape*> v;

    while(1)
    {
        int cmd;
        cin >> cmd;

        if      ( cmd == 1 ) v.push_back(new Rect);
        else if ( cmd == 2 ) v.push_back(new Circle);



        else if ( cmd == 8 )
        {
            cout << "index >> ";
            int k;
            cin >> k;

            // k 번째 도형의 복사본을 v에 추가한다.

            v.push_back( v[k]->Clone() ); // 다형성.
			`	
/*
            // k 번째 도형의 복사본을 v에 추가한다.
			// 도형이 추가 될 때 마다 수정되어야 하는 좋지 못한 코드다!
            switch( v[k]->type )
            {
            case 1:  break;
            case 2:  break;
            }
            */

        }


        else if ( cmd == 9 )
        {
            for ( auto p : v)
                p->Draw();  // 다형성
        }
    }

}
































//
