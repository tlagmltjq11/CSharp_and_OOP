#include <iostream>
#include <mutex>
#include <atomic>
using namespace std;

// Section6. 객체를 생성하는 방법
// Singleton Pattern

// 핵심
// 1. C++ 11의 atomic 라이브러리를 사용하면 안전한 DLCP를 사용할 수 있다.

class Cursor
{
private:
    Cursor() { }
    Cursor(const Cursor&) = delete;
    void operator=(const Cursor&) = delete;

    static atomic<Cursor*> m_instance;
    static mutex m_mutex;
public:
    static Cursor& getInstance()
    {
        Cursor* tmp = m_instance.load();
        if (tmp == nullptr) {
            lock_guard<mutex> lock(m_mutex);
            tmp = m_instance.load();
            if (tmp == nullptr) {
                tmp = new Cursor;
                m_instance.store(tmp);
            }
        }
        return *tmp;

    }
};
atomic<Cursor*> Cursor::m_instance;
mutex Cursor::m_mutex;

int main()
{
    Cursor& c1 = Cursor::getInstance();
}










//
