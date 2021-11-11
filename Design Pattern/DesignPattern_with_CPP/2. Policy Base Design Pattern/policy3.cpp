#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// Policy Base Design

// 핵심
// 1. policy2.cpp 에서 언급했던 가상함수의 오버헤드 문제
// -> ★ 가상함수는 inline 치환이 되지 않기 때문에 오버헤드가 존재한다고 한다.

// 2. ★ Policy Base Design 이라는 패턴을 사용해서 위 문제를 해결 할 수 있다.
// -> Generic을 이용해서 정책 클래스를 교체 할 수 있는 기술로 가상함수를 사용하지
// -> 않아도 되기 때문에 inline 치환이 가능해 오버헤드를 줄일 수 있다.
// -> c++ 기반 라이브러리에서 많이 볼 수 있는 디자인 패턴임.

// ★ 장/단점
// Policy Base Design이 그렇다고 만능은 아니다. Generic은 컴파일 타임에 fix되기 때문에
// 전략패턴처럼 런타임 중에 정책을 교체할 수 없게 된다.
// 또한, 인터페이스처럼 구현해야하는 메소드를 명확히 코드상에서 보여주는 것이 없기 때문에
// Documentation을 참조해가면서 정책 클래스를 구현해야한다는 단점이 있다.

// ★ 결론
// 멀티쓰레드와 같이 런타임중에 정책을 바꿀 일이 없다면 Policy Base Design을 고려하자.

template<typename T, typename ThreadModel = NoLock> class List
{
    ThreadModel tm; // 동기화 정책을 담은 클래스
public:
    void push_front(const T& a)
    {
        tm.Lock();
        //...
        tm.Unlock();
    }
};

class MutexLock
{
    // mutex m;
public:
    inline void Lock()   { cout << "mutex lock" << endl;}
    inline void Unlock() { cout << "mutex Unlock" << endl;}
};

class NoLock
{
public:
    inline void Lock()   {}
    inline void Unlock() {}
};

//List<int, NoLock> s; //동기화가 필요 없다면 이처럼 사용
List<int, MutexLock> s;

int main()
{

    s.push_front(10);

}
