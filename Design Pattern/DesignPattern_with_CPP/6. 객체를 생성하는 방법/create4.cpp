// Section6. 객체를 생성하는 방법
// 객체를 생성하는 방법

// 핵심
// 1. 기존에 존재하던 객체를 복사해서 새로운 객체를 생성하는 방식
// -> Prototype Pattern : 의외로 많이 사용하고 활용도도 높은 패턴

// 1,2,3 은 무에서 유를 생성해주고
// 4는 기존하던 것을 복사해주는 것이 차이점.

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
