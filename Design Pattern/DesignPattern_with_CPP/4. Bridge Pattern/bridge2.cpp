#include <iostream>
using namespace std;

// Section4. 간접층의 원리
// bridge

// Bridge Pattern
// ★ 구현과 추상화 개념을 분리해서 각각을 독립적으로 변형할 수 있게 하는 패턴이다.
// 구현 : IMP3
// 추상 : MP3
// ★ 즉 모든 mp3는 play, stop을 가져야 한다.. 라는 규칙을 정해주는 인터페이스는 그대로 있고
// ★ 각 mp3 마다 업데이트 해야하는 부분은 MP3에서 해결하여 둘을 독릭접으로 사용할 수 있게 한다.

// 장점 : 독립적인 업데이트★

// 핵심
// 1. MP3라는 클래스를 추가한다.
// -> 사용자의 요구조건을 중간 MP3에서 해결할 수 있게 된다.

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
//---------------------------

class MP3
{
    IMP3* pImpl;
public:
    MP3()
    {
        pImpl = new IPod;
    }
    void Play() { pImpl->Play();}
    void Stop() { pImpl->Stop();}
    void PlayOneMinute()
    {
        pImpl->Play();
        Sleep(1);
        pImpl->Stop();
    }
};

class People
{
public:
    void UseMP3(MP3* p )
    {
        p->Play();
        p->PlayOneMinute();
    }
};


int main()
{

}






//
