class Entry
{
    static void Main()
    {
        MyList<int> list = new MyList<int>();
        for (int i = 1; i <= 5; ++i)
            list.add(i * i);
 //       list.add("fool"); // can give error at compile
        list.disp();

        MyList<string> list1 = new MyList<string>();
        list1.add("amar");
        list1.add("beena");
        list1.add("chandra");
        list1.add("deepak");
        list1.disp();
        list.disp();

    }

}

class MyList<T>
{
    // implementation class
    class Node// Node is hidden from the client
    {
        T key;
        Node next;
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
    Node head = null;
    Node tail = null;
    public void disp()
    {
        Node t = head;
        while (t != null)
        {
            T x = t.Key;
            System.Console.WriteLine("{0} ", x);
            t = t.Next;
        }
    }
    // add at the end
    public void add(T o)
    {
        Node t = new Node(o);
        if (head == null)
        {
            head = tail = t;
        }
        else
        {
            tail.Next = t;
            tail = t;
        }
    }
}
