public class Interface_1
{
    public static void main(String[] args)
    {
        IF1 if1 = new A();
        if1.foo();
        IF1 if2 = new A();
        if2.foo();

        B b1 = new B();
        B b2 = new B();
        System.out.println(b1.hashCode());
        System.out.println(b2.hashCode()); // diff
        //		C c = new C(); c.foo(); c.bar(); // ok
        //		IF2 c = new C(); c.foo(); c.bar(); // ok; preferred
        //		IF1 c = new C(); c.foo(); c.bar(); // no
        //			bar is not an interface of IF1

        D d1 = new D(10);
        System.out.println(d1.hashCode());
        D d2 = new D(20);
        System.out.println(d2.hashCode());
    }
}
// can have methods : all public ; no implementation
// no ctor ; no instantiate
// can also fields : static and final
interface IF1 {
    void foo();
    int val = 1729; // final
                    //	String msg = "java string";
    B b = new B();
}
class B
{
}
class A implements IF1
{
    public void foo()
    {
        System.out.println("foo implemented by A");
        System.out.println("val : " + val);
        // val =  1234;
        System.out.println(b.hashCode()); // same for
                                          // every call
    }
}
// can we build an interface using existing interface
interface IF2 extends IF1 {
    void bar();
}

class C implements IF2
{
    public void foo() { System.out.println("foo implemented by C"); }
    public void bar() { System.out.println("bar implemented by C"); }
}
class D
{
    private int x;
    public D(int x) { this.x = x; }
}
