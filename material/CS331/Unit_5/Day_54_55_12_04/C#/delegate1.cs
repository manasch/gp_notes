// delegate
//  similar to pointer to function or functor
//  is a reference type
//  can refer to a static or a non static fn
//     to make it refer to an instance fn,
//      while assigning also provide the object
/*
void foo() { 
// some code
}
void (*ptr_fn)(); // ptr_fn : variable
ptr_fn = foo;

or

typedef void (*ptr_fn_t)(); // ptr_fn_t : typename
ptr_fn_t p = foo;
p();

*/
delegate void fnptr_t(); // type called delegate
class Entry
{
    delegate int myop_t(int x, int y);
    private int x;
    public Entry(int x)
    {
    	this.x = x;
    }
    static void Main()
    {
        fnptr_t ptr = new fnptr_t(f1);
    //    System.Console.WriteLine(ptr == null);
        ptr();
        ptr = f2;
        ptr();

        myop_t myop = new myop_t(add);
        System.Console.WriteLine("res : {0}", myop(10, 20));
        myop = mul;
        System.Console.WriteLine("res : {0}", myop(10, 20));
 
        Entry e = new Entry(5);
        myop = e.memfn; // binding callable to an object
        // required for instance function
        System.Console.WriteLine("res : {0}", myop(10, 20));

    }

    static void f1()
    {
        System.Console.WriteLine("f1 called");

    }
    static void f2()
    {
        System.Console.WriteLine("f2 called");

    }
    static int add(int x, int y)
    {
        return x + y;

    }
    static int mul(int p, int q)
    {
        return p * q;
    }
    int memfn(int aa, int bb)
    {
        return aa * aa + bb * bb + this.x;
    }

}



