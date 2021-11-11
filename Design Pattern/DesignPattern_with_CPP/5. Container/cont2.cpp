#include <iostream>
using namespace std;

// Section5. 통보, 열거, 방문
// Container

// 핵심
// 어떻게 다른 타입을 저장할까?
// 1. 기반 클래스의 포인터를 저장하는 컨테이너 방식!! (예전에 널리 사용)

// 장점
// 코드 메모리가 증가하지 않는다.

// ★ 단점
// 타입 안정성이 떨어진다. -> 잘못된 타입의 데이터를 넣을 수도 있다.
// 요소를 컨테이너에서 꺼낼 때, 반드시 캐스팅이 필요하다.
// primitive type은 저장할 수 없다. (c#은 모든 타입이 object라서 가능함.)
// -> Integer(객체) 클래스 같은 것들을 만들어야 한다.

struct Object
{
    virtual ~Object() {}
};
// 모든 클래스는 object 로 부터 파생되어야 한다. C#

class Dialog : public Object{};
class Point : public Object{};
class Rect : public Object{};
class Integer : public Object
{
    int value;
public:
    Integer(int n) : value(n) {}
}


struct Node
{
    Object*   data;
    Node* next;
    Node( Object* d, Node* n) : data(d), next(n) {}
};

class slist
{
    Node* head = 0;
public:
    void push_front(Object* n) { head = new Node(n, head);}
    Object*  front()           { return head->data;}
};

int main()
{
    slist s;

    s.push_front(new Point);
    s.push_front(new Point);

    s.push_front ( 10 ); // error : primitive type 이라서 object형에 넣을 수 없다.
    s.push_front ( new Integer(10) ); // ok.

//    Point* p = s.front();
    Point* p = static_cast<Point*>(s.front());

//    s.push_front( new Dialog );


//    int n = s.front();
}









//
