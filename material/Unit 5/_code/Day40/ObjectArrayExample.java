public class ObjectArrayExample {

    public static void main(String[] args) {
        // Create an array of Object with a length of 4
        Object[] objArray = new Object[4];

        // Add different types of objects to the array
        objArray[0] = "Hello";
        objArray[1] = 42;
        objArray[2] = new Person("Alice", 30);
        objArray[3] = new int[]{1, 2, 3};

        // Iterate over the elements and print their class names
        for (Object obj : objArray) {
            System.out.println("Object: " + obj + ", Class: " + obj.getClass().getSimpleName());
        }
    }

    static class Person {
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
    }
}
