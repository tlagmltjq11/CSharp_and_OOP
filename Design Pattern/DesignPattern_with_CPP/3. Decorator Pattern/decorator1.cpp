#include <iostream>
using namespace std;

// Section3. ����� ����
// Decorator

// �ٽ�
// 1. ������ ȹ�� �� �̻����� ��Ƽ������ �����ٸ�?
// -> �� ������ ������ ������ �ٲ�� State ���ϰ� �ٸ���
// -> ������ ���� + ���ο� ������ ���൵��� �Ѵ�.

// �ڡ� �� Decorator Pattern�� ����ð��� ��ü�� ����� �߰� �� �� ����ϴ� �����̴�.

class SpaceCraft // ���ּ�
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
