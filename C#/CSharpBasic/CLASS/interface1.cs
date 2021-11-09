using System;
using System.Collections;

// 핵심
// 1. 일관된 형태의 라이브러리를 만들기 위해
// "클래스들이 사용하는 메소드의 이름을 약속" 할 수 없을까?
// -> 인터페이스를 사용해서 약속하자!

// 2. 인터페이스란 클래스를 "만드는 사람과 사용하는 사람 사이의 규칙을 정의" 하는 것이다.

// 3. C# 언어의 핵심
// 다양한 인터페이스를 먼저 설계(제공)하고 대부분의 클래스는
// "특정 인터페이스를 구현하는 방식으로 메소드를 제공" 한다.
// ex) 대부분의 Collections 클래스는 "ICollection 인터페이스를 구현" 한다.
// -> List에는 Clear() 메소드가 있다는 의미.

/*
interface IList
{
    void Clear();
}
*/

// 모든 컬렉션은 반드시 IList 를 구현해야 한다.
// 인터페이스는 재정의가 아니라 구현이라는 점 유의
class Stack : IList 
{
    public void Clear() { }
}

class Queue : IList
{
    public void Clear() { }
}

class Program
{
    static void Main()
    {

    }
}
