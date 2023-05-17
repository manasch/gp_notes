#include<iostream>
template<typename T, typename = void>
struct has_data_member : std::false_type {};

template<typename T>
struct has_data_member<T, std::void_t<decltype(std::declval<T>().data)>> : std::true_type {};

struct Foo {
    int data;
};

struct Bar {};

int main() {
    bool foo_has_data = has_data_member<Foo>::value;
    bool bar_has_data = has_data_member<Bar>::value;
    std::cout << std::boolalpha << foo_has_data << ", " << bar_has_data << std::endl;
}
