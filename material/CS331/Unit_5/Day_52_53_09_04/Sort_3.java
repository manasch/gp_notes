import java.util.*;
public class Sort_3
{
    public static void main(String[] args)
    {
        Comparable<MyNum> a[] =
            new MyNum[] {new MyNum(25), new MyNum(11), new MyNum(9),
                         new MyNum(36), new MyNum(12)};

        //	System.out.println(Arrays.toString(a));
        //	Arrays.sort(a);
        //	System.out.println(Arrays.toString(a));

        //	int b[] = {11, 55, 33, 22, 44 };
        //	Arrays.sort(b);
        //	System.out.println(Arrays.toString(b));

        System.out.println(Arrays.toString(a));
        mysort(a);
        System.out.println(Arrays.toString(a));
        /*
                        mysort(a, new Compare());
                        System.out.println(Arrays.toString(a));
                        mysort(a, new NewCompare());
                        System.out.println(Arrays.toString(a));
        */
    }
    public static String disp(MyNum[] x)
    {
        String res = "[ ";
        for (MyNum elem : x)
        {
            res = res + elem + ",";
        }
        res = res + "]";
        return res;
    }

    public static void mysort(Comparable<MyNum>[] a)
    {
        int n = a.length;
        int i;
        int j;
        for (i = 0; i < n - 1; ++i)
            for (j = i + 1; j < n; ++j)
            {
                if (a[i].compareTo((MyNum)a[j]) > 0)
                {
                    Comparable temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = (MyNum)temp;
                }
            }
    }
    /*
            public static void mysort(MyNum[] a, Compare c)
            {
            //	System.out.println("mysort");
                    int n = a.length;
                    int i; int j;
                    for(i = 0; i < n - 1; ++i)
                            for(j = i + 1; j < n; ++j)
                            {
                                    if(c.compare(a[i], a[j]) > 0)
                                    {
                                            MyNum temp;
                                            temp = a[i];
                                            a[i] = a[j];
                                            a[j] =  temp;
                                    }

                            }
            }
            */
}

// class MyNum implements Comparable
class MyNum implements Comparable<MyNum>
{
    private int val;
    public MyNum(int val) { this.val = val; }
    public String toString() { return val + "\t"; }
    @Override public int compareTo(MyNum other)
    {
        return other.val % 10 - val % 10;
    }
    int getVal() { return val; }
}

class Compare
{
    public int compare(MyNum x, MyNum y) { return x.getVal() - y.getVal(); }
}
class A
{
}
class NewCompare extends Compare // ok
{
    static int sum(int x)
    {
        int s = 0;
        while (x > 0)
        {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    public int compare(MyNum x, MyNum y)
    {
        return sum(x.getVal()) - sum(y.getVal());
    }
}

// classes with no data members
//	a) mimic procedural approach
//		all the methods are static
//		Math Arrays
//	b) make a callback
//		has to be an instance method
//		should be overridable from the subclass
