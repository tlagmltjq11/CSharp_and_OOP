#include <iostream>
using namespace std;

// 핵심
// 1. protected 소멸자 -> 객체를 heap에 만들게끔 하는 기법

class Car
{
public:
    Car() {}

    void Destroy() { delete this;}
protected:
    ~Car(){ cout << "~Car" << endl;}
};

int main()
{
    //Car c; // 스택에 객체를 만들수 없다. 소멸자가 불릴 수 없어서!

    Car* p = new Car;
    p->Destroy(); // 멤버함수로 직접 호출해야한다.

    //delete p;
}
