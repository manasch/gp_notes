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
	System.Collections.Generic.Dictionary<string, string> h = 
			new System.Collections.Generic.Dictionary<string, string> ();
	public void add(string k, string v)
	{
		h[k] = v;
	}
	public void disp()
	{
		foreach(string k in h.Keys)	
		{
			string v = h[k];
			System.Console.WriteLine("{0} {1}", k, v);
		}
	}
}
