#include <iostream>
#include <list>
using namespace std;

// Section5. 통보, 열거, 방문
// visitor

// 핵심
// ★ List s 는 TwiceVisitor, ShowVisitor 등 여러가지 타입의 방문자를 받을 수 있어야 한다.

// 1. 방문자를 위한 인터페이스가 필요하게 된다. : IVisitor ★
// 2. 모든 방문 대상 객체는 accept가 있어야 한다. : IAcceptor ★

// 방문자(visitor)의 인터페이스
template<typename T> struct IVisitor
{
    virtual void visit(T& elem) = 0; // 요소를 받는 메소드
    virtual ~IVisitor() {}
};

template<typename T> class TwiceVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { elem = elem * 2;}
};

template<typename T> class ShowVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { cout << elem << endl;}
};
//------------------------


// 방문의 대상의 인터페이스
template<typename T> struct IAcceptor
{
    virtual void accept( IVisitor<T>* p) = 0;
    virtual ~IAcceptor()  {}
};

template<typename T> class List : public list<T>, public IAcceptor<T>
{
public:
    using list<T>::list; // c++11 생성자 상속
    virtual void accept( IVisitor<T>* p)
    {
        // 모든 요소를 방문자에게 전달.
        for( auto& e : *this) // ★ 자신의 요소를 하나씩 꺼내어 방문자에게 보내는 과정이다
            p->visit(e);
    }
};

template<typename T> class TripleVisitor : public IVisitor<T>
{
public:
    virtual void visit(T& elem) { elem = elem * 3;}
};

int main()
{
    List<int> s = { 1,2,3,4,5,6,7,8,9,10};

    TwiceVisitor<int> tv;
    s.accept(&tv);

    TripleVisitor<int> trv;
    s.accept(&trv);

    ShowVisitor<int> sv;
    s.accept(&sv);


    //s.triple_all_element();
}













//
