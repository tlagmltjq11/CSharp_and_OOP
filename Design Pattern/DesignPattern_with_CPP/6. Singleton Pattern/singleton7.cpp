#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. ★ 싱글턴 코드를 상속을 통해서 재사용하는 방식

// CRTP : Curiously Recurring Template Pattern
// -> 기반 클래스를 만들 때, 파생 클래스의 이름을 활용하도록 하는 코드
// -> 아래에서 템플릿을 이용한 부분이다.
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

// 자신의 타입을 리턴받아야 하므로 템플릿을 사용해야 한다.
class Mouse : public Singleton< Mouse >
{

};

int main()
{
    Mouse& c1 = Mouse::getInstance();

}










//
