class Entry
{
    static void Main()
    {
        MyList list = new MyList();
        for (int i = 1; i <= 5; ++i)
            list.add(i * i);
 //       list.add("fool"); // can give error at runtime
        list.disp();
    }

}

class MyList
{
    // implementation class
    class Node // Node is hidden from the client
    {
        object key;
        Node next;
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
    Node head = null;
    Node tail = null;
    public void disp()
    {
        Node t = head;
        while (t != null)
        {
            int x = (int)t.Key;
            System.Console.WriteLine("{0} ", x);
            t = t.Next;
        }
    }
    // add at the end
    public void add(object o)
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