#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// State Pattern

// 핵심
// 1. Item에 따른 조건 분기 방식
// -> 모든 동작 함수에 조건 분기문이 필요하게 된다.
// -> 새로운 아이템 추가 시 모든 동작 함수에 분기문이 추가되어야 한다.

// 객체지향에서 쓸만한 방식은 아니다!!

class Character
{
    int gold = 0;
    int item = 0;
public:
    void run()
    {
        if ( item == 1)
            cout << "run"    << endl;
        else if ( item == 2 )
            cout << "fast run" << endl;
    }
    void attack()
    {
        if ( item == 1)
             cout << "attack" << endl;
        else if ( item == 2 )
             cout << "attack2" << endl;
    }
};

int main()
{
    Character* p = new Character;
    p->run();
    p->attack();
}
