#include <iostream>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. static 멤버 데이터로 갖고있는 방법
// -> 전역변수로 선언해뒀기 때문에 사용하지 않더라도 객체는 생성되는 단점이 있다.

// 2. static 지역 변수로 갖는 방법
// -> 한번이라도 사용해야 객체가 생성된다.

// 3. new를 통해서 생성하는 방법 (동기화 문제가 존재한다.)



// 1번 방식
/*
class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static Cursor instance;
public:
    static Cursor& getInstance()
    {
        return instance;
    }
};
Cursor Cursor::instance;
*/


// 2번 방식
/*
class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

public:
    // lazy intialization
    static Cursor& getInstance()
    {
        static Cursor instance;
        return instance;
    }
};
*/


// 3번 방식
class Cursor
{
    int x, y;

private:
    Cursor() { cout << "Cursor()" << endl; }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static Cursor* pInstance;
public:
    static Cursor& getInstance()
    {
        if ( pInstance == 0 )
            pInstance = new Cursor;
        return *pInstance;
    }
};
Cursor* Cursor::pInstance = 0;

int main()
{
    Cursor& c1 = Cursor::getInstance();

}










//
