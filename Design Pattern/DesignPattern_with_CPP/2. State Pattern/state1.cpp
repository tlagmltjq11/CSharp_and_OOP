#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// State Pattern

// 핵심
// 슈퍼마리오에서는 아이템을 먹으면 "달리기", "공격하기"가 아이템 특성에 따라 변화한다.
// 1. 아이템의 상태에 따라 "달리기", "공격하기" 동작을 변경해야 한다.

class Character
{
    int gold = 0;
    int item = 0;
public:
    void run()    { cout << "run"    << endl; }
    void attack() { cout << "attack" << endl; }
};

int main()
{
    Character* p = new Character;
    p->run();
    p->attack();
}
