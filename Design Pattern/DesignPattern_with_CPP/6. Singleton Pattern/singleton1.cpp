#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// Singleton Pattern
// 클래스의 인스턴스는 "오직 하나임을 보장하며" 이에 대한 "접근은
// 어디에서든지 가능하도록" 제공하는 패턴이다.

// 생성자는 private
// static 멤버함수로 단 하나의 객체를 생성해 리턴한다.

// 마우스 커서는 단 한개만 존재한다.
class Cursor
{
    int x, y;

private:
    Cursor() { } // 생성자를 private에 놓는다.
    Cursor(const Cursor&) = delete; // 복사 생성자를 막는다.
    void operator=(const Cursor&) = delete; // 대입 연산자를 막는다

public:
    static Cursor& getInstance() // static 멤버 함수를 통해서 오직 하나의 객체를 생성 후 반환
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    //Cursor c1, c2; // 2개를 만들 수 없어야 한다.
    Cursor& c1 = Cursor::getInstance();
    Cursor& c2 = Cursor::getInstance();
    cout << &c1 << endl;
    cout << &c2 << endl;

	// 복사와 대입 연산자를 통해 객체를 더 만들어 낼 수 있기 때문에 막아줘야 한다.
    //Cursor c3 = c1;
}










//
