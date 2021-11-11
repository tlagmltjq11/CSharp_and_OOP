// cont3.cpp => iterator1.cpp
#include <iostream>
using namespace std;

// Section5. 통보, 열거, 방문
// Iterator

// C#에서 배운 열거자와 동일한 내용이다.
// 모든 컨테이너가 내부 구조와 상관없이 동일한 방법으로 요소에 접근 할 수 있도록 하는 패턴이다.
// -> IEnumerable, IEnumerator 이용

// 핵심
// 1. 각 컨테이너 마다 요소를 열거하는 방식이 다르다.
// -> 동일한 방법으로 각 요소에 접근할 수 없을까?
// -> 모든 컨테이너의 요소를 열거하는 방식이 동일하다면
// -> ★ 메소드를 여러 버전으로 만들지 않아도 될 것이다. (간편하다.)

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
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);

    SlisEnumerator<int>* p = s.GetEnumerator();

    int n = p->GetObject(); // 40
    p->MoveNext(); //

    int n2 = p->GetObject(); // 50



}









//
