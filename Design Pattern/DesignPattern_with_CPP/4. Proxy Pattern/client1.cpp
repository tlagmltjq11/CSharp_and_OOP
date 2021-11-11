#include <iostream>
#include "ecourse_dp.hpp"
using namespace std;
using namespace ecourse;

// Section4. 간접층의 원리
// Proxy

// Proxy Patter : 어떤 객체에 대한 접근을 제어하기 위한 용도로
// "대리인이나 대변인에 해당하는 객체를 제공하는 패턴"

// 핵심
// 1. 이 코드를 앞으로 계속 발전하며 프록시 패턴을 알아볼 것임.

int main()
{
	int server = ec_find_server("CalcService");

	cout << "server : " << server << endl;

	int ret = ec_send_server(server, 1, 10, 20);

	cout << ret << endl; // 30
}
