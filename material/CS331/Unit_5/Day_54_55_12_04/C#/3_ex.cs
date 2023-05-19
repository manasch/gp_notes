class Ex
{
	public static void Main()
	{
		System.Collections.ArrayList mylist = new System.Collections.ArrayList();
		int[] a = {11, 22, 33, 44, 55};
		foreach(int e in a)
		{
			mylist.Add(e);
		}
		// mylist.Add("abc");
		foreach(var e in mylist)
		{
			int k = (int)e;
			System.Console.Write("{0}  ", k); 
		}
		System.Console.WriteLine();
	}
}
