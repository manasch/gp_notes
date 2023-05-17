public class TypeErasureWithoutGenerics {
    private Object value;

    public void setValue(Object value) {
        this.value = value;
    }

    public Object getValue() {
        return value;
    }

    public static void main(String[] args) {
        TypeErasureWithoutGenerics stringExample = new TypeErasureWithoutGenerics();
        stringExample.setValue("Hello, world!");
        String stringValue = (String) stringExample.getValue(); // Casting required
        System.out.println(stringValue);

        TypeErasureWithoutGenerics integerExample = new TypeErasureWithoutGenerics();
        integerExample.setValue(42);
        Integer integerValue = (Integer) integerExample.getValue(); // Casting required
        System.out.println(integerValue);
    }
}
