class Ex
{
	public static void Main()
	{
		System.Collections.ArrayList mylist = new System.Collections.ArrayList();
		System.Console.WriteLine("capacity : {0} count : {1} ",
				mylist.Capacity, mylist.Count);
		mylist.Add(10);
		System.Console.WriteLine("capacity : {0} count : {1} ",
				mylist.Capacity, mylist.Count);
		mylist.Add(20);
		mylist.Add(30);
		mylist.Add(40);
		System.Console.WriteLine("capacity : {0} count : {1} ",
				mylist.Capacity, mylist.Count);
		mylist.Add(40);
		System.Console.WriteLine("capacity : {0} count : {1} ",
				mylist.Capacity, mylist.Count);
				
	}
}
// Count :  actual # of elements
// Capacity : total space available in terms of # of elements

// array : size is fixed at the time of creation
// arraylist : grow
//		count > capacity => normally doubled

