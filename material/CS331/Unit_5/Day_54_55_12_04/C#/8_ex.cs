class Ex
{
	public static void Main()
	{
		System.Collections.Generic.List<int> mylist = 
			new System.Collections.Generic.List<int>();
		int[] a = {11, 22, 33, 44, 55};
		foreach(int e in a)
		{
			mylist.Add(e);
		}
		foreach(var e in mylist)
		{
			int k = e; // no casting
			System.Console.Write("{0}  ", k); 
		}
		System.Console.WriteLine();
		//mylist.Add("abc"); // compile time error
	}
}
