#include <iostream>
using namespace std;

// Section4. �������� ����
// bridge

// Bridge Pattern
// �� ������ �߻�ȭ ������ �и��ؼ� ������ ���������� ������ �� �ְ� �ϴ� �����̴�.
// ���� : IMP3
// �߻� : MP3
// �� �� ��� mp3�� play, stop�� ������ �Ѵ�.. ��� ��Ģ�� �����ִ� �������̽��� �״�� �ְ�
// �� �� mp3 ���� ������Ʈ �ؾ��ϴ� �κ��� MP3���� �ذ��Ͽ� ���� ���������� ����� �� �ְ� �Ѵ�.

// ���� : �������� ������Ʈ��

// �ٽ�
// 1. MP3��� Ŭ������ �߰��Ѵ�.
// -> ������� �䱸������ �߰� MP3���� �ذ��� �� �ְ� �ȴ�.

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
