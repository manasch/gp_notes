#include <deque>
#include <stdexcept>
//#define STACK
#ifdef STACK
template<typename T>
class Stack {
public:
  void push(const T& value) {
    data_.push_back(value);
  }
  
  void pop() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    data_.pop_back();
  }
  
  T& top() {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return data_.back();
  }
  
  const T& top() const {
    if (empty()) {
      throw std::out_of_range("Stack is empty");
    }
    return data_.back();
  }
  
  bool empty() const {
    return data_.empty();
  }
  
  std::size_t size() const {
    return data_.size();
  }
  
private:
  std::deque<T> data_;
};
#include <iostream>

int main() {
  Stack<int> my_stack;
  
  my_stack.push(1);
  my_stack.push(2);
  my_stack.push(3);
  
  while (!my_stack.empty()) {
    std::cout << my_stack.top() << ' ';
    my_stack.pop();
  }
  std::cout << '\n';
  
  return 0;
}
#endif
#define QUEUE
#ifdef QUEUE
#include <deque>
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue {
public:
  void push(const T& value) {
    data_.push_back(value);
  }
  
  void pop() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    data_.pop_front();
  }
  
  T& front() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_.front();
  }
  
  const T& front() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_.front();
  }
  
  T& back() {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_.back();
  }
  
  const T& back() const {
    if (empty()) {
      throw std::out_of_range("Queue is empty");
    }
    return data_.back();
  }
  
  bool empty() const {
    return data_.empty();
  }
  
  std::size_t size() const {
    return data_.size();
  }
  
private:
  std::deque<T> data_;
};

int main() {
  Queue<int> my_queue;
  
  my_queue.push(1);
  my_queue.push(2);
  my_queue.push(3);
  
  while (!my_queue.empty()) {
    std::cout << my_queue.front() << ' ';
    my_queue.pop();
  }
  std::cout << '\n';
  
  return 0;
}

#endif