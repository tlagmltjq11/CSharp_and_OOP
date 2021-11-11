/*

핵심 : ★ 변하지 않는 코드에서 변하는 부분은 분리 되어야 한다.

1. 일반 함수에서 변하는 부분 분리
-> 함수 인자로 분리


2. 멤버 함수에서 변하는 부분 분리
	2.1 가상 함수로 분리 : Template Method
	-> 실행시간에 교체 할 수 없고, 변하는 코드를 재사용 할 수 없다.
	-> 상속 기반의 패턴

	2.2 다른 클래스로 분리
	-> 정책을 재사용 할 수 있다.

		2.2.1 인터페이스로 교체 : Strategy, State Pattern
		-> 실행시간 교체 가능, 가상함수 기반(성능 저하)

		2.2.2 Generic 인자로 교체 : Policy Base Design
		-> 실행시간 교체 불가능, 인라인 치환 가능(빠르다)

*/