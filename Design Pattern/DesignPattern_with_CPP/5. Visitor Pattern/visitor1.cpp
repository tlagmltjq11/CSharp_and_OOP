#include <iostream>
#include <list>
using namespace std;

// Section5. 통보, 열거, 방문
// visitor

// 핵심
// ★ Visitor Pattern : 객체 구조에 속한 요소에 수행 할 오퍼레이션을 정의하는 객체
// -> ★ 기존 클래스를 변경하지 않고(멤버 함수를 추가하지 않고) 새로운 오퍼레이션을
// -> 정의할 수 있게 된다.

int main()
{
    list<int> s = { 1,2,3,4,5,6,7,8,9,10};

    // 모든 요소를 2배로 만들고 싶다.
    // 방법1. 외부에서 직접 연산 수행.
    for ( auto& n : s )
        n = n * 2;

	// 위 동작이 복잡하고 자주 사용된다면 차라리 멤버 함수로 제공?
	// -> ★ 멤버 함수를 추가한다는 것은 쉬운 일이 아니다.
	// -> 수정되어야 할 부분들이 굉장히 많고, 완전히 다른 클래스로 탈바꿈 될 수도 있다.
    // 방법 2. 멤버 함수로 기능을 제공
    s.twice_all_element();
    s.show_all_element();

    // 방법 3. 방문자 패턴을 사용한다.
    TwiceVisitor<int> tv; // 방문자.
    s.accept(&tv);

    ShowVisitor<int> sv; // 방문자.
    s.accept(&sv);

}





//
