#include <iostream>
using namespace std;

// Section3. 재귀적 포함
// Decorator

// 핵심
// 1. Decorator 패턴의 의도
// ★ 객체에 동적으로 새로운 서비스를 추가할 수 있게 한다.
// 기능 추가를 위해 상속을 사용하는 것 보다는 융통성있는 방법이다.

// IDecorator로 한번 더 묶어준다.

// 우주선과 기능추가객체의 공통의 기반 클래스
struct Component
{
    virtual void Fire() = 0;
    virtual ~Component() {}
};


class SpaceCraft : public Component
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

//---------------
// ★ 기능 추가 클래스의 공통의 기반 클래스
class IDecorator : public Component
{
    Component* craft;
public:
    IDecorator( Component* p) : craft(p) {}

    void Fire() { craft->Fire();}
};


class LeftMissile : public IDecorator
{
public:
    LeftMissile( Component* p) : IDecorator(p) {}

    void Fire()
    {
        IDecorator::Fire();
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

class RightMissile : public IDecorator
{
public:
    RightMissile( Component* p) : IDecorator(p) {}

    void Fire()
    {
        IDecorator::Fire();
        cout << "Right Missile : >>>>>>>>" << endl;
    }
};


int main()
{
    SpaceCraft sc;

    LeftMissile  lm(&sc);
    RightMissile rm(&lm);

    rm.Fire();
}







//
