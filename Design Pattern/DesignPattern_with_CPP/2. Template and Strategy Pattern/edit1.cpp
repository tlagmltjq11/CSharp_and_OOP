#include <iostream>
#include <string>
#include <conio.h>  // getch()
using namespace std;

// Section2. ���뼺�� �������� �и� (Template Method Pattern)
// 1. ���ϴ� ���� �и��ϴ� ��� 

// �ٽ�
// 1. isdigit()�� ���� Validation ��å�� ��ü�� �� �ֵ��� �����ؾ� �Ѵ�.
// -> Edit�� �ڵ带 �������� ����, ��å�� ������ �� �־�� �Ѵ�.
// ���� ���ڸ� �Է� �����ϹǷ� �����Է��� �ȵ�.

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

			// 13  == Enter Ű �ǹ�
            if ( c == 13 ) break;

			// isdigit�� �������� �Ǻ��ϴ� ���̺귯����.
			// ���� ���ڸ� �Է��� �����ϴ�.
			// �׷��� ���ڸ� �Է¹ް� �ʹٸ�?
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
