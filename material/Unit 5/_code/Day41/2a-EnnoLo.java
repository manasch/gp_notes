import java.util.ArrayList;
import java.util.List;

public class EnnoLo {
    public static void main(String[] args) {
        List<String> ls = new ArrayList<String>(); // 1
        List<Object> lo = ls; 

        lo.add(new Object()); // attempt to add an Object to a List<String>

        String s = ls.get(0); // Attempts to assign an Object to a String!

        System.out.println(s);
    }
}
// In general, if Foo is a subtype (subclass or subinterface) of Bar, and G is some generic type declaration,
// it is NOT THE CASE that G<Foo> is a subtype of G<Bar>. 
// This is probably the hardest thing you need to learn about generics, 
// because it goes against our deeply held intuitions.
