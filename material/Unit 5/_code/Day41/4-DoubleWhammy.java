import java.util.LinkedList;
import java.util.List;
import java.util.Iterator;

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class DoubleWhammy {
    public static void main(String[] args) {
        List myList = new LinkedList();
        myList.add(new Integer(0));
        myList.add("Hello, world!");
        myList.add(new Person("Alice"));
        myList.add(new Person("Bob"));

        Iterator iter = myList.iterator();
        while (iter.hasNext()) {
            Object obj = iter.next();
            if (obj instanceof Integer) {
                Integer x = (Integer) obj;
                System.out.println(x);
            } else if (obj instanceof String) {
                String s = (String) obj;
                System.out.println(s);
            } else if (obj instanceof Person) {
                Person p = (Person) obj;
                System.out.println(p.getName());
            }
        }
    }
}
