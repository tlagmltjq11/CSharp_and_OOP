#include <iostream>
#include <vector>
using namespace std;

// Section5. �뺸, ����, �湮
// Observer

// �� ��ü ������ 1:N�� ���踦 �����ϰ� �� ��ü�� ���°� ���ϸ�
// ���ӵ� �ٸ� ��ü�� �뺸�� ����, �ڵ����� ������ �Ͼ�� �ϴ� �����̴�.

// ������ : Observer
// ������� : Subject

// -> �׷��ٸ� ��ȭ�� ������ ���� �����ؾ� �ϳ�?
// -> No. ��ȭ�� �뺸���ָ� �ȴ�.��


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
