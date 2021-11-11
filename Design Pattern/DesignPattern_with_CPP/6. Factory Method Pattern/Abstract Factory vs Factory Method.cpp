/*

							팩토리 메서드										추상팩토리

결합도를 낮추는 대상		클라이언트 코드와 인스턴스를 만들어야				클라이언트에서 서로 연관된 일연의 제품들을
							할 구상 클래스를 분리시켜야 할때 사용				만들어야 할때 사용
							어떤 구상 클래스를 필요로 하게 될지 미리			( ConcreteFactory <-> Client )
							알 수 없는 경우 사용
							( ConcreteProduct <->  Client )
							


객체 생성 지원 범위			한 팩토리당 한 종류									한 팩토리에서 서로 연관된 여러 종류 모두 지원
							( create 메서드가 Factory 클래스에 1개)				( create() 메서드가 팩토리 클래스에 여러 개)



사용 목적					클라이언트 코드와 인스턴스를 만들어야 할 구상		클라이언트에서 서로 연관된 일련의 제품들
							클래스를 분리시켜야 할때 사용						을 만들어야 할때 사용 
							어떤 구상 클래스를 필요로 하게 될지 미리
							알 수 없는 경우 사용


*/