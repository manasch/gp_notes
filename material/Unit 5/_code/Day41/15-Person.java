public class Person {
    private String name;

    public Person(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public static void main(String[] args) {
        MyGenericClass<String> stringObj = new MyGenericClass<>("Hello");
        MyGenericClass<Integer> integerObj = new MyGenericClass<>(123);
        // MyGenericClass<Person> personObj = new MyGenericClass<>(new Person("John Doe"));

        System.out.println(stringObj.getValue()); // prints "Hello"
        System.out.println(integerObj.getValue()); // prints 123
        //System.out.println(personObj.getValue().getName()); // prints "John Doe"
    }
}

class MyGenericClass<T extends Object & Comparable<T>> {
    private T value;

    public MyGenericClass(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }
}
