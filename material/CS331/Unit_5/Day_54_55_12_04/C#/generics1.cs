// parameter passing:
//	in parameter : default
//  ref parameter
//  out parameter

// no type erasure
// can use value types
class Entry
{
    static void Main()
    {
        int a = 10;
        int b = 20;
        MySwap(ref a, ref b);
        System.Console.WriteLine("a : {0} b : {1}",
            a, b);
    }
    /*
    static void MySwap(ref int x, ref int y)
    {
        int t = x;
        x = y;
        y = t;
    }
     * */
    // generics
    static void MySwap<T>(ref T x, ref T y)
    {
        T t = x;
        x = y;
        y = t;
    }
}

