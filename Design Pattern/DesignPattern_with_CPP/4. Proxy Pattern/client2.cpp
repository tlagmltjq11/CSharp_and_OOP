#include <iostream>
#include "ecourse_dp.hpp"
using namespace std;
using namespace ecourse;

// Section4. 간접층의 원리
// Proxy

// 핵심
// 1. 메소드를 1, 2 처럼 숫자가아니라 메소드명으로 보내주기 위해 Calc 클래스를 생성
// -> ★ 현재 Calc가 원격지의 계산기 서버를 대신하고 있다.

// ★ Proxy의 장점 ★
// 명령 코드 대신 함수명으로 호출할 수 있다. Add, Sub
// 잘못된 명령 코드를 사용하지 않게 된다.
// Client는 IPC에 대해서 알 필요가 없다. 
// 보안 기능을 추가하거나, 자주 사용되는 요청에 대한 캐쉬를 추가할 수 있다.


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
