#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. 싱글턴 코드 자체를 매크로를 통해서 재사용 하는 방식

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

    MAKE_SINGLETON(Cursor) // 굉장히 간편하게 싱글턴 패턴을 사용할 수 있다.
};

int main()
{
    Cursor& c1 = Cursor::getInstance();
}













//
