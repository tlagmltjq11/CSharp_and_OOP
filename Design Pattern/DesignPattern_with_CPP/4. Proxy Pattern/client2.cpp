#include <iostream>
#include "ecourse_dp.hpp"
using namespace std;
using namespace ecourse;

// Section4. �������� ����
// Proxy

// �ٽ�
// 1. �޼ҵ带 1, 2 ó�� ���ڰ��ƴ϶� �޼ҵ������ �����ֱ� ���� Calc Ŭ������ ����
// -> �� ���� Calc�� �������� ���� ������ ����ϰ� �ִ�.

// �� Proxy�� ���� ��
// ��� �ڵ� ��� �Լ������� ȣ���� �� �ִ�. Add, Sub
// �߸��� ��� �ڵ带 ������� �ʰ� �ȴ�.
// Client�� IPC�� ���ؼ� �� �ʿ䰡 ����. 
// ���� ����� �߰��ϰų�, ���� ���Ǵ� ��û�� ���� ĳ���� �߰��� �� �ִ�.


// Proxy.. 
class Calc
{
    int server;
public:
    Calc() { server = ec_find_server("CalcService");    }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

int main()
{
    Calc* pCalc = new Calc;

	cout << pCalc->Add(1, 2) << endl;
    cout << pCalc->Sub(10, 8) << endl;
}









//
