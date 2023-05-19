class Ex
{
	public static void Main()
	{
		Places places = new Places();
		string [,] all = new string[,]
			{
				{ "karnataka", "bangalore" },
				{ "kerala", "Kochi" },
				{ "kerala", "munnar" },
				{ "tamilnad", "chennai"},
				{ "karnataka", "mysore" },
				{ "tamilnad", "madurai" },
				{ "tamilnad", "salem" },
				{ "kerala", "trivandrum" },
				{ "karnataka", "hassan" }
			};
	//	System.Console.WriteLine("# of elements : {0} ", all.Length); // 18
	//	System.Console.WriteLine("upper bound of dimension 1 : {0}",
	//		all.GetUpperBound(0));
	//	System.Console.WriteLine("upper bound of dimension 2 : {0}",
	//		all.GetUpperBound(1));
		for(int i = 0; i <= all.GetUpperBound(0); ++i)
		{
	//		System.Console.WriteLine("{0} {1}", all[i, 0], all[i, 1]);
			places.add(all[i, 0], all[i, 1]);
		}
		places.disp();
	}
}
class Places
{
	System.Collections.Hashtable h = new System.Collections.Hashtable();
	// if key does not exist,
	//	create a new arraylist; associate with the key
	// add value to the list for that key
	public void add(string k, string v)
	{
		if(!h.Contains(k))
			h[k] = new System.Collections.ArrayList();
		((System.Collections.ArrayList)h[k]).Add(v);
	}
	public void disp()
	{
		foreach(string k in h.Keys)	
		{
			System.Console.WriteLine("{0}", k);
			foreach(string v in (System.Collections.ArrayList)h[k])
				System.Console.WriteLine("  {0}", v);
		}
	}
}
