#include <iostream>
#include "ecourse_dp.hpp" // IPC 관련 코드
#include "ICalc.h"
using namespace std;
using namespace ecourse;

// Section4. 간접층의 원리
// Proxy

// Proxy Pattern : 어떤 객체에 대한 접근을 제어하기 위한 용도로
// "대리인이나 대변인에 해당하는 객체를 제공하는 패턴"

// 핵심
// 1. 

class Calc : public ICalc
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Calc calc;


int dispatch( int code, int x, int y )
{
	printf("[DEBUG] %d, %d, %d\n", code, x, y );

	switch( code )
	{
	case 1: return calc.Add( x, y);
	case 2: return calc.Sub( x, y);
	}
	return -1;
}

int main()
{
	ec_start_server("CalcService", dispatch);
}












//
