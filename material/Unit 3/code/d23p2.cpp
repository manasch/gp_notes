#include <iostream>

template <typename T>
class Stack {
public:
    Stack() : m_top(nullptr), m_size(0) {}

    bool empty() const {
        return m_size == 0;
    }

    size_t size() const {
        return m_size;
    }

    const T& top() const {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        return m_top->value;
    }

    void push(const T& value) {
        Node* newNode = new Node{value, m_top};
        m_top = newNode;
        ++m_size;
    }

    T pop() {
        if (empty()) {
            throw std::runtime_error("Stack is empty");
        }
        T poppedValue = m_top->value;
        Node* poppedNode = m_top;
        m_top = m_top->next;
        --m_size;
        delete poppedNode;
        return poppedValue;
    }

private:
    struct Node {
        T value;
        Node* next;
    };

    Node* m_top;
    size_t m_size;
};
int main()
{
Stack<int> myStack;
myStack.push(10);
const int& poppedValue = myStack.pop();
std::cout << poppedValue;
//! int pauper = myStack.pop(); Constructor call
}