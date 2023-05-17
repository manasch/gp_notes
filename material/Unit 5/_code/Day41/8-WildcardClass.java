public class WildcardClass<T> {
    private T value;

    public WildcardClass(T value) {
        this.value = value;
    }

    public T getValue() {
        return value;
    }

    public static void main(String[] args) {
        WildcardClass<?> wc1 = new WildcardClass<>("Hello");
        WildcardClass<?> wc2 = new WildcardClass<>(123);
        System.out.println(wc1.getValue());
        System.out.println(wc2.getValue());

        // Add an int to the wildcard class
        WildcardClass<?> wc3 = new WildcardClass<>(45);
        System.out.println(wc3.getValue());

        // Add a double to the wildcard class
        WildcardClass<?> wc4 = new WildcardClass<>(3.14);
        System.out.println(wc4.getValue());
    }
}

