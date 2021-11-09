using System;

// 핵심
// 1. indexer : 객체를 배열처럼 사용할 수 있게 하는 문법 
// -> 프로퍼티와 생성방식이 매우 유사하다.
// 프로퍼티 이름자리에 this[int idx]만 넣어주면 된다.
// C++ 에서 "[] 연산자 재정의와 동일"

class Sentence
{
    private string[] words = null;

    public Sentence(string s) { words = s.Split(); }

    //public string Name
    public string this[ int idx ]
    {
        get { return words[idx]; }
        set { words[idx] = value; }
    }

    public override string ToString()
    {
        // 배열에있는 모든 요소를 공백으로 띄워가며 합치라는 의미
        return string.Join(" ", words);
    }
}


class Program
{
    public static void Main()
    {
        Sentence s = new Sentence("Dog is Animal");

        s[0] = "Cat";

        Console.WriteLine(s[0]); // Cat
        Console.WriteLine(s);    // Cat is Animal

                // s.ToString()
                
                    
    }
}