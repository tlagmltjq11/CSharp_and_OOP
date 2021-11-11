#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// State Pattern

// 핵심
// 1. 변하는 부분을 가상함수로 변경하는 방식 (상속 후 재정의 방식)
// -> 아래와 같은 방식은 아이템을 먹을때마다 완전히 새로운 캐릭터로 바뀌어 버리는 것이다.
// -> 즉 기존 객체의 동작이 변경된 것이 아니라 동작이 변경된 새로운 객체가 생성된 것이다.
// -> ★ 상속은 객체에 대한 변화가 아닌 클래스에 의한 변화다 ★ !!!

class Character
{
    int gold = 0;
    int item = 0;
public:
    void run()    { runImp(); }
    void attack() { attackImp(); }

    virtual void runImp() {}
    virtual void attackImp() {}
};

class PowerItemCharacter : public Character
{
public:
    virtual void runImp() { cout << "fast run" << endl;}
    virtual void attackImp() { cout << "power attack" << endl;}
};

class NormalCharacter : public Character
{
public:
    virtual void runImp() { cout << "run" << endl;}
    virtual void attackImp() { cout << "attack" << endl;}
};


int main()
{
    Character* p = new NormalCharacter;
    p->run();
    p->attack();

    p = new PowerItemCharacter;
    p->run();
    p->attack();

}









//
