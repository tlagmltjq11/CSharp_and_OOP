#include <iostream>
#include <list>
#include <vector>
#include <deque>
using namespace std;

// Section4. 간접층의 원리
// Adapter

// 핵심
// 1. 실제 STL의 Stack이 List등의 클래스의 인터페이스를 변경해서
// 즉 어댑터 패턴을 이용해서 만들어졌음을 보여준다.
// -> Sequence Container의 인터페이스를 수정해서 stack, queue 등을 제공한다.

// ★ 클래스 어답터이다.


// stack 을 만들어 봅시다.
// list의 함수이름을 stack 처럼 보이도록 변경
/*
template<typename T> class Stack : private list<T>
{
public:
    void push(const T& a) { list<T>::push_back(a);}
    void pop()            { list<T>::pop_back();}
    T&   top()            { return list<T>::back();}
};
*/
/*
template<typename T, typename C = deque<T> > class Stack
{
    C st;
public:
    inline void push(const T& a) { st.push_back(a);}
    void pop()            { st.pop_back();}
    T&   top()            { return st.back();}
};
*/
#include <stack>

int main()
{
    //Stack<int, list<int> > s;
    //Stack<int, vector<int> > s;
    stack<int> s;
    s.push(10);
    s.push(20);

//    s.push_front(20);

    cout << s.top() << endl; // 20
}









//
