public class IntegerOnly<T extends Integer> {
    private T value;

    public IntegerOnly(T value) {
        if (value instanceof Integer) {
            this.value = value;
        } else {
            System.out.println("Type " + value.getClass().getSimpleName() + " is not an Integer. Value discarded.");
        }
    }

    public T getValue() {
        return value;
    }

    public static void main(String[] args) {
        IntegerOnly<Integer> io1 = new IntegerOnly<>(123);
        //IntegerOnly<String> io2 = new IntegerOnly<>("hello");
       // IntegerOnly<Double> io3 = new IntegerOnly<>(3.14);

        System.out.println(io1.getValue()); // prints 123
        //System.out.println(io2.getValue()); // Error
       // System.out.println(io3.getValue()); // Error
    }
}
