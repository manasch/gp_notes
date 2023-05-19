// make a linked list

// var : make the compiler deduce the type based on initialization
class Ex
{
	public static void Main()
	{
		//var t = 10; // t becomes int
		//var x = new List(); // x becomes List
		int[] a = {11, 22, 33, 44, 55};
		List<int> mylist = new List<int>();
		foreach(var e in a)
		{
			mylist.add(e);
		}
		mylist.disp();
		// mylist.add("nxp"); // compile time error
		
		List<string> strlist = new List<string>();
		strlist.add("shiva");
		strlist.add("rama");
		strlist.add("krishna");
		strlist.disp();
		
	}
}

// we has a class of Object
// now it is class of type T
// create a List of some type say T
class List<T>
{
	private Node head = null;
	private Node tail = null;
	private class Node
	{
		private T key;
		private Node next;
		public Node(T key)
		{
			this.key = key;
			this.next = null;
		}
		public T Key
		{
			get { return key; }
		}
		public Node Next
		{
			get { return next; }
			set { next = value; }
		}
	}
	public void add(T key)
	{
		Node temp = new Node(key);
		if(head == null)
		{
			head = tail = temp;
		}
		else
		{
			tail = tail.Next = temp;
		}
	}
	public void disp()
	{
		Node temp = head;
		while(temp != null)
		{
			T k = temp.Key;
			System.Console.Write("{0} ", k);
			temp = temp.Next;
		}
		System.Console.WriteLine();
	}
}






