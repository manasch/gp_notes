import java.util.*;
public class Test
{
    public static void main(String[] s)
    {
        Comparable<MyNum> a[] =
            new MyNum[] {new MyNum(25), new MyNum(11), new MyNum(9),

                         new MyNum(36), new MyNum(12)};
        System.out.println(Arrays.toString(a));
        mysort(a);
        System.out.println(Arrays.toString(a));
    }
    public static void mysort(Comparable<MyNum>[] a)
    {
        int n = a.length;
        int i;
        int j;
        for (i = 0; i < n - 1; ++i)
        {
            for (j = i + 1; j < n; ++j)
            {
                if (a[i].compareTo((MyNum)a[j]) > 0)
                {
                    Comparable<MyNum> temp;
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
    }
}

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
