public class IntegerUtilityMethods {
    public static void main(String[] args) {
        // Parsing an integer from a string
        String numberString = "42";
        int parsedInt = Integer.parseInt(numberString);
        System.out.println("Parsed int: " + parsedInt);

        // Converting an integer to a binary string
        int number = 10;
        String binaryString = Integer.toBinaryString(number);
        System.out.println("Binary representation: " + binaryString);

        // Comparing two integers
        int a = 5;
        int b = 10;
        int comparisonResult = Integer.compare(a, b);
        System.out.println("Comparison result: " + comparisonResult);

        // Finding the maximum and minimum values of an integer
        int maxInt = Integer.MAX_VALUE;
        int minInt = Integer.MIN_VALUE;
        System.out.println("Max int: " + maxInt);
        System.out.println("Min int: " + minInt);
    }
}
