#include <iostream>
#include <mutex>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. 멀티쓰레딩 환경에서 동기화 문제

// 2. Lock과 UnLock은 최조 객체를 만들때만 필요하다.
// -> 객체를 리턴받을때 마다 락이 걸리는 것은 비효율 적이다.
// -> ★ DCLP 방식을 사용하자.
// Double Check Locking Pattern : pInstance 를 2번 체크해주는 것을 의미한다.
// 단점 : if를 2번 호출
// ★ 장점 : 최초 이외에는 Lock을 수행하지 않는다. -> 성능향상

// ★★ 하지만 2004년 이후로 DLCP의 문제점이 발견된 방식이다.
// 문제점은 다음 코드에서 살펴본다.


class Cursor
{
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static mutex   m;
    static Cursor* pInstance;
public:


    static Cursor& getInstance()
    {
		// 여러 스레드가 동시에 해당 if문에 진입하면 문제가 생기므로 mutex 진행

        // 단점 : 최초 생성시 if 를 2번 실행
        // 장점 : 최초 이외에는 Lock 을 수행하지 않는다.
        if ( pInstance == 0 )
        {
            m.lock();
            if ( pInstance == 0 )
                pInstance = new Cursor;
            m.unlock();
        }

        return *pInstance;
    }





};
Cursor* Cursor::pInstance = 0;
mutex   Cursor::m;


int main()
{
    Cursor& c1 = Cursor::getInstance();
}










//
