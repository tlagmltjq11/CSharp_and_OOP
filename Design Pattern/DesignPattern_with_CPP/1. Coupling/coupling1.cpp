#include <iostream>
using namespace std;

// �ٽ�
// 1. ���߿� HDCamera�� ���Ե����ν� �����ϴ� People Ŭ������ �޼ҵ带 �߰����־�� �ߴ�.
// -> �� ���� �ڵ��� ������ �߱�����.
// SOLID�� OCP ��Ģ�� ��Ű�� ���� �ڵ尡 �ȴ�.

// 2. ���Ѱ���
// ��ü�� ���� ��ȣ�ۿ� �� ��, ���ο� ���ؼ� �� �˰� �ִ� �� (Ŭ���� �̸� ��)
// -> ��ü/Ȯ���� �Ұ����� ������ �������̴�.
// �Ʒ� ���������� useCamera(Camera* p)�� �׷��� ���� ���̴�.
// ī�޶�� ����� ���谡 ���� Ŀ�ø��� �����ϱ� ����.

class Camera
{
public:
    void take() { cout << "take picture" << endl;}
};

class HDCamera
{
public:
    void take() { cout << "take HD picture" << endl;}
};

class People
{
public:
    void useCamera(Camera* p) { p->take(); }
    void useCamera(HDCamera* p) { p->take(); }
};

int main()
{
    People p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);
}




















//
