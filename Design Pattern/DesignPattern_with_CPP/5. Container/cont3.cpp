#include <iostream>
using namespace std;

// Section5. �뺸, ����, �湮
// Container

// �ٽ�
// ��� �ٸ� Ÿ���� �����ұ�?
// 1. Generic, template (���� �θ� ���Ǵ� ���)

// ����
// Ÿ�� �������� �پ��.
// ��Ҹ� ���� ��, ĳ������ �ʿ� ����.
// primitive type ���� ������ �� �ִ�.

// ����
// �ڵ� �޸𸮰� �����Ѵ�.
// -> int�� ������ int�� �����ϴ� slist�� �����, �ٸ� Ÿ���� ����������
// -> �ش� Ÿ�� ���� slist Ŭ������ ����ؼ� �����ȴ�.


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
