public class MyComplex
{
    public MyComplex(double rp, double ip)
    {
        this.rp = rp;
        this.ip = ip;

    }
    double rp = 0.0;
    double ip = 0.0;
    public override string ToString()
    {
        return rp.ToString() + " +j" + ip.ToString();
    }
    public static MyComplex add(MyComplex lhs, MyComplex rhs)
    {
        return new MyComplex(lhs.rp + rhs.rp,
            lhs.ip + rhs.ip);
    }
    public static MyComplex operator+(MyComplex lhs, MyComplex rhs)
    {
        return new MyComplex(lhs.rp + rhs.rp,
            lhs.ip + rhs.ip);
    }
    // property
    public double Magnitude
    {
        get
        {
            return System.Math.Sqrt(rp * rp + ip * ip);
        }
    }
    public double RealPart
    {
        get
        {
            return this.rp;
        }
        set
        {
         	this.rp = value;
        }
    }
    // indexer
    public double this[int i]
    {
        get
        {
            switch (i)
            {
                case 0: return rp;
                case 1: return ip;
                default: return 0.0;
            }
        }
    }
    // convert from one type to another
    // type conversion operator

    // return type cannot be specified
    // should use implicit or explicit 
    public static   explicit operator double(MyComplex c)
    {
        return c.rp;
    }
}
public class Client
{
	public static void Main()
	{
		MyComplex c = new MyComplex(3.0, 4.0);
		System.Console.WriteLine("magnitude : {0} ", c.Magnitude);
		//c.Magnitude = 10;
		System.Console.WriteLine("rp : {0} ", c.RealPart);
		c.RealPart = 5.0;
		System.Console.WriteLine("rp : {0} ", c.RealPart);
		System.Console.WriteLine("rp : {0} ", c[0]);
		
	}
}
