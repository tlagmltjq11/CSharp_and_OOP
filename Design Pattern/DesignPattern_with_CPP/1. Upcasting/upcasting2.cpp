#include <iostream>
using namespace std;

// 핵심
// 1. 파생 클래스가 재정의 한 함수가 호출되게 하려면 "가상 함수"로 만들어라.

class Animal
{
    int age;
public:
    virtual void Cry() { cout << "Animal Cry" << endl;}
};

class Dog : public Animal
{
    int color;
public:
    // override
    virtual void Cry()  { cout << "Dog Cry" << endl;}
};

int main()
{
    Dog d;
    Animal* p = &d; 

    p->Cry(); //오버라이드 했으므로 Dog의 Cry가 호출된다.
}







































//
