#include <iostream>
#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace std;
using namespace ecourse;

// Section4. 간접층의 원리
// Proxy

// 핵심
// 1. 자신의 Add를 호출하는 것 같지만, 서버의 Add를 호출하는 것
// -> 즉 다른 프로세스에 있는 함수를 호출하는 과정이다.
// -> RPC (remote procedure Call) 이라는 개념이다.

// 2. Client와 Server의 메소드명을 일치시키는게 좋다는 것을 알 수 있다.
// -> ★ ICal 인터페이스를 도입하자 !


class Calc : public ICalc
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

	// 자신의 Add를 호출하는 것 같지만, 서버의 Add를 호출하는 것
	// -> 즉 다른 프로세스에 있는 함수를 호출하는 과정이다.
	// -> RPC (remote procedure Call) 이라는 개념이다.

	// Client와 Server의 메소드명을 일치시키는게 좋다는 것을 알 수 있다.
	// -> ★ ICal 인터페이스를 도입하자 !

	cout << pCalc->Add(1, 2) << endl;
    cout << pCalc->Sub(10, 8) << endl;
}









//
