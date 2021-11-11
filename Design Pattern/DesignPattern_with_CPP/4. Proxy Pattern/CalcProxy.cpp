#include "ecourse_dp.hpp"
#include "ICalc.h"
using namespace ecourse;

// Section4. 간접층의 원리
// Proxy

// 핵심
// 1. 프록시를 동적 모듈로 제공하기

class Calc : public ICalc
{
    int server;
    int count = 0;
public:
    Calc()  { server = ec_find_server("CalcService");    }
    ~Calc()  { cout << "~Calc" << endl; }

    void AddRef()  { ++count;}
    void Release() { if ( --count == 0 ) delete this; }

    int Add(int a, int b) { return ec_send_server(server, 1, a, b);}
    int Sub(int a, int b) { return ec_send_server(server, 2, a, b);}
};

extern "C" __declspec(dllexport)
// 클라이언트는 동적 모듈에 있는 클래스(프록시)의 이름을 알 수 없다.
// 고로 프록시의 객체를 생성하고 리턴하기 위해 약속된 함수가 필요하다.
ICalc* CreateCalc()
{
    return new Calc;
}






//
