#include <iostream>
using namespace std;

// 핵심
// 1. 제품(카메라)을 먼저 만들지 말고, 제품의 인터페이스(규칙)를 먼저 설계하라.

// 2. 이제 새로운 카메라가 등장해도 People의 코드가 수정되지 않는다 !!!
// -> 약한 커플링 : 교체/확장 가능한 유연한 디자인이다.
// -> 객체 상호간에 인터페이스를 통신하는 기법이다.
// 즉 구현에 의존하지 않고 인터페이스에 의존하는 기법임.



// 규칙 : 모든 카메라는 아래 클래스로부터 파생되어야 한다.
//
//  정확히는 모든 카메라는 아래 인터페이스를 구현해야 한다.

//#define interface struct

//c++에는 인터페이스 키워드가 없어서 구조체로 사용한다.
struct ICamera
{
    virtual void take() = 0;
    virtual ~ICamera() {} // 누군가의 부모기 때문에 가상소멸자.
};



// 카메라가 없어도 카메라를 사용하는 코드를 만들수 있다.
class People
{
public:
    void useCamera( ICamera* p ) { p->take(); }
};


class Camera : public ICamera
{
public:
    void take() { cout << "take picture" << endl;}
};

class HDCamera  : public ICamera
{
public:
    void take() { cout << "take HD picture" << endl;}
};

class UHDCamera  : public ICamera
{
public:
    void take() { cout << "take UHD picture" << endl;}
};


int main()
{
    People p;
    Camera c;
    p.useCamera(&c);

    HDCamera hc;
    p.useCamera(&hc);

    UHDCamera uhc;
    p.useCamera(&uhc);
}




















//
