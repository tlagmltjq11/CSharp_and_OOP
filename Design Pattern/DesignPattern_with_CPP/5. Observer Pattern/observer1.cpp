#include <iostream>
#include <vector>
using namespace std;

// Section5. 통보, 열거, 방문
// Observer

// ★ 객체 사이의 1:N의 관계를 정의하고 한 객체의 상태가 변하면
// 종속된 다른 객체에 통보가 가고, 자동으로 수정이 일어나게 하는 패턴이다.

// 관찰자 : Observer
// 관찰대상 : Subject

// -> 그렇다면 변화를 루프를 돌며 관찰해야 하나?
// -> No. 변화를 통보해주면 된다.★


class Table
{
    int data;
public:
    void SetData(int d) { data = d;  }
};

class PieGraph
{
public:
    void Draw(int n)
    {
        cout << "Pie Graph : ";

        for ( i = 0; i < n; i++)
            cout << "*";
    }
};

int main()
{
}




















//
