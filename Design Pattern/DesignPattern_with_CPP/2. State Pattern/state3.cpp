#include <iostream>
using namespace std;

// Section2. ���뼺�� �������� �и�
// State Pattern

// �ٽ�
// 1. ���ϴ� �κ��� �����Լ��� �����ϴ� ��� (��� �� ������ ���)
// -> �Ʒ��� ���� ����� �������� ���������� ������ ���ο� ĳ���ͷ� �ٲ�� ������ ���̴�.
// -> �� ���� ��ü�� ������ ����� ���� �ƴ϶� ������ ����� ���ο� ��ü�� ������ ���̴�.
// -> �� ����� ��ü�� ���� ��ȭ�� �ƴ� Ŭ������ ���� ��ȭ�� �� !!!

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
