#include <iostream>
#include <vector>

template<typename T>
class Stack {
public:
    // Constructor to initialize an empty stack
    Stack() {}

    // Push an element to the top of the stack
    void push(const T& value) {
        vec_.push_back(value);
    }

    // Remove and return the top element of the stack
    T pop() {
        T value = vec_.back();
        vec_.pop_back();
        return value;
    }

    // Return the top element of the stack
    const T& top() const {
        return vec_.back();
    }

    // Check if the stack is empty
    bool empty() const {
        return vec_.empty();
    }

    // Return the number of elements in the stack
    std::size_t size() const {
        return vec_.size();
    }

private:
    std::vector<T> vec_;
};
int main()
{
    Stack<int> myStack;
    myStack.push(10);
    myStack.push(20);
    std::cout<<myStack.pop();


}