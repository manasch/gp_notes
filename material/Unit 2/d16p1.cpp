// A nested class is a class defined inside 
// another class. The inner class is also called a nested
// class or a member class. 
// Here's a simple example to 
// illustrate the concept of nested classes in C++:
class OuterClass {
public:
    int outerValue;

    class InnerClass {
    public:
        int innerValue;
    };

    InnerClass innerObject;
};

int main() {
    OuterClass outerObject;
    outerObject.outerValue = 10;
    outerObject.innerObject.innerValue = 20;
    return 0;
}
