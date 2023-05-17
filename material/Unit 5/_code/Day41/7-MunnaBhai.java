import java.util.LinkedList;
import java.util.List;

public class MunnaBhai {
    public static void main(String[] args) {
        List<Integer> myIntList = new LinkedList<Integer>(); // 1'
        // Now type checking at compile time
        myIntList.add(21); // 2'
       // myIntList.add("0"); Will create an error
        Integer x = myIntList.iterator().next(); // 3'

        System.out.println(x);
    }
}
