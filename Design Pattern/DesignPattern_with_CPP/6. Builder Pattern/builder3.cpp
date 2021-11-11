#include <iostream>
#include <string>
using namespace std;

// Section6. 객체를 생성하는 방법
// Builder Pattern
// 복잡한 객체를 생성하는 방법과 표현하는 방법을 정의하는 클래스를 별도로 분리하여
// 서로 다른 표현이라도 이를 생성할 수 있는 동일한 구축 공정을 제공할 수 있도록 한다.
// -> 생성하는 방법은 makeName, makePhone, makeAddress로 동일하기에 변하지 않는다.
// -> 하지만 표현하는 방법 RawText, XML은 변해야하기 때문에 별로도 분리한다.

// ★ 결국 Strategy Pattern과 동일하다.
// 차이는? : 전략패턴은 알고리즘을 변경할 때 사용하는 것이고
// 빌더 패턴은 객체를 생성할 때 사용하는 것이다.

// Strategy(알고리즘 변경) == Builder(객체 생성법 변경) == State(동작 변경) 이 셋은 결국 똑같다.
// ★★★ 단 의도를 파악하면 구분이 가능하다.


// 입학 지원서
using Application = string; // class Application {}


// 지원서의 각 단계의 표현을 만드는 빌더 인터페이스
struct IBuilder
{
    virtual ~IBuilder() {}
    virtual void makeName(string name) =  0;
    virtual void makePhone(string phone) =  0;
    virtual void makeAddress(string addr) =  0;

    virtual Application getResult() = 0;
};

// 지원서 만드는 클래스
class Director
{
    string name = "HONG";
    string phone = "010-111-1111";
    string address = "SEOUL KANGNAMGU";
    IBuilder* pBuilder;
public:
    void setBuilder( IBuilder* p ) { pBuilder = p;}

    Application construct()
    {
        pBuilder->makeName(name);
        pBuilder->makePhone(phone);
		//pBuilder->makeAddress(address);

        return pBuilder->getResult();
    }
};

class XMLBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(string name)
    {
        app += "<NAME>" + name + "</NAME>\n";
    }
    virtual void makePhone(string phone)
    {
        app += "<PHONE>" + phone + "</PHONE>\n";
    }
    virtual void makeAddress(string addr)
    {
        app += "<ADDRESS>" + addr + "</ADDRESS>\n";
    }

    virtual Application getResult() { return app;}
};

class TextBuilder : public IBuilder
{
    Application app;
public:
    virtual void makeName(string name)
    {
        app += name + "\n";
    }
    virtual void makePhone(string phone)
    {
        app += phone + "\n";
    }
    virtual void makeAddress(string addr)
    {
        app +=  addr + "\n";
    }

    virtual Application getResult() { return app;}
};

int main()
{
    Director d;
    XMLBuilder xb;
    d.setBuilder(&xb);

    Application app = d.construct();
    cout << app << endl;

    TextBuilder tb;
    d.setBuilder(&tb);
    app = d.construct();
    cout << app << endl;
}






//
