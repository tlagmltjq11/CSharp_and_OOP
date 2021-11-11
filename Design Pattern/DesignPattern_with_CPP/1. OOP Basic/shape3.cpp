#include <iostream>
#include <vector>
using namespace std;

// 핵심
// 1. ★★ 변한지 않는 코드에서 변해야하는 부분은 분리 되어야 한다.
// -> 변하는 부분을 가상함수로 뽑아내자!

// 2. ★ Template Method Pattern 
// 모든 도형에 공통적인 변하지않는 흐름을 기반 클래스에서 제공하고
// 각 도형 별로 변해야 하는 부분을 가상함수로 제공해서 재정의하게 하는 패턴.

class Shape
{
protected:
    // 변하는 것을 가상함수로 뽑아낸다.
    virtual void DrawImp()
    {
        cout << "Draw Shape" << endl;
    }

public:
    // final : 파생 클래스가 재정의 할수 없게 한다. c# : sealed
    virtual void Draw() final
    {
        cout << "mutex lock" << endl;
        DrawImp();
        cout << "mutex unlock" << endl;
    }

    virtual Shape* Clone() { return new Shape(*this);}
};

class Rect : public Shape
{
public:
    virtual void DrawImp() { cout << "Draw Rect" << endl;}
    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle: public Shape
{
public:
    virtual void DrawImp() { cout << "Draw Circle" << endl;}
    virtual Shape* Clone() { return new Circle(*this);}
};


int main()
{
    vector<Shape*> v;

    while(1)
    {
        int cmd;
        cin >> cmd;

		// 도전 과제 
		// 1. 아래 분기문 객체 생성과정을 OCP 를 만족하게 할 수 없을까?
		// => Factory 패턴
		// 2. Undo/Redo 기능을 넣으려면 어떻게 코딩해야 할까 ?
		// => Command 패턴

        if      ( cmd == 1 ) v.push_back(new Rect);
        else if ( cmd == 2 ) v.push_back(new Circle);
        else if ( cmd == 8 )
        {
            cout << "index >> ";
            int k;
            cin >> k;
            v.push_back( v[k]->Clone() );
        }
        else if ( cmd == 9 )
        {
            for ( auto p : v)
                p->Draw();
        }
    }

}
































//
