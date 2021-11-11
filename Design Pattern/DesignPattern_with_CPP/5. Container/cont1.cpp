#include <iostream>
using namespace std;

// Section5. 통보, 열거, 방문
// Container

// 핵심
// 1. 현재 링크드리스트는 int 밖에 저장할 수 없다.
// -> 어떻게 다른 타입을 저장할까?

struct Node
{
    int   data;
    Node* next;
    Node( int d, Node* n) : data(d), next(n) {}
};

class slist
{
    Node* head = 0;
public:
    void push_front(int n) { head = new Node(n, head);}
    int  front()           { return head->data;}
};

int main()
{
    slist s;

    s.push_front(10);
    s.push_front(20);
    s.push_front(30);
    s.push_front(40);
    s.push_front(50);

    int n = s.front();
}









//
