#include <iostream>
using namespace std;

// Section2. 공통성과 가변성의 분리
// Policy Base Design

// 핵심
// 1. 멀티스레드에 안전하게 하기위해 동기화 코드를 넣었는데
// 동기화가 필요하지 않은 사용자는 성능만 저하된다.
// -> 동기화 정책은 교체 가능해야한다. 즉 분리해야한다 !!

// 변하는 것을 분리하는 방법
// 1) 변하는 것을 가상 함수로
// 2) 변하는 것을 다른 클래스로

// 어떤 방식을 선택할까?
// -> ★ 동기화 정책은 List뿐만 아니라 다른 클래스에서도 필요하다.
// -> 2번 즉 전략패턴을 사용하는게 좋다는 결론 !!!

template<typename T> class List
{
public:
    void push_front(const T& a)
    {
    //    Lock();
        //...
    //    Unlock();
    }
};

List<int> s; // 전역변수로 멀티 스레드에 안전하지 않다.

int main()
{

    s.push_front(10);

}
