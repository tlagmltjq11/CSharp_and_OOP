#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// Policy Base Design

// 핵심
// 1. 동기화 처리 부분을 분리해낸 후 전략패턴으로 구성함

// 2. 문제가 없어 보이는 예제이지만 만약 push_front가 수 없이 호출된다면
// -> ★ 가상함수의 오버헤드 문제가 커질 수 있다.

struct ISync
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {} // 모든 기반클래스는 가상 소멸자를 가져야 한다.
};

template<typename T> class List
{
    ISync* pSync = 0;
public:
    void setSync(ISync* p) { pSync = p;}

    void push_front(const T& a)
    {
        if ( pSync != 0 ) pSync->Lock();
        //...
        if ( pSync != 0 ) pSync->UnLock();
    }
};

// Mutex 정책
class MutexLock : public ISync
{
    // mutex m;
public:
    virtual void Lock()  {}
    virtual void UnLock() {}
};

List<int> s;

int main()
{
    MutexLock m;
    s.setSync(&m);

    s.push_front(10);


    NoLock m2; // NoLock 정책을 구현했다고 가정
    s.setSync(&m2);

}
