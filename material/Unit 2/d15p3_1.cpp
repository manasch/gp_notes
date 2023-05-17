#include <iostream>
using namespace std;

template<typename T>
class Tree;

template<typename T>
class Node {
  private:
    T data;
  public:
    Node(T data) : data(data) {}
    void printTreeData(Tree<T> &tree) {
        cout << "Tree data: " << tree.data << endl;
    }
};

template<typename T>
class Tree {
  private:
    T data;
  public:
    Tree(T data) : data(data) {}
    friend class Node<T>;
    friend class Factory;
};

class Factory {};

int main() {
  Node<int> n(10);
  Tree<int> t(20);
  n.printTreeData(t);
  return 0;
}
