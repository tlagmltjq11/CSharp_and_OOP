#include <iostream>
using namespace std;

// Section3. 재귀적 포함
// Decorator

// 핵심
// 1. RightMissile을 먹는 순간 Left 미사일의 아이템 효과가 사라진다.
// -> 고로 RightMissile에게 lm을 넘겨주어야 하는데 error가 난다.
// -> SpaceCraft *  형식만을 받을 수 있기 때문이다.
// -> ★ 결국 공통의 기반 클래스가 있어야 한다는 것.

// 다음 코드에서 계속..

// ★ 우주선과 기능추가객체의 공통의 기반 클래스
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

class LeftMissile : public Component
{
    Component* craft;
public:
    LeftMissile( Component* p) : craft(p) {}

    void Fire()
    {
        craft->Fire();
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

class RightMissile : public Component
{
    Component* craft;
public:
    RightMissile( Component* p) : craft(p) {}

    void Fire()
    {
        craft->Fire();
        cout << "Right Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
//    sc.Fire();

    LeftMissile lm(&sc);
//    lm.Fire();

    //RightMissile rm(&sc);
    RightMissile rm(&lm); // 기능추가된 객체에 다시 기능 추가
    rm.Fire();

}







//
