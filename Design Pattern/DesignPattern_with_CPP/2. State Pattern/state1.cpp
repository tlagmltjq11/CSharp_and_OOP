#include <iostream>
using namespace std;

// Section2. ���뼺�� �������� �и�
// State Pattern

// �ٽ�
// ���۸����������� �������� ������ "�޸���", "�����ϱ�"�� ������ Ư���� ���� ��ȭ�Ѵ�.
// 1. �������� ���¿� ���� "�޸���", "�����ϱ�" ������ �����ؾ� �Ѵ�.

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
