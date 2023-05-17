 class GenericVector<T> {
    private Object[] elements;
    private int size;

    public GenericVector(int capacity) {
        elements = new Object[capacity];
        size = 0;
    }

    public void add(T element) {
        if (size == elements.length) {
            grow();
        }
        elements[size] = element;
        size++;
    }

    @SuppressWarnings("unchecked")
    public T get(int index) {
        return (T) elements[index];
    }

    public int size() {
        return size;
    }

    private void grow() {
        Object[] newElements = new Object[elements.length * 2];
        System.arraycopy(elements, 0, newElements, 0, elements.length);
        elements = newElements;
    }
}
public class GenericVectorExample {
    public static void main(String[] args) {
        GenericVector<String> stringVector = new GenericVector<>(2);
        stringVector.add("Hello");
        stringVector.add("World");
        System.out.println("String vector size: " + stringVector.size());
        System.out.println("First element: " + stringVector.get(0));
        System.out.println("Second element: " + stringVector.get(1));

        GenericVector<Integer> intVector = new GenericVector<>(2);
        intVector.add(42);
        intVector.add(1337);
        System.out.println("Integer vector size: " + intVector.size());
        System.out.println("First element: " + intVector.get(0));
        System.out.println("Second element: " + intVector.get(1));
    }
}
