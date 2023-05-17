public class HelloWorld<T> {
    private T message;

    public HelloWorld(T message) {
        this.message = message;
    }

    public T getMessage() {
        return message;
    }

    public void setMessage(T message) {
        this.message = message;
    }

    public void printMessage() {
        System.out.println(message);
    }

    public static void main(String[] args) {
        HelloWorld<String> helloString = new HelloWorld<String>("Hello, world!");
        HelloWorld<Integer> helloInteger = new HelloWorld<Integer>(42);

        helloString.printMessage(); // prints "Hello, world!"
        helloInteger.printMessage(); // prints "42"

        helloString.setMessage("Goodbye, world!");
        helloInteger.setMessage(84);

        helloString.printMessage(); // prints "Goodbye, world!"
        helloInteger.printMessage(); // prints "84"
    }
}
