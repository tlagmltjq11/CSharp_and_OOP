
// 핵심
// 1. 기반 클래스로 파생 클래스를 참조 할 수 있다.
// -> 가능한 이유는 파생 클래스에는 기반 클래스의 모든 내용이 포함되어 있기 때문에
// -> 기반 클래스 참조로 메모리를 따라 갔을 때, 파생 클래스의 메모리 내에 기반 클래스 형식을
// -> 찾을 수 있기 때문이다.

// 상속은 기능을 물려받는 것 뿐만 아니라, 다양한 객체를 하나로 묶는 기능도 중요하다.

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
