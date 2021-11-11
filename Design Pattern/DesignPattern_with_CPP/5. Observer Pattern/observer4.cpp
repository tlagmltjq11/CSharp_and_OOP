#include <iostream>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// Observer

// 핵심
// 1. 변경된 Data를 어떻게 전달할 것인가?
// -> 변화를 통보할 때 같이 전달 - ★ Push 방식 (observer3.cpp에서 사용중)
// -> 데이터가 복잡하면 위 방식은 한계가 있다. (함수 인자가 많아진다는 둥..)

// -> 변화 되었다는 사실만 전달하고, Graph에서 table의 멤버 함수를 통해서
// -> 직접 접근 -> ★ Pull 방식
// -> ★ 옵저버에서 변화되었다는 사실을 보내며, 자신의 참조를 전달하는 방식이다.

// -> ★ 단 옵저버가 서브젝트로 부터 받은 참조에 대해서 캐스팅을 사용해 줘야 한다.


// ★ 두 방식 모두 장/단점이 있지만 Pull 방식을 더 많이 사용하긴 한다.

class Subject;

struct IGraph
{
    virtual void update(Subject*) = 0;

    virtual ~IGraph() {}
};


class Subject
{
    vector<IGraph*> v;
public:
    void attach(IGraph* p) { v.push_back(p);}
    void detach(IGraph* p) { }

    void notify()
    {
        for ( auto p : v)
            p->update(this);
    }
};

class Table : public Subject
{
    int data;
    int color;
public:
    int GetData() { return data;}

    void SetData(int d)
    {
        data = d;
        notify();
    }
};


class PieGraph : public IGraph
{
public:
    virtual void update(Subject* p)
    {
        // table 에 접근해서 data를 꺼내 온다.
        //int n = p->GetData(); // error. 캐스팅 필요.★
        int n = static_cast<Table*>(p)->GetData();

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
    virtual void update(Subject* p)
    {
        int n = static_cast<Table*>(p)->GetData();

        Draw(n);
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
