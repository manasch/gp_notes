// * Non-dependent types are those that are 
// *not dependent on a template parameter.
// ?The type of the member variable data is int, 
// ?which is not dependent on the template parameter T.
// !It's worth noting that non-dependent types are known 
// ! todo at compile-time and can be used in more contexts 
// ! todo than dependent types, which are only known at 
// ! todo instantiation time.
template<typename T>
class MyClass {
  int data;// ! Non dependent 
          // ! - known at compile time
public:
  MyClass(int data) : data(data) {}
};
int main()
{
    
    return 0;
}