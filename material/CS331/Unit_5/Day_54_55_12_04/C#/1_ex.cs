// make a linked list

// var : make the compiler deduce the type based on initialization
class Ex
{
	public static void Main()
	{
		//var t = 10; // t becomes int
		//var x = new List(); // x becomes List
		int[] a = {11, 22, 33, 44, 55};
		List mylist = new List();
		foreach(var e in a)
		{
			mylist.add(e);
		}
		mylist.disp();
		mylist.add("nxp"); // ok
		
		// runtime error
	//	mylist.disp();
		
	}
}
// class within a class
//	private class
//	hidden

class List
{
	private Node head = null;
	private Node tail = null;
	private class Node
	{
		private object key;
		private Node next;
		public Node(object key)
		{
			this.key = key;
			this.next = null;
		}
		public object Key
		{
			get { return key; }
		}
		public Node Next
		{
			get { return next; }
			set { next = value; }
		}
	}
	public void add(object key)
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
			int k = (int)temp.Key;
			System.Console.Write("{0} ", k);
			temp = temp.Next;
		}
		System.Console.WriteLine();
	}
}
// convert : anything of anytype => object : trivial : upcasting
//           derived class => base class
// convert : base class => derived ; not automatic; requires casting


// programming to object class:
//	no compile time error
//	converting back to a required type may cause runtime error








