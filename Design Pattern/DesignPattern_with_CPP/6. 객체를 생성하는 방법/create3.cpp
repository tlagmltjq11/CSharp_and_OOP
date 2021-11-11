// Section6. 객체를 생성하는 방법
// 객체를 생성하는 방법

// 핵심
// 1. 객체를 만들어주는 Factory 클래스를 사용한다.
// -> ★ 각 클래스들은 본래의 기능만 가질 수 있다.
// -> ★ 추상 팩토리 패턴

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
    Rect() {}
public:
	friend class ShapeFactory;
};

class Circle : public Shape
{
    Circle() {}
public:
	friend class ShapeFactory;
};

class ShapeFactory
{
public:
	Shape* CreateShape( int type )
	{
		Shape* p = 0;
		switch( type )
		{
		case 1: p = new Rect; break;
		case 2: p = new Circle; break;
		}
		return p;
	}
};

int main()
{
	ShapeFactory factory;
	Shape* p = factory.CreateShape(1);

}














//
