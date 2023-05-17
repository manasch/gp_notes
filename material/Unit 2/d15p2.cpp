template<typename T>
class Node;
// Forward friend as regular classes allowed 
// we need definition of template classes
template<typename T>
class Node {};

template<typename T>
class Tree {
  friend class Factory; // OK even if first cldeclaration of Factory
  friend class Node<T>; // error if Node isn't visible
};

class Factory {};

int main() {
  Tree<int> t;
  return 0;
}
