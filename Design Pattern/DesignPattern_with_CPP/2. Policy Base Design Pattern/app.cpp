#include <iostream>
using namespace std;

// 핵심
// 뭔가 FSM Framework랑 비슷한 구조인 것 같다.

// 1. Application Framework의 개념

class CWinApp; // 클래스 전방 선언.

CWinApp* g_app = 0;

class CWinApp
{
public:
    CWinApp()    { g_app = this;}
    virtual bool InitInstance() { return false; }
    virtual int  ExitInstance() { return false; }
    virtual int  Run()          { return 0; }
};

// main이 위 클래스 내부에 있었다면 전형적인 템플릿 메소드 패턴의 예제였을 것이다.
// 하지만 main은 c++에서 멤버함수가 될 수 없기에 아래와 같은 프레임워크 형식을 띄는 것. 
int main()
{
    if ( g_app->InitInstance() == true)
        g_app->Run();
    g_app->ExitInstance();
}

//-----------------------
// 라이브러리 사용자
// 1. CWinApp 의 파생 클래스 만들어야 한다.
// 2. 사용자 클래스를 전역객체 생성

class MyApp : public CWinApp
{
public:
    virtual bool InitInstance()
    {
        cout << "initialization" << endl;
        return true;
    }

    virtual int  ExitInstance()
    {
        cout << "finish" << endl;
        return 0;
    }
};
MyApp theApp;

// 1. 전역변수 생성자. 기반 클래스 생성자.
// 2. main 함수 실행.
































//
