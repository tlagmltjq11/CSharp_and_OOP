
// 핵심
// 1. protected 생성자 - 파생클래스의 생성자에서 접근한다.
// -> ★ 자기자신은 객체를 만들 수 없지만 파생클래스들은 객체를 만들게 하겠다는 의미다 !!!

// 2. Dog의 생성자가 먼저 호출되고 Dog의 생성자 안에서 Animal의 생성자를 호출한다.
// -> 고로 블록자체는 Animal 생성자의 블록이 먼저 수행된다.

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
