using System;

// 핵심
// 1. 컬렉션이란 "동일 타입의 객체를 여러 개 보관" 할 수 있는 클래스

// 2. 어떤 타입을 보관할 것인가? 에 따라서 4가지로 나뉜다.
// Object를 저장하는 컬렉션 : Collections
// 특정 타입만 저장하는 컬렉션 : Collections.Specialized
// 사용자가 지정하는 타입을 저장하는 컬렉션 : Collections.Generic
// Thread safe 컬렉션 : Collections.Concurrent

namespace CSHARP.CSharpBasic.Collections
{
    class collections1
    {
        int[] arr1 = { 1, 2, 3, 4, 5 };
        string[] arr2 = { "aa", "bb", "cc" };
    }
}
