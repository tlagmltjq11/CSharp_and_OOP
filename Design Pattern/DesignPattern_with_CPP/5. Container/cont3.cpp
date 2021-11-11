#include <iostream>
using namespace std;

// Section5. 통보, 열거, 방문
// Container

// 핵심
// 어떻게 다른 타입을 저장할까?
// 1. Generic, template (가장 널리 사용되는 방식)

// 장점
// 타입 안정성이 뛰어나다.
// 요소를 꺼낼 때, 캐스팅이 필요 없다.
// primitive type 까지 저장할 수 있다.

// 단점
// 코드 메모리가 증가한다.
// -> int를 넣으면 int로 동작하는 slist가 생기고, 다른 타입을 넣을때마다
// -> 해당 타입 전용 slist 클래스가 계속해서 생성된다.


template<typename T> struct Node
{
    T   data;
    Node* next;
    Node( const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> class slist
{
    Node<T>* head = 0;
public:
    void push_front(const T& n) { head = new Node<T>(n, head);}
    T  front()                  { return head->data;}
};

int main()
{
    slist<Point> s2;

    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    //s.push_front( new Dialog); // error

    int n = s.front();
}









//
