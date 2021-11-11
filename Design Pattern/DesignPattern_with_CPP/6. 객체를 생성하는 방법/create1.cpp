// Section6. 객체를 생성하는 방법
// 객체를 생성하는 방법

// 핵심
// 1. 사용자가 직접 객체를 생성하는 방법
// -> stack 객체 or heap 객체
// 가장 자유로운 방법이며 객체 생성에 대한 제약이 없다. !!

// 만약 5개 이상 못만들게 하고 싶다면?
// -> 자유롭게 만들게해서는 안된다 !!
// -> 특정 위치에서만 객체를 생성할 수 있게 해야 한다.

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
