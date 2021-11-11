/*

Section4. 에서 나오는 모든 예제들의 공통적인 특징은
★ 간접층을 도입하여 사용한다는 것이다.

List를 Adapter로 감싸서 Stack을 만든 경우.
서버 Proxy를 만든 경우.. 등등


왜 간접층을 사용하는가?? -> ★ "의도" ★가 중요하다.
1. 인터페이스를 변경하려고 -> Adapter ★
2. 어떤 객체에 대한 접근을 제어하기 위한 "대행자"를 만드려고 -> Proxy ★
3. 서브시스템의 복잡한 과정을 감추기 위해 -> Facade ★
4. Update를 독립적으로 수행하기 위해 -> Bridge ★

*/