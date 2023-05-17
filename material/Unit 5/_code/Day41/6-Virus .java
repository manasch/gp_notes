import java.util.LinkedList;
import java.util.List;

public class Virus {
    public static void main(String[] args) {
        List myIntList = new LinkedList(); // 1
        myIntList.add(new Integer(0)); // 2
        myIntList.add("0"); // 3 ok horn please - IncompatibleClassChangeError
        Integer x = (Integer) myIntList.iterator().next(); // 4

        System.out.println(x);
    }
}
