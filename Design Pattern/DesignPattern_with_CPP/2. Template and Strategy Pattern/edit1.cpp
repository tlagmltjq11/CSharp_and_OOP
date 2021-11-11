#include <iostream>
#include <string>
#include <conio.h>  // getch()
using namespace std;

// Section2. 공통성과 가변성의 분리 (Template Method Pattern)
// 1. 변하는 것을 분리하는 방법 

// 핵심
// 1. isdigit()과 같은 Validation 정책을 교체할 수 있도록 설계해야 한다.
// -> Edit의 코드를 수정하지 말고, 정책을 변경할 수 있어야 한다.
// 현재 숫자만 입력 가능하므로 문자입력이 안됨.

class Edit
{
    string data;
public:
    string getData()
    {
        data.clear();

        while( 1 )
        {
            char c = getch();

			// 13  == Enter 키 의미
            if ( c == 13 ) break;

			// isdigit은 숫자인지 판별하는 라이브러리다.
			// 현재 숫자만 입력이 가능하다.
			// 그런데 문자를 입력받고 싶다면?
            if ( isdigit(c) )
            {
                data.push_back(c);
                cout << c;
            }
        }
        cout << endl;
        return data;
    }
};


int main()
{
    Edit edit;

    while(1)
    {
        string s = edit.getData();
        cout << s << endl;
    }
}








































//
