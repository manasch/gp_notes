// delegate int delegate_t(int p, int q);

class Entry
{
    static void Main()
    {
        delegate_t op = new delegate_t(add);
        System.Console.WriteLine("res : {0} ",
            What.compute(10, 20, op));
        op = mul;
        
        System.Console.WriteLine("res : {0} ",
            What.compute(10, 20, op));
        int[] x = { 1, 2, 3, 4, 5 };
        System.Console.WriteLine("res : {0} ",
                    What.sum(x));
        System.Console.WriteLine("res : {0} ",
                    What.sum(x, 0));
        System.Console.WriteLine("res : {0} ",
                    What.sum(x, 100));
        op = add;
        System.Console.WriteLine("res : {0} ",
              What.sum(x, 0, op));
        op = mul;
        System.Console.WriteLine("res : {0} ",
              What.sum(x, 1, op));
  
    }
    static int add(int x, int y)
    {
        return x + y;
    }
    static int mul(int x, int y)
    {
        return x * y;
    }

}