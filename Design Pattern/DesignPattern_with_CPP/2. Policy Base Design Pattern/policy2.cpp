#include <iostream>
using namespace std;

// Section2. ���뼺�� �������� �и�
// Policy Base Design

// �ٽ�
// 1. ����ȭ ó�� �κ��� �и��س� �� ������������ ������

// 2. ������ ���� ���̴� ���������� ���� push_front�� �� ���� ȣ��ȴٸ�
// -> �� �����Լ��� ������� ������ Ŀ�� �� �ִ�.

struct ISync
{
    virtual void Lock() = 0;
    virtual void UnLock() = 0;
    virtual ~ISync() {} // ��� ���Ŭ������ ���� �Ҹ��ڸ� ������ �Ѵ�.
};

template<typename T> class List
{
    ISync* pSync = 0;
public:
    void setSync(ISync* p) { pSync = p;}

    void push_front(const T& a)
    {
        if ( pSync != 0 ) pSync->Lock();
        //...
        if ( pSync != 0 ) pSync->UnLock();
    }
};

// Mutex ��å
class MutexLock : public ISync
{
    // mutex m;
public:
    virtual void Lock()  {}
    virtual void UnLock() {}
};

List<int> s;

int main()
{
    MutexLock m;
    s.setSync(&m);

    s.push_front(10);


    NoLock m2; // NoLock ��å�� �����ߴٰ� ����
    s.setSync(&m2);

}
