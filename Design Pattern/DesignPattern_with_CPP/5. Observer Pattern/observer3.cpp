#include <iostream>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// Observer

// 핵심
// 1. 테이블들은 옵저버패턴을 위한 코드와 데이터를 위한 코드를 갖고 있을 것이다.
// -> ★ 옵저버의 기본 기능을 제공하는 기반 클래스를 설계하자. : Subject

// 실제로 Subject와 IGraph끼리 통신하고 있으니 추상클래스 끼리 통신한다고 봐도 된다.

struct IGraph
{
    virtual void update(int) = 0;

    virtual ~IGraph() {}
};

// 관찰자의 기본 기능을 제공하는 클래스
class Subject
{
    vector<IGraph*> v;
public:
    void attach(IGraph* p) { v.push_back(p);}
    void detach(IGraph* p) { }
    void notify(int data)
    {
        for ( auto p : v)
            p->update(data);
    }
};

class Table : public Subject
{
    int data;
public:
    void SetData(int d)
    {
        data = d;
        notify(data);
    }
};

// 아직 사용하지 않을거라 주석처리
/*
class Table3D : public Subject
{
    int data[10];
public:
    void SetData(int d)
    {
        data = d;
    }
};
*/


class PieGraph : public IGraph
{
public:
    virtual void update(int n)
    {
        Draw(n);
    }
    void Draw(int n)
    {
        cout << "Pie Graph : ";

        for ( int i = 0; i < n; i++)
            cout << "*";
        cout << endl;
    }
};

class BarGraph : public IGraph
{
public:
    virtual void update(int n)
    {
        Draw(n); // 그래프를 다시 그린다.
    }
    void Draw(int n)
    {
        cout << "Bar Graph : ";

        for ( int i = 0; i < n; i++)
            cout << "+";
        cout << endl;
    }
};

int main()
{
    BarGraph bg;
    PieGraph pg;

    Table t;
    t.attach( &bg);
    t.attach( &pg);

    while( 1 )
    {
        int n;
        cin >> n;
        t.SetData(n);
    }
}




















//
