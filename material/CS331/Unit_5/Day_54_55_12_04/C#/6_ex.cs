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
	public void add(string k, string v)
	{
		h[k] = v;
	}
	public void disp()
	{
		foreach(string k in h.Keys)	
		{
			string v = (string)h[k];
			System.Console.WriteLine("{0} {1}", k, v);
		}
	}
}
