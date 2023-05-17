import java.util.LinkedList;
import java.util.List;

class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}

public class Mudi {
    public static void main(String[] args) {
        List<Object> myList = new LinkedList<>();
        myList.add(new Integer(0));
        myList.add("Hello, world!");
        myList.add(new Person("Alice"));
        myList.add(new Person("Bob"));

        for (Object obj : myList) {
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
