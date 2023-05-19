     
class Entry
{
    static void Main()
    {
        A a = new A();
        DoSave(a);
        B b = new B();
        DoSave(b);

    //    DoSync(a);
        DoSync(b);
    //    a = b;
    //    DoSync(a); // error

    }

    static void DoSave(IPersist ipersist)
    {
        ipersist.save();
        ipersist.load();

    }
    static void DoSync(ISync isync)
    {
        isync.mylock();
        isync.myunlock();
      
    }
}

class A : IPersist
{
    public virtual void save()
    {
        System.Console.WriteLine("save of A called");
    }
    public virtual void load()
    {
        System.Console.WriteLine("save of A called");
    }
}

class B : A, ISync
{
    public override void save()
    {
        System.Console.WriteLine("save of B called");
    }
    public  void mylock()
    {
        System.Console.WriteLine("save of B called");
    }
    public  void myunlock()
    {
        System.Console.WriteLine("save of B called");
    }
}

interface IPersist
{
    void save();
    void load();
}

interface ISync
{
    void mylock();
    void myunlock();
}

