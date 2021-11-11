#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// State Pattern

// 핵심
// 1. 변하는 부분을 다른 클래스로 분리하는 방식. (인터페이스로 분리)
// -> 동작의 인터페이스를 정의 한 후 Item에 따른 함수의 동작을 재정의한 클래스를 만든다.
// -> 아이템 획득 시 해당 state로 교체해준다.

// 2. ★ 객체의 속성은 유지하지만 동작을 변경할 수 있게 되었다.
// -> 클래스가 아닌 객체에 대한 변화가 이루어지고 있다.

// 3. ★ 살펴보면 Strategy 패턴과 완벽히 동일하게 보인다 !!
// -> 실제 다이어그램도 정확히 일치한다.
// ★ 하지만 전략패턴은 동작의 "알고리즘"을 바꾸는 것이고
// ★ 상태패턴은 "동작" 전체를 바꾸는 것이라서 "의도/의미"가 다르다고 보면 된다.

struct IState
{
    virtual void run() = 0;
    virtual void attack() = 0;
    virtual ~IState() {}
};

class Character
{
    int gold = 0;
    int item = 0;
    IState* state;
public:
    void changeState(IState* p) { state = p;}
    void run()    { state->run(); }
    void attack() { state->attack(); }
};

class NormalState : public IState
{
    virtual void run()   { cout << "run" << endl;}
    virtual void attack(){ cout << "attack" << endl;}
};

class PowerItemState : public IState
{
    virtual void run()   { cout << "fast run" << endl;}
    virtual void attack(){ cout << "power attack" << endl;}
};

int main()
{
    NormalState ns;
    PowerItemState ps;

    Character* p = new Character;
    p->changeState(&ns);
    p->run();
    p->attack();
    
    p->changeState(&ps); // 아이템 획득.
    p->run();
    p->attack();
}