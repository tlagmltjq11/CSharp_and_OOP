#include <iostream>
using namespace std;

// Section2. ���뼺�� �������� �и�
// State Pattern

// �ٽ�
// 1. Item�� ���� ���� �б� ���
// -> ��� ���� �Լ��� ���� �б⹮�� �ʿ��ϰ� �ȴ�.
// -> ���ο� ������ �߰� �� ��� ���� �Լ��� �б⹮�� �߰��Ǿ�� �Ѵ�.

// ��ü���⿡�� ������ ����� �ƴϴ�!!

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
