#include <iostream>
using namespace std;

// Section6. ��ü�� �����ϴ� ���
// Factory Method Pattern

// �ٽ�
// 1. WinDialog, GTKDialog�� ����Ǵ� �κ��� Init()�� ���ؼ� ���� ���Ŭ������ �������.
// -> BaseDialog
// -> �� �׷��� BaseDialog�� Init() ���ο��� Btn, Edit�� �����ϴ� �κ��� ������ �� ����.
// -> �� �������ʴ� �ڵ忡�� ���ؾ��ϴ� �κ��� �����Լ��� �̾Ƴ��� �Ļ�Ŭ������ �����ϰ�����.
// -> �� �̴� Template Method Pattern�� ��Ȯ�ϰ� ��ġ�Ѵ�.
// -> �� ������ �Ļ�Ŭ�������� �����ϴ°��� �˰����� �ƴ�, � ��ü�� ���������� �����ϱ� ������
// -> �� �̸� Factory Method Pattern �̶�� �θ���.

// ��� �����Լ��� ���� �κ��� CreateButton()�� CreateEdit()�̴�.
// ���� Button�� Edit�� Ÿ���� IButton, IEdit�� ����ؼ� ��� ������ �� �ִ�.
// ���丮 �޼ҵ� ������ ���� Ŭ������ ���丮 �޼ҵ带 �α� ������ ������ �������� ���Ѵ�.
// �����ϴ� ��ǰ�� ������ ���� Ŭ������ Ȯ���Ͽ� �����ϰ� ������� ������ �� �ֱ� �����̴�.

// ����
// �ٸ�, ���丮 �޼���� ����ؼ� ���ο� ����Ŭ������ �����Ѵٴ� ���� �ִ�.
// �̴� ���ʿ��ϰ� ���� Ŭ������ �����ϰ� �� �� �ְ�
// �̷� ���� ������ �� �� �ִٴ� ������ �ִ�.

struct IEdit
{
    virtual void Draw() = 0;
    virtual ~IEdit() {}
};
struct IButton
{
    virtual void Draw() = 0;
    virtual ~IButton() {}
};

struct WinButton : public IButton { void Draw() { cout << "Draw WinButton" << endl;}};
struct GTKButton : public IButton { void Draw() { cout << "Draw GTKButton" << endl;}};

struct WinEdit : public IEdit { void Draw() { cout << "Draw WinEdit" << endl;}};
struct GTKEdit : public IEdit { void Draw() { cout << "Draw GTKEdit" << endl;}};

//---------------------------------------------------

class BaseDialog
{
public:
    void Init()
    {
        IButton* pBtn = CreateButton();
        IEdit*   pEdit = CreateEdit();

        //pBtn->Move();
        //pEdit->Move();

        pBtn->Draw();
        pEdit->Draw();
    }
    virtual IButton* CreateButton() = 0;
    virtual IEdit*   CreateEdit() = 0;
};


class WinDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new WinButton;}
    virtual IEdit* CreateEdit()    { return new WinEdit;}
};

class GTKDialog : public BaseDialog
{
public:
    virtual IButton* CreateButton() { return new GTKButton;}
    virtual IEdit* CreateEdit()   { return new GTKEdit;}
};

int main()
{
    WinDialog dlg;
    dlg.Init();
}




















//
