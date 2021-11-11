#include <iostream>
using namespace std;

// Section6. ��ü�� �����ϴ� ���
// Singleton Pattern

// �ٽ�
// Singleton Pattern
// Ŭ������ �ν��Ͻ��� "���� �ϳ����� �����ϸ�" �̿� ���� "������
// ��𿡼����� �����ϵ���" �����ϴ� �����̴�.

// �����ڴ� private
// static ����Լ��� �� �ϳ��� ��ü�� ������ �����Ѵ�.

// ���콺 Ŀ���� �� �Ѱ��� �����Ѵ�.
class Cursor
{
    int x, y;

private:
    Cursor() { } // �����ڸ� private�� ���´�.
    Cursor(const Cursor&) = delete; // ���� �����ڸ� ���´�.
    void operator=(const Cursor&) = delete; // ���� �����ڸ� ���´�

public:
    static Cursor& getInstance() // static ��� �Լ��� ���ؼ� ���� �ϳ��� ��ü�� ���� �� ��ȯ
    {
        static Cursor instance;
        return instance;
    }
};

int main()
{
    //Cursor c1, c2; // 2���� ���� �� ����� �Ѵ�.
    Cursor& c1 = Cursor::getInstance();
    Cursor& c2 = Cursor::getInstance();
    cout << &c1 << endl;
    cout << &c2 << endl;

	// ����� ���� �����ڸ� ���� ��ü�� �� ����� �� �� �ֱ� ������ ������� �Ѵ�.
    //Cursor c3 = c1;
}










//
