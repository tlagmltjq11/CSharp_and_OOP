#include <iostream>
using namespace std;

// Section6. ��ü�� �����ϴ� ���
// Singleton Pattern

// �ٽ�
// 1. �̱��� �ڵ� ��ü�� ��ũ�θ� ���ؼ� ���� �ϴ� ���

#define MAKE_SINGLETON(classname)                   \
private:                                            \
    classname() { }                                 \
    classname(const classname&) = delete;           \
    void operator=(const classname&) = delete;      \
public:                                             \
    static classname& getInstance()                 \
    {                                               \
        static classname instance;                  \
        return instance;                            \
    }



class Cursor
{
    int x, y;

    MAKE_SINGLETON(Cursor) // ������ �����ϰ� �̱��� ������ ����� �� �ִ�.
};

int main()
{
    Cursor& c1 = Cursor::getInstance();
}













//
