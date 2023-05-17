#include <iostream>
#include <vector>
#include <list>
#include <type_traits>

template <typename Iter>
void print_iterator_category(Iter iter) {
    using category = typename std::iterator_traits<Iter>::iterator_category;
    if constexpr (std::is_same_v<category, std::input_iterator_tag>) {
        std::cout << "Input iterator" << std::endl;
    } else if constexpr (std::is_same_v<category, std::output_iterator_tag>) {
        std::cout << "Output iterator" << std::endl;
    } else if constexpr (std::is_same_v<category, std::forward_iterator_tag>) {
        std::cout << "Forward iterator" << std::endl;
    } else if constexpr (std::is_same_v<category, std::bidirectional_iterator_tag>) {
        std::cout << "Bidirectional iterator" << std::endl;
    } else if constexpr (std::is_same_v<category, std::random_access_iterator_tag>) {
        std::cout << "Random access iterator" << std::endl;
    } else {
        std::cout << "Unknown iterator category" << std::endl;
    }
}

int main() {
    std::vector<int> v{1, 2, 3};
    std::list<int> l{4, 5, 6};

    auto v_iter = v.begin();
    auto l_iter = l.begin();

    print_iterator_category(v_iter);
    print_iterator_category(l_iter);

    return 0;
}
