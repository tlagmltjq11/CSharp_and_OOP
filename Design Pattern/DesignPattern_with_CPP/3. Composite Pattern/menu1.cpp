#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Section3. ����� ����
// Composite ������ ����� Menu System �����


// �˾��޴� : �޴��������� ���� �˾�
// �޴������� : �� �޴�������
// �˾��޴��� �˾��޴�, �޴������� �� �ٸ� ������ �� �־�� �Ѵ�. -> ����.

// �˾��޴�, �޴��������� �����ִ� ���� Ŭ����
class BaseMenu
{
    string title;
public:
    BaseMenu( string s) : title(s) {}

    string getTitle() const { return title;}

	// �˾��޴��� ���ο� �˾��� ������ϰ�, �޴��������� ���� �ؾ��ϹǷ�
	// (�߻�)���� �����Լ��� �����.
    virtual void command() = 0;
};

class MenuItem : public BaseMenu
{
    int id;
public:
    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        cout << getTitle() << endl;
        getchar();
    }
};

int main()
{
    MenuItem m("sound", 11); // ok..

}




//









//
