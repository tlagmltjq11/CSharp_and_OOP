
// �ٽ�
// 1. ��� Ŭ������ �Ļ� Ŭ������ ���� �� �� �ִ�.
// -> ������ ������ �Ļ� Ŭ�������� ��� Ŭ������ ��� ������ ���ԵǾ� �ֱ� ������
// -> ��� Ŭ���� ������ �޸𸮸� ���� ���� ��, �Ļ� Ŭ������ �޸� ���� ��� Ŭ���� ������
// -> ã�� �� �ֱ� �����̴�.

// ����� ����� �����޴� �� �Ӹ� �ƴ϶�, �پ��� ��ü�� �ϳ��� ���� ��ɵ� �߿��ϴ�.

class Animal
{
    int age;
};
class Dog : public Animal
{
    int color;
};

int main()
{
    Dog d;

    Dog*    p1 = &d;  // ok.

    double* p2 = &d;  // error.

    Animal* p3 = &d;  // ok.
}







































//