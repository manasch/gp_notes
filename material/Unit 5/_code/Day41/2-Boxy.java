public class Box<T> {
    private T item;

    public void setItem(T item) {
        this.item = item;
    }

    public T getItem() {
        return item;
    }
}
// When we write a box template class like this it COMPILES to something like this
// Illustrative purposes only
public class Box_Object {
    private Object item;

    public void setItem(Object item) {
        this.item = item;
    }

    public Object getItem() {
        return item;
    }
}
// Now lets say we do this 
Box<Integer> intBox = new Box<>();
Box<Character> charBox = new Box<>();
// No new classes are defined or compiles - NOT LIKE C++
// Instead it uses the compiles class Box_Object to generate BYTE code directly 
// for a set of classes that could  something like this
// Generic class definition
// Creating Box<Integer> object
Box<Integer> intBox = new Box<Integer>();
// Compiler generates bytecode for Box<Integer> methods
// resulting in something like this:
class Box_Integer {
    private Integer item;

    public void setItem(Integer item) {
        this.item = item;
    }

    public Integer getItem() {
        return item;
    }
}

// Creating Box<Character> object
Box<Character> charBox = new Box<Character>();
// Compiler generates bytecode for Box<Character> methods
// resulting in something like this:
class Box_Character {
    private Character item;

    public void setItem(Character item) {
        this.item = item;
    }

    public Character getItem() {
        return item;
    }
}


