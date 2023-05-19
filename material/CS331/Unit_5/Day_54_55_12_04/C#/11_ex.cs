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
		for(int i = 0; i <= all.GetUpperBound(0); ++i)
		{
			places.add(all[i, 0], all[i, 1]);
		}
		places.disp();
	}
}
class Places
{
//	System.Collections.Hashtable h = new System.Collections.Hashtable();
	
	System.Collections.Generic.Dictionary
			<string, System.Collections.Generic.List<string>> h = 
		new System.Collections.Generic.Dictionary
			<string, System.Collections.Generic.List<string>>();
			
	public void add(string k, string v)
	{
		if(!h.ContainsKey(k))
			h[k] = new System.Collections.Generic.List<string>();
		h[k].Add(v);
	}
	public void disp()
	{
		foreach(string k in h.Keys)	
		{
			System.Console.WriteLine("{0}", k);
			foreach(string v in h[k])
				System.Console.WriteLine("  {0}", v);
		}
	}
}
