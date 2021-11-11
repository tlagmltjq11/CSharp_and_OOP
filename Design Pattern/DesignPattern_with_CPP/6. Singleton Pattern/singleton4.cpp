#include <iostream>
#include <mutex>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. DCLP 은 컴파일러 최적화(reOrdering)에 의해서 버그가 발생할 수 있다. 

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
        // 단점 : 최초 생성시 if 를 2번 실행
        // 장점 : 최초 이외에는 Lock 을 수행하지 않는다.
        if ( pInstance == 0 )
        {
            m.lock();
            if ( pInstance == 0 )
            {
                pInstance = new Cursor;

				// 위 new 구문은 다음과 같이 실행된다.
                // 1. temp = sizeof(Cursor) 메모리 할당.
                // 2. Cursor::Cursor() 생성자 호출
                // 3. pInstance = temp;

				// 만약 컴파일러가 아래와 같이 최적화하여 순서를 바꾼다면??
				// 두번째 과정에서 주소를 미리 할당하고 생성자를 호출하게 되는데
				// 주소만 할당하고 아직 생성자 호출 중인데, 만약 다른 스레드가 접근하면
				// 주소가 null이 아니기 때문에 객체를 바로 리턴받는다.
				// 하지만 아직 제대로 생성된 객체가 아니어서 잘못된 객체를 받을 수 있다.
				// 1. pInstance = sizeof(Cursor) 메모리 할당.
                // 3. pInstance = temp;
                // 2. Cursor::Cursor() 생성자 호출

            }

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
