#include <iostream>
#include <vector>
#include <algorithm>
class IsGreaterThan {
public:
    IsGreaterThan(int threshold) : m_threshold(threshold) {}

    bool operator()(int value) const {
        return value > m_threshold;
    }

private:
    int m_threshold;
};

int main() {
    std::vector<int> values{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int threshold = 5;

    auto it = std::find_if(values.begin(), values.end(), IsGreaterThan(threshold));

    if (it != values.end()) {
        std::cout << "First value greater than " << threshold << " is " << *it << std::endl;
    } else {
        std::cout << "No value greater than " << threshold << std::endl;
    }

    return 0;
}
