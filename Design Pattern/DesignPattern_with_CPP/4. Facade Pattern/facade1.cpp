// how to build
// g++ facade1.cpp -lws2_32
// cl  facade1.cpp /link ws2_32.lib
#include <iostream>
#include <WinSock2.h>
using namespace std;

// Section4. 간접층의 원리
// facade (퍼사드)

// 핵심
// 1. 아래 소켓 관련 함수를 클래스화 하는 것이 현재 목표다.
// 1) 하나의 클래스에 모든 기능을 넣는다. (X)
// 2) 기능 별로 분리해서 각각 클래스로 설계한다. (O)

// ★ 최대한 클래스를 작게 만들어야 유지보수에도 좋고 기능별로 분리해야
// ★ 단일책임의 원칙도 지킬 수 있다.

// 1차 API : C함수로 제공 즉 모든 것을 직접 코딩..

int main()
{
    // 1. 네트워크 라이브러리 초기화
	WSADATA w;
	WSAStartup(0x202, &w);

	// 2. 소켓 생성
	int sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓

	// 3. 소켓에 주소 지정
	struct sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	// 4. 소켓을 대기 상태로변경
	listen(sock, 5);

	// 5. 클라이언트가 접속할때 까지 대기
	struct sockaddr_in addr2 = { 0 };
	int sz = sizeof(addr2);

	accept(sock, (SOCKADDR*)&addr2, &sz);

    // 6. socket 라이브러리 cleanup
	WSACleanup();
}
