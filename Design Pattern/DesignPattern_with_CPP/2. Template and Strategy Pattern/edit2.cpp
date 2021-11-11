#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

// Section2. ���뼺�� �������� �и� (Template Method Pattern)
// 1. ���ϴ� ���� �и��ϴ� ��� 

// �ٽ�
// Template Method Pattern (��ӱ��)
// 1. �������ʴ� �ڵ�ȿ� ���ؾ��ϴ� �κ��� �и�����. (2���� ����� ����)

// 1) isdigit�� ������ �����Լ��� �̴� ���.
// -> validation ��å�� �����ϰ� ������ ���ο� Edit�� �Ļ� Ŭ������ ����
// -> validate() �����Լ��� �������ϸ� �ȴ�.
// -> �̴� �и� ���� Edit Ŭ������ �ڵ带 ���������ʰ�, ���ο� �Ļ�Ŭ������ �����
// -> "Ȯ���ϴ� �ڵ�"��� �� �� �ִ�.

// �ٸ� 1������ ���� �ڵ忡 ����.

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
