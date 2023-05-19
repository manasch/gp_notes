// inner class:
//	inner class which has a reference to the outer class
//	static inner class
//	anonymous inner class
//		extends a class at the point of creation
//			of the object
//		cannot be extended ; is a final class
//		cannot introduce new methods
//			call is thro the superclass interface
//			no name to cast to subclass interface
//		no ctor
//		attributes not meaningful
//		used to override methods of the named
//			super class
import java.util.*;
public class Inner_4
{
    public static void main(String[] args)
    {
        IWhat i1 = new A();
        caller(i1);
        /*
        class NoName extends A
        {
                public void foo()
                {
                        System.out.println("new one");
                }
        }
        NoName y = new NoName();
        */
        A y = new A() {
            public void foo() { System.out.println("new one"); }
        };
        // y.foo();
        caller(y);
        /*
        IWhat i2 = new IWhat() {
                public void foo()
                {
                        System.out.println
                        ("implements interface");
                }
        };
        i2.foo();

        caller(new IWhat() {
                public void foo()
                {
                        System.out.println
                        ("implements a new interface");
                }
        });

        Integer a[] = { 44, 22, 33, 11, 55 };
        Arrays.sort(a, new Comparator<Integer>() {
                public int compare(Integer x, Integer y)
                {
                        return y - x;
                }
        });
        System.out.println(Arrays.toString(a));
        */
    }
    static void caller(IWhat w) { w.foo(); }
}

interface IWhat {
    void foo();
}

class A implements IWhat
{
    public void foo() { System.out.println("foo A"); }
}
