#include <iostream>
#include <string>
using namespace std;

// Section6. 객체를 생성하는 방법
// Builder Pattern

// 핵심
// 1. 각 지원서를 만드는 메소드를 따로 정의해주는 방식.
// -> ★ 지원서에서 주소를 빼야한다면 두 메소드에서 모두 수정해주어야 한다.
// -> 우선 각 메서드는 이름, 전화번호, 주소의 순서로 표기받아야 한다는 흐름은 동일하다.
// -> 하지만 각 메소드에서 표현법은 변해야 한다.

// 흐름은 동일한데, 변해야하는 부분이 있다? -> 분리해내면 된다는 것을 알 것이다.★
// 1) 변하는 것을 가상 함수로 (상속) -> 실행시간 교체 x, 재사용성 x, 유연성 x
// 2) 변하는 것을 다른 클래스로 (인터페이스) -> 유연성이 더 좋다. 이 방법으로 설계해보자!★



// 입학 지원서
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
        Application app;
        app += name + "\n";
        app += phone + "\n";
        //app += address + "\n";
        return app;
    }

    Application XMLconstruct()
    {
        Application app;
        app += "<NAME>" + name + "</NAME>\n";
        app += phone + "\n";
        //app += address + "\n";
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
