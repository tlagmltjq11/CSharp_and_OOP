#include <iostream>
using namespace std;

// Section6. ��ü�� �����ϴ� ���
// Singleton Pattern

// �ٽ�
// 1. �� �̱��� �ڵ带 ����� ���ؼ� �����ϴ� ���

// CRTP : Curiously Recurring Template Pattern
// -> ��� Ŭ������ ���� ��, �Ļ� Ŭ������ �̸��� Ȱ���ϵ��� �ϴ� �ڵ�
// -> �Ʒ����� ���ø��� �̿��� �κ��̴�.
template<typename TYPE> class Singleton
{
protected: // protected
    Singleton() { }
    Singleton(const Singleton&) = delete;
    void operator=(const Singleton&) = delete;
public:
    static TYPE& getInstance()
    {
        static TYPE instance;
        return instance;
    }
};

// �ڽ��� Ÿ���� ���Ϲ޾ƾ� �ϹǷ� ���ø��� ����ؾ� �Ѵ�.
class Mouse : public Singleton< Mouse >
{

};

int main()
{
    Mouse& c1 = Mouse::getInstance();

}










//
