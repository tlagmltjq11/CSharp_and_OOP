
// �ٽ�
// 1. protected ������ - �Ļ�Ŭ������ �����ڿ��� �����Ѵ�.
// -> �� �ڱ��ڽ��� ��ü�� ���� �� ������ �Ļ�Ŭ�������� ��ü�� ����� �ϰڴٴ� �ǹ̴� !!!

// 2. Dog�� �����ڰ� ���� ȣ��ǰ� Dog�� ������ �ȿ��� Animal�� �����ڸ� ȣ���Ѵ�.
// -> ��� �����ü�� Animal �������� ����� ���� ����ȴ�.

class Animal
{
protected:
    Animal() {}
};

class Dog : public Animal
{
public:
    Dog() {} // Dog() : Animal() {}   
};

int main()
{
    Animal a;   // error
    Dog    d;   // ok.
}
