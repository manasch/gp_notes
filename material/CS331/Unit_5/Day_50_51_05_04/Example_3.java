public class Example_3
{
	public static void main(String[] args)
	{
		System.out.println("hello world");
		Box<Integer> b = new Box<Integer>();
		b.put(25);
		int x = b.get(); // no casting required
		System.out.println("x : " + x);
		
	//	b.put("hello"); // compile time error
	
		Box<String> s = new Box<String>();
		s.put("hello");
		String s1 = s.get();
		System.out.println("s1 : " + s1);
		System.out.println(s.i);
		
	}
} 

// Generic class

class Box<T>
{
	static int i;
	private T o;
	public T get() { ++i;return o; }
	public void put(T o) { ++i;this.o = o; } 
}

//  generics
//	no cast
//	incompatible types => compile time error

// At runtime - after compilation - there shall be one and only one
// class called Box
// Does not depend on for how many types the class has been instantiated
// Effectively after compilation, generic type shall be replaced by Object
// Type Erasure
//	no static members in the class
//	only for reference types and not value types



