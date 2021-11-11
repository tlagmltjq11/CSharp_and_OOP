#include <iostream>
using namespace std;

// Section4. �������� ����
// bridge

// �ٽ�
// 1. MP3�� ��ǥ�ϴ� �������̽��� ������ ����
// -> ���� 1�� �̸���� ����� ��û��.
// -> �ش� ����� �������̽� �ְԵǸ� �����ϴ� ��� MP3�� ����� �߰���..

// MP3�� ��Ģ�� ����
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
        p->PlayOneMinute(); // ���� 1�� �̸���� ����� ��û��.
		// -> �ش� ����� �������̽� �ְԵǸ� �����ϴ� ��� MP3�� ����� �߰���..
    }
};


int main()
{

}






//
