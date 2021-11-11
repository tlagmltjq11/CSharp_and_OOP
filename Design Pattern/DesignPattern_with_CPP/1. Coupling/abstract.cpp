
// 핵심
// 1. 즉 순수 가상함수는  c#에서의 추상함수라고 생각하면 된다.
// -> 파생 클래스에서 구현을 강제하도록 하는 것.

class Shape  // 추상 클래스. : 순수 가상함수를 포함하는 클래스!
{
public:
    virtual void Draw() = 0; // 순수 가상함수.

};
class Rect : public Shape
{
public:
	virtual void Draw() {} // 구현부를 제공하면 추상 아님.
};


int main()
{
    //Shape  s; // error. : 추상클래스는 객체름 만들 수 없다.
    Shape* p; // ok..

    Rect r; // Draw()구현이 없으면 error
}
