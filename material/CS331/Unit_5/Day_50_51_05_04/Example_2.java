public class Example_2
{
	public static void main(String[] args)
	{
		System.out.println("hello world");
		Box b = new Box();
		b.put(25);
		//int x = b.get(); // requires an explicit cast
		int x = (Integer)b.get();
		System.out.println("x : " + x);
		
		b.put("hello");
	//	x = (Integer)b.get(); // throws classcastexception
		
		
	}
} 

// put something into the box
// get it out

class Box
{
	private Object o;
	public Object get() { return o; }
	public void put(Object o) { this.o = o; } 
}

//  two short comings:
//	get requires a cast
//	might throw runtime errors




