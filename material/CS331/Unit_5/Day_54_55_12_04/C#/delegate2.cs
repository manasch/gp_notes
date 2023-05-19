// delegate
//  similar to pointer to function or functor
//  is a reference type
//  can refer to a static or a non static fn
//     to make it refer to an instance fn,
//      while assigning also provide the object

// mutlicast delegate
//      return type should be void
delegate void fnptr_t(); // type called delegate
class Entry
{
    static void Main()
    {
        fnptr_t ptr = new fnptr_t(f1);
        //    System.Console.WriteLine(ptr == null);
        ptr();
        System.Console.WriteLine("-------------------------");
        //ptr = ptr + f2;
        ptr += f2;
        ptr();
        System.Console.WriteLine("-------------------------");
        ptr += f3;
        ptr();
        System.Console.WriteLine("-------------------------");
        ptr -= f2;
        ptr();
        System.Console.WriteLine("-------------------------");
 
  
    }

    static void f1()
    {
        System.Console.WriteLine("f1 called");

    }
    static void f2()
    {
        System.Console.WriteLine("f2 called");

    }
    static void f3()
    {
        System.Console.WriteLine("f3 called");

    }
 
}


// C Puzzle book
//  Feuer

