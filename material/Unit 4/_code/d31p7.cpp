#include <iostream>
#include <type_traits>

template<typename T>
struct is_pointer{
    static constexpr bool value = false;
};

template<typename T>
struct is_pointer<T*>{
    static constexpr bool value = true;
};

template<typename T>
struct strip_pointer{
    using type = T;
};

template<typename T>
struct strip_pointer<T*>{
    using type = T;
};

template<typename T>
void print1(T t){
    using T_without_pointer = strip_pointer<T>::type;
    if constexpr(is_pointer<T>::value && std::is_floating_point<T_without_pointer>::value){
        std::cout << *t;
    }
    else{
        std::cout << t;
    }
}

template<typename A, typename B, typename C>
void print3(A a, B b, C c) {
  print1(a);
  std::cout << ", ";
  print1(b);
  std::cout << ", ";
  print1(c);
  std::cout << '\n';
}

int main() {
  print3(1, 2, 3);
  std::string hello = "hello world";
  print3(hello, 2, hello);
  print3(&hello, 2, 3);
  float a=10;
  double b= 2;
  print3(&hello, &a, &b);
}