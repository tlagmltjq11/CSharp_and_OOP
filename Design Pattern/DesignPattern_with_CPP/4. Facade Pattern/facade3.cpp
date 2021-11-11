#include <iostream>
#include <WinSock2.h>
#include <string>
using namespace std;

// Section4. 간접층의 원리
// facade

// 핵심
// 1. TCPServer라는 클래스를 새로 설계함.
// -> ★ 사용자는 IP주소랑 Port번호만 넘겨주면 끝이다. -> 굉장히 쉬워짐.

// 3차 API(facade) : 완전히 추상화하여 사용하기 쉽게 만들어 둔다.

// ★ Facade Pattern ★
// 퍼사드 패턴은 서브시스템을 사용하기 쉽게 하기 위한 포괄적 개념의 인터페이스를 제공하는 것이다.
// -> 즉 퍼사드 패턴은 여러 서브 시스템을 합성하여 사용하기 굉장히 쉬운
// -> 일관된 인터페이스를 제공하는 패턴이다.

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

class TCPServer
{
    NetworkInit init;
    Socket sock;
public:
    TCPServer() : sock(SOCK_STREAM) {}

    void Start(const char* sip, short port)
    {
        IPAddress ip(sip, port);
    	sock.Bind(&ip);
    	sock.Listen();
    	sock.Accept();
    }
};

int main()
{
	TCPServer server;
    server.Start( "127.0.0.1", 4000); // 사용이 굉장히 간단해졌다.
}















//
