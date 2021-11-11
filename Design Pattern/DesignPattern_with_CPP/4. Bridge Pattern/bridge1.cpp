#include <iostream>
using namespace std;

// Section4. 간접층의 원리
// bridge

// 핵심
// 1. MP3를 대표하는 인터페이스를 제공한 상태
// -> 고객이 1분 미리듣기 기능을 요청함.
// -> 해당 기능을 인터페이스 넣게되면 존재하는 모든 MP3에 기능이 추가됨..

// MP3의 규칙을 제공
struct IMP3
{
    virtual void Play() = 0;
    virtual void Stop() = 0;
    virtual ~IMP3() {}
};

class IPod :  public IMP3
{
public:
    void Play() { cout << "Play MP3" << endl;}
    void Stop() { cout << "Stop MP3" << endl;}
};

class People
{
public:
    void UseMP3(IMP3* p )
    {
        p->Play();
        p->PlayOneMinute(); // 고객이 1분 미리듣기 기능을 요청함.
		// -> 해당 기능을 인터페이스 넣게되면 존재하는 모든 MP3에 기능이 추가됨..
    }
};


int main()
{

}






//
