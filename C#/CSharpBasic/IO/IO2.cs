using System;

//핵심
// 1. 일반 문자열 "Hello"
// 2. 보간 문자열 $"n={n}"
// 3. 축자 문자열 @"C:\"

class Program
{
    public static void Main()
    {
        int    n = 10;
        double d = 3.4;

        Console.WriteLine(n);

        //서식에 맞춰 출력하는 법
        Console.WriteLine("n = {0} d = {1} {0}", n, d);
        Console.WriteLine($"n = {n} d = {d} {n}"); //$를 써주면 변수의 이름을 곧바로 대입할 수 있다. -> 가독성이 더 좋다.

        Console.WriteLine("C:\\AAA\\BBB\\a.txt");
        Console.WriteLine(@"C:\AAA\BBB\a.txt"); //@로 시작하면 특수문자 취급을 하지 않는다. 고로 백슬래쉬가 모두 출력된다.
        // 파일의 경로 쓸 때 백슬래쉬를 너무 많이쓰면 불편하니 @로 시작하게끔 사용함.
    }
}
