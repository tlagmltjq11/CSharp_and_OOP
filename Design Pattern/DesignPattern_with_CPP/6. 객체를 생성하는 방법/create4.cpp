// Section6. ��ü�� �����ϴ� ���
// ��ü�� �����ϴ� ���

// �ٽ�
// 1. ������ �����ϴ� ��ü�� �����ؼ� ���ο� ��ü�� �����ϴ� ���
// -> Prototype Pattern : �ǿܷ� ���� ����ϰ� Ȱ�뵵�� ���� ����

// 1,2,3 �� ������ ���� �������ְ�
// 4�� �����ϴ� ���� �������ִ� ���� ������.

class Shape
{
public:
	virtual ~Shape() {}

    virtual Shape* Clone() = 0;
};

class Rect : public Shape
{
public:
    virtual Shape* Clone() { return new Rect(*this);}
};

class Circle : public Shape
{
public:
    virtual Shape* Clone() { return new Circle(*this);}
};

int main()
{
	Shape* p = new Rect;

	Shape* p2 = p->Clone();
}









//
