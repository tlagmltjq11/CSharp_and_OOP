#include <iostream>
#include <algorithm>
using namespace std;

// 핵심
// 이전까지는 멤버 함수에서 변하는 부분을 분리했다.
// 이번 예제에서는 "일반 함수"에서 변하는 부분을 분리하는 과정이다.
// 멤버가 아니므로 "사용자가 정책을 바꿀 수 있는 방식은 메소드 인자" 밖에 없다.
// -> ★ 고로 일반 함수는 정책 교체를 메소드 인자로 넘겨주어야 한다.

// 1. 사용자 입장에서 정책을 바꾸려면 내부코드 자체를 바꿔야 하는 상황.
// -> 변해야하는 정책 부분은 분리해내자

// qsort()
void Sort(int* x, int sz, bool(*cmp)(int, int))
{
    for (int i = 0; i < sz-1; i++)
    {
        for( int j = i + 1; j < sz; j++)
        {
            //if ( x[i] < x[j] )

            if ( cmp( x[i],  x[j])  )
                swap( x[i], x[j] );
         }
     }
}

bool cmp1( int a, int b) { return a < b;}
bool cmp2( int a, int b) { return a > b;}
int main()
{
    int x[10] = { 1,3,5,7,9,2,4,6,8,10};

    Sort( x, 10, &cmp2);

    for ( auto n : x)
        cout << n << ", ";
}













//
