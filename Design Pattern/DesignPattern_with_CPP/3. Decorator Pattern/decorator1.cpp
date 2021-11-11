#include <iostream>
using namespace std;

// Section3. 재귀적 포함
// Decorator

// 핵심
// 1. 아이템 획득 시 미사일이 멀티샷으로 나간다면?
// -> ★ 기존의 동작이 완전히 바뀌는 State 패턴과 다르게
// -> 기존의 동작 + 새로운 동작이 진행도어야 한다.

// ★★ 즉 Decorator Pattern은 실행시간에 객체에 기능을 추가 할 때 사용하는 패턴이다.

class SpaceCraft // 우주선
{
    int color;
    int speed;
public:
    void Fire() { cout << "Space Craft : ----------" << endl;}
};

int main()
{
    SpaceCraft sc;
    sc.Fire();
}
