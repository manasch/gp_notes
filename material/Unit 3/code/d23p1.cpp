#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Get the top element and then pop it
    int poppedValue = myStack.top();
    myStack.pop();

    cout << "Popped value: " << poppedValue << endl;
    cout << "Current top value: " << myStack.top() << endl;

    return 0;
}
