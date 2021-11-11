#include <iostream>
using namespace std;

// Section3. 재귀적 포함
// Decorator

// 핵심
// 1. 상속을 통한 기능 추가 방식.
// -> 아이템을 먹는 순간 완전히 새로운 우주선을 만들어버리는 것임.
// -> 즉 기존 객체에 기능을 더한 것이 아닌 기능이 부여된 새로운 객체를 만든 것이다.

// 상속을 통한 기능 추가 -> 객체가 아닌 클래스(SpaceCraft)에 기능을 추가하는 것.
// 실행시간이 아닌 코드 작성시에 기능이 추가되는 것.

class SpaceCraft
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

// 상속을 통한 기능의 추가.
class LeftMissile : public SpaceCraft
{
public:
    void Fire()
    {
        SpaceCraft::Fire(); // 기존 기능 수행.
        cout << "Left Missile : >>>>>>>>" << endl;
    }
};

int main()
{
    SpaceCraft sc;
    sc.Fire();

    LeftMissile lm;
    lm.Fire();
}







//
