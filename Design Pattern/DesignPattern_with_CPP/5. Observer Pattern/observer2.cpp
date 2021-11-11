#include <iostream>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// Observer

// 핵심
// 1. 모든 옵저버를 관리하기 위해 IGraph라는 인터페이스를 정의함.


// 모든 옵저버를 하나의 컬렉션에 저장하기 위해, 
// 통보 메소드를 만들기 위해 인터페이스로 묶는다.
struct IGraph
{
    virtual void update(int) = 0;

    virtual ~IGraph() {}
};


class Table
{
    vector<IGraph*> v; // 통보 대상인 옵저버들의 포인터를 갖고 있어야 한다. ★

    int data;
public:
    void attach(IGraph* p) { v.push_back(p);} // 옵저버 추가
    void detach(IGraph* p) { } // 옵저버 삭제


    void SetData(int d)
    {
        data = d; // 데이터 변경

        for ( auto p : v) // 데이터 변경을 통보해준다.
            p->update(data);
    }
};




class PieGraph : public IGraph
{
public:
    virtual void update(int n)
    {
        Draw(n); // 그래프를 다시 그린다.
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
