#include <iostream>
#include <vector>
using namespace std;

// �ٽ�
// 1. ��� ������ Ÿ������ �����Ѵ�.
// 2. ��� ������ ���� ��� Ŭ������ �����Ѵ�. Shape
// 3. ��� ������ ������ Ư¡�� �ݵ�� ��� Ŭ�������� �־�� �Ѵ�. : Draw
// -> �̴� ��� ���� Ư¡�� ��� Ŭ�����κ��� �����޾ƾ� �Ѵٴ°� �´� �Ҹ�����.
// 4. �Ļ�Ŭ�������� �������ϰ� �Ǵ� �Լ��� �ݵ�� ���� �Լ��� ������ �Ѵ�.


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
