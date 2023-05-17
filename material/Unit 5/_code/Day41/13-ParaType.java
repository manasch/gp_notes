class Pair<T, U> {
    private T first;
    private U second;

    public Pair(T first, U second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public U getSecond() {
        return second;
    }
}

class Utils {
    public static <T, U> Pair<U, T> swap(Pair<T, U> pair) {
        return new Pair<U, T>(pair.getSecond(), pair.getFirst());
    }
}

public class ParaType {
    public static void main(String[] args) {
        Pair<Integer, String> pair1 = new Pair<>(1, "one");
        System.out.println("Pair 1: " + pair1.getFirst() + ", " + pair1.getSecond());

        Pair<String, Integer> pair2 = Utils.swap(pair1);
        System.out.println("Pair 2 (after swap): " + pair2.getFirst() + ", " + pair2.getSecond());
    }
}
