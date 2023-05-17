class Person implements Cloneable {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    @Override
    public String toString() {
        return "Person[name=" + name + ", age=" + age + "]";
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) {
            return true;
        }
        if (obj == null || getClass() != obj.getClass()) {
            return false;
        }
        Person other = (Person) obj;
        return age == other.age && name.equals(other.name);
    }

    @Override
    public int hashCode() {
        int result = name.hashCode();
        result = 31 * result + age;
        return result;
    }

    @Override
    protected Person clone() throws CloneNotSupportedException {
        return (Person) super.clone();
    }
}

public class ObjExample {
    public static void main(String[] args) {
        Person person1 = new Person("Alice", 30);
        Person person2 = new Person("Alice", 30);

        // Using toString()
        System.out.println("person1: " + person1);

        // Using equals()
        System.out.println("person1 equals person2: " + person1.equals(person2));

        // Using hashCode()
        System.out.println("person1 hashCode: " + person1.hashCode());
        System.out.println("person2 hashCode: " + person2.hashCode());

        // Using getClass()
        System.out.println("person1 class: " + person1.getClass());

        // Using clone()
        try {
            Person person3 = person1.clone();
            System.out.println("person3 (cloned from person1): " + person3);
            System.out.println("person1 equals person3: " + person1.equals(person3));
        } catch (CloneNotSupportedException e) {
            e.printStackTrace();
        }
    }
}
