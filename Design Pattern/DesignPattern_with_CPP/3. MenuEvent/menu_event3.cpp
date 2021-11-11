#include "menu.hpp"

// Section3. ����� ����
// Menu Event

// �ٽ�
// 1. MenuItem�� ���� ������ �ϴ� ���� �޶�� �Ѵ�.
// -> �����Լ��� command() ������ ���ؾ��ϴ� �κ��� �� �ٽ� �и��ؾ� �Ѵ�.

// ��� 3. ���� ����ó�� �������̽��� ������ ��ü�� �������� ����, �� �Լ��� ��������
// -> �Լ������ͷ� �Լ��� �޾Ƽ� ȣ�����ڴ� ��.

// c#(Delegate)�� �ٸ��� c++�� �Լ� �����ʹ� ����Լ�/�Ϲ��Լ� ��θ� ���� �� ����.
// ��� ���� �ҽ����� ��ü���� ����� �̿��ؼ� �ذ� �Ѵ�.

// �� C#�̾��ٸ� Delegate�� ��� ������ ������ �޼ҵ带 �޾ƿ� ȣ�����ָ� �� �� ����.
// -> �б⹮�� ������ �� ����.

// �� ���⼭ Menu Event section ������ ��� �ȴ�. �ڴ� ���� �Ⱥ��� �ȴ�. (�� �ڵ�� ������)

class MenuItem : public BaseMenu
{
    int id;

    void (Dialog::*handler)();
    Dialog* target;

public:
    void setHandler( void(*f)() ) { handler = f;}

    MenuItem(string s, int n) : BaseMenu(s),  id(n) {}

    virtual void command()
    {
        handler();
    }
};


class Dialog : public IMenuListener
{
public:
    virtual void doCommand(int id)
    {
        //cout << "Dialog doCommand" << endl;
        switch( id )
        {
        case 11: cout << "11" << endl; break;
        case 12: cout << "12" << endl; break;
        }
    }
};

int main()
{
    Dialog dlg;
    MenuItem m1( "Add Student " , 11);
    MenuItem m2( "Remove Student " , 12);

    m1.setListener(&dlg);
    m2.setListener(&dlg);


    m1.command();
    m2.command();
}














//
