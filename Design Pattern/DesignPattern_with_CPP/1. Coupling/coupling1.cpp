#include <iostream>
using namespace std;

// 핵심
// 1. 나중에 HDCamera가 도입됨으로써 기존하던 People 클래스에 메소드를 추가해주어야 했다.
// -> 즉 기존 코드의 수정을 야기했음.
// SOLID의 OCP 원칙을 지키지 못한 코드가 된다.

// 2. 강한결합
// 객체가 서로 상호작용 할 때, 서로에 대해서 잘 알고 있는 것 (클래스 이름 등)
// -> 교체/확장이 불가능한 경직된 디자인이다.
// 아래 예제에서는 useCamera(Camera* p)가 그러한 예일 것이다.
// 카메라와 사람의 관계가 강한 커플링을 유지하기 때문.

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
