#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Section2. 공통성과 가변성의 분리 (Strategy Pattern)
// 1. 변하는 것을 분리하는 방법 

// 핵심
// Strategy Pattern (인터페이스 기반 / 포함 기반)
// 1. 변하지않는 코드안에 변해야하는 부분은 분리하자. (2가지 방법이 존재)

// 2) 변하는 부분을 다른 클래스로 뽑아내는 방식.
// -> 교체가 가능해야 한다. 즉 약한 결합 -> ★ 인터페이스 기반 통신!! 


// validation 을 위한 인터페이스
struct IValidator
{
    virtual bool validate(string s, char c) = 0;
    virtual bool iscomplete(string s)  { return true;}

    virtual ~IValidator() {} //c++에서 모든 기반 객체는 가상 소멸자를 가져야함
};

// 주민 번호 : 801    1   확인.


class Edit
{
    string data;
    //---------------------
    IValidator* pVal = 0;
public:
    void setValidator(IValidator* p ) { pVal = p;} // 정책 교체
    //---------------------------

    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

            if ( c == 13 &&
                ( pVal == 0 || pVal->iscomplete(data)  ) ) break;

            if ( pVal == 0 || pVal->validate(data, c) ) // 값의 유효성 검사를 외부 클래스에게 위임!!
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};

class LimitDigitValidator : public IValidator
{
    int value;
public:
    LimitDigitValidator(int n) : value(n) {}

    virtual bool validate( string s, char c )
    {
        return s.size() < value && isdigit(c);
    }

    virtual bool iscomplete( string s)
    {
        return s.size() == value;
    }
};


int main()
{
    Edit edit;
    LimitDigitValidator v(5);
    edit.setValidator(&v); // 정책 교체

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}
