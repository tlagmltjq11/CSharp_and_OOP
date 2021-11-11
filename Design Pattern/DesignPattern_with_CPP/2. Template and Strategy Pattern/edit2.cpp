#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Section2. 공통성과 가변성의 분리 (Template Method Pattern)
// 1. 변하는 것을 분리하는 방법 

// 핵심
// Template Method Pattern (상속기반)
// 1. 변하지않는 코드안에 변해야하는 부분은 분리하자. (2가지 방법이 존재)

// 1) isdigit을 별도의 가상함수로 뽑는 방식.
// -> validation 정책을 변경하고 싶으면 새로운 Edit의 파생 클래스를 만들어서
// -> validate() 가상함수를 재정의하면 된다.
// -> 이는 분명 기존 Edit 클래스의 코드를 수정하지않고, 새로운 파생클래스를 만드는
// -> "확장하는 코드"라고 볼 수 있다.

// 다른 1가지는 다음 코드에 있음.

class Edit
{
    string data;
public:

    virtual bool validate(char c)
    {
        return isdigit(c);
    }

    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

            if ( c == 13 ) break;

            if ( validate(c) )
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};
//--------------------
class AddressEdit : public Edit
{
public:
    virtual bool validate(char c)
    {
        return true;
    }
};

int main()
{
    AddressEdit edit;

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}








































//
