class Ex
{
	public static void Main()
	{
		System.Collections.Hashtable myhash = new System.Collections.Hashtable();
		//key value pairs
		myhash["ramanujan"] = 1729;
		myhash["prime"] = 29;
		myhash["odd"] = 11;
		foreach(string k in myhash.Keys)
		{
			int val = (int)myhash[k];
			System.Console.WriteLine("{0} {1}", k, val);
		}
	}
}
