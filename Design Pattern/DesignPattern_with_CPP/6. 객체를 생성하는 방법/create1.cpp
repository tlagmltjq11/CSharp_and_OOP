// Section6. ��ü�� �����ϴ� ���
// ��ü�� �����ϴ� ���

// �ٽ�
// 1. ����ڰ� ���� ��ü�� �����ϴ� ���
// -> stack ��ü or heap ��ü
// ���� �����ο� ����̸� ��ü ������ ���� ������ ����. !!

// ���� 5�� �̻� ������� �ϰ� �ʹٸ�?
// -> �����Ӱ� ������ؼ��� �ȵȴ� !!
// -> Ư�� ��ġ������ ��ü�� ������ �� �ְ� �ؾ� �Ѵ�.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
};

class Circle : public Shape
{
public:
};

int main()
{
	Rect r; // stack

	Shape* p = new Rect; // heap

}
