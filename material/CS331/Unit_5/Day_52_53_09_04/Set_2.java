// interface provides multiple implementations
// List Interface :
//		LinkedList
//		ArrayList
// Set Interface
//		HashSet   : similar to unordered set in C++
//			use hashCode
//			equals
//		TreeSet : similar to sorted associative set container
//			ht balanced binary search tree
//		LinkedHashSet : based on Hashing; we can also traverse in the
// input order
import java.util.*;
public class Set_2
{
    public static void main(String[] args)
    {
        int a[] = {20, 30, 10, 40, 10, 30, 10, 20, 30, 40};
        // uses hashing ; convert an object to
        //	an int value
        //	store the object at that loc
        //		in some data structure
        // order is not defined
        //		Set<Integer> s =  new HashSet<Integer>();

        //		uses a ht balanced binary search tree
        //		elements will be in order

        //		Set<Integer> s =  new TreeSet<Integer>();

        //		based on hashing; traverse in the input order
        Set<Integer> s = new LinkedHashSet<Integer>();

        for (int x : a)
        {
            s.add(x);
        }
        System.out.println(s);
    }
}
