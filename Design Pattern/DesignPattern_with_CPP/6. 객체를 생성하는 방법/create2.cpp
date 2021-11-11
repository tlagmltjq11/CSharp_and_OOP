// Section6. 객체를 생성하는 방법
// 객체를 생성하는 방법

// 핵심
// 1. 생성자를 private으로 막고 객체를 반환하는 static 메소드를 구현한다.
// -> ★ static 메소드 내에서만 객체를 생성할 수 있기 때문에
// -> ★ 제약 조건을 추가할 수 있다.
// 객체 생성 함수를 함수의 인자로 전달 할 수 있다.

class Shape
{
public:
	virtual ~Shape() {}
};

class Rect : public Shape
{
    Rect() {}  // private 생성자. ★
public:
    static Shape* Create() { return new Rect;} // static 함수
};

class Circle : public Shape
{
    Circle() {}
public:
    static Shape* Create() { return new Circle;}
};

// 도형을 만들어서 그림을 그리는 함수
//void CreateAndDraw(string s)
//void CreateAndDraw(int type) // OCP 위반
void CreateAndDraw(Shape* (*f)() ) // 함수포인터를 매개변수로 사용
{
    // ..
//    new s;
//    if ( type == 1 ) new Rect;

    Shape* p = f(); // 사용자가 준 함수를 통해서 도형을 생성해준다. ★
    p->Draw();
}


int main()
{
    CreateAndDraw(&Rect::Create ); // 객체 생성 함수를 인자로 전달한 경우 ★
    //CreateAndDraw("Rect");

	//Shape* p = Rect::Create();

}









//
