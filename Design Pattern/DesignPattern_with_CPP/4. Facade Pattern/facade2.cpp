#include <iostream>
#include <WinSock2.h>
using namespace std;

// Section4. 간접층의 원리
// facade

// 핵심
// 1. 세부적인 코드가 클래스 내부에서 처리 되므로 사용하기 간결하고 쉽다.
// -> ★ 좀 더 사용하기 쉽고 간결한 형태로 제공 할 수 없을까? (네트워크를 잘 모르는 사용자라고 가정)
// -> 다음 코드에서..

// 2차 API : 분야/기능 별 클래스로 제공 (어느정도 네트워크에 이해가 있는 사람을 위함)

// network 라이브러리의 초기화와 cleanup을 담당.
class NetworkInit
{
public:
	NetworkInit()
	{
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		WSACleanup();
	}
};

// IP 주소 관리.
class IPAddress
{
	struct sockaddr_in addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	struct sockaddr* getRawAddress() { return (struct sockaddr*)&addr; }
};

// socket 프로그래밍의 일반적인 절차.
class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(struct sockaddr_in));
	}
	void Listen() { ::listen(sock, 5); }
	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);
		accept(sock, (struct sockaddr*)&addr2, &sz);
	}
};



int main()
{
	NetworkInit init;
	IPAddress ip("127.0.0.1", 4000);
	Socket sock(SOCK_STREAM); // TCP
	sock.Bind(&ip);
	sock.Listen();
	sock.Accept();
}









//
