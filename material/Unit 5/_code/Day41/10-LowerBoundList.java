import java.util.ArrayList;
import java.util.List;

public class LowerBoundList<T extends Number> {
    private List<? super T> numbers;

    public LowerBoundList() {
        this.numbers = new ArrayList<>();
    }

    public boolean addNumber(T number) {
        return numbers.add(number);
    }

    public List<? super T> getNumbers() {
        return numbers;
    }

    public static void main(String[] args) {
        LowerBoundList<Integer> integerList = new LowerBoundList<>();
        integerList.addNumber(3);
        integerList.addNumber(7);
        integerList.addNumber(10);
        System.out.println("Integer List: " + integerList.getNumbers()); // Output: Integer List: [3, 7, 10]

        LowerBoundList<Double> doubleList = new LowerBoundList<>();
        doubleList.addNumber(5.0);
        doubleList.addNumber(15.5);
        doubleList.addNumber(20.0);
        System.out.println("Double List: " + doubleList.getNumbers()); // Output: Double List: [5.0, 15.5, 20.0]
    }
}
