#include <iostream>
using namespace std;

// Section3. 재귀적 포함
// Decorator

// 핵심
// 1. 포함을 통한 기능 추가 방식.
// 기존 객체에 기능을 추가하는 방식이됨. -> 우주선이 하나밖에 없음

// 클래스가 아닌 객체에 기능이 추가됨.
// 컴파일 시간이 아닌 실행 시간에 기능 추가!


// 기능 추가 방법	기능 추가 대상	기능 추가 시점
// 상속				클래스			컴파일타임
// 포함				객체			실행시간

// ★ 상속은 포함에 비해 유연성이 없다.

class SpaceCraft
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

// 구성(Composition) 통한 기능의 추가.
class LeftMissile
{
    SpaceCraft* craft;
public:
    LeftMissile( SpaceCraft* p) : craft(p) {}

    void Fire()
    {
        craft->Fire(); // 기존 기능 수행.
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm(&sc);
    lm.Fire();
}







//
