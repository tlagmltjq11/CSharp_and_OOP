using System;

// 핵심
// 1. 인터페이스의 메소드 구현 시 override를 표기하지 않는다.
// -> virtual을 붙여 가상으로 만들어도 된다! (어쨌든 구현한거니까)

interface ICamera
{
    void Take();
}

class MP3
{
    public virtual void Play() { }
}

class SmartPhone : MP3, ICamera
{
    public override void Play() { }

    //public void Take() { }
    public virtual void Take() { }
}

class Program
{
    static void Main()
    {

    }
}
