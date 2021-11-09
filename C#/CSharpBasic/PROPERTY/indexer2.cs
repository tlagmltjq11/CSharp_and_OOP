using System;

// 핵심
// 1. 사실 인덱서는 매개변수를 갖는 프로퍼티라고 봐도 무방하다.
// -> 실제로 같이 취급하는 서적도 많다.

class Sentence
{
    private string[] words = null;
    public Sentence(string s) { words = s.Split(); }

    // property
    public string Name { get; set; } = "UNKNOWN";


    // indexer
    // get_Item(int idx)
    // set_Item(int idx, string value)
    // 위 두 메소드가 내부적으로 생성된다.
    // 고로 set에 매개변수를 넣는 프로퍼티라고 볼 수 있다.
    public string this[int idx]
    {
        get { return words[idx]; }
        set { words[idx] = value; }
    }
}


class Program
{
    public static void Main()
    {
        Sentence s = new Sentence("Dog is Animal");

        s[0] = "Cat";
    }
}