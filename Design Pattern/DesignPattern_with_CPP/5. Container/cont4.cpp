#include <iostream>
using namespace std;

// Section5. 통보, 열거, 방문
// Container

// 핵심
// 1. 템플릿의 단점은 코드메모리가 커진다는 것이었다.
// -> 사용자 입장에서는 그냥 템플릿같지만, 내부적으로는 void * 를 이용하며
// -> 캐스팅을 해주는 템플릿을 한번 거친다.

// -> thin template 방식이라고 한다.

struct Node
{
    void* data;
    Node* next;
    Node( void* d, Node* n) : data(d), next(n) {}
};

class slistImp
{
    Node* head = 0;
public:
    void push_front(void* n) { head = new Node(n, head);}
    void* front()           { return head->data;}
};

// 대신 캐스팅을 해주는 클래스를 만든다.
template<typename T> class slist : public slistImp
{
public:
    inline void push_front(T n) { slistImp::push_front( (void*)n);}
    inline T front()           { return (T)(slistImp::front());}
};


int main()
{
    slist<int> s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    int n = s.front();
}









//
