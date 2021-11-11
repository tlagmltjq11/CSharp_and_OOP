#include <iostream>
#include <string>
using namespace std;

// Section6. 객체를 생성하는 방법
// Builder Pattern

// 핵심
// 1. 지원서 객체는 다양한 형태로 생성될 수 있어야 한다.
// -> 지원서에는 이름, 전화번호, 주소의 순서로 표기되어야 한다.
// -> ★ 지원서는 상황에 따라 Raw Text 방식, XML 방식으로 만들 수 있어야 한다고 가정.

// 입학 지원서 (Application을 지원서라는 클래스라고 가정)
using Application = string; // class Application {}


// 지원서 만드는 클래스
class Director
{
    string name = "HONG";
    string phone = "010-111-1111";
    string address = "SEOUL KANGNAMGU";
public:
    Application construct()
    {
        Application app; // 지원서 생성
        app += name + "\n";
        app += phone + "\n";
        app += address + "\n";
        return app;
    }
};

int main()
{
    Director d;
    // 전화, 이름 입력...
    Application app = d.construct();
    cout << app << endl;
}






//
