#include <iostream>
#include <stdexcept>
#include <concepts>
template <typename T>
concept Copyable = std::is_copy_constructible_v<T> && std::is_copy_assignable_v<T>;

template <typename T>
class MyStack {
public:
    MyStack(int maxSize);
    ~MyStack();
    void push(const T& item);
    T pop();
private:
    T* data;
    int top;
    const int MAX_SIZE;
};

template <typename T>
MyStack<T>::MyStack(int maxSize) : MAX_SIZE(maxSize) {
    data = new T[MAX_SIZE];
    top = -1;
}

template <typename T>
MyStack<T>::~MyStack() {
    delete[] data;
}

template <typename T>
void MyStack<T>::push(const T& item) {
    if (top == MAX_SIZE - 1) {
        throw std::runtime_error("Stack overflow");
    }
    data[++top] = item;
}

template <typename T>
T MyStack<T>::pop() {
    if (top == -1) {
        throw std::runtime_error("Stack underflow");
    }
    return data[top--];
}

class NonCopyable {
public:
    NonCopyable() {}
    ~NonCopyable() {}
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

int main() {
    // Create a MyStack of int
    MyStack<int> intStack(5);
    intStack.push(1);
    intStack.push(2);
    std::cout << intStack.pop() << std::endl;
    std::cout << intStack.pop() << std::endl;

    // Create a MyStack of NonCopyable
    //MyStack<NonCopyable> ncStack(5);
    //ncStack.push(NonCopyable());
    //ncStack.push(NonCopyable());
    //ncStack.pop();
    //ncStack.pop();
    return 0;
}