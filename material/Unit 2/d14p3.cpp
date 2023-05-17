#include <vector>
#include <string>
#include <iostream>
#include<cstring>

class MyString {
private:
    std::vector<char> m_data;

public:
    // Constructor does not do anything
    MyString() {}
    // Specific add to m_data
    void assign(const char *str) {
        m_data.clear();
        m_data.insert(m_data.end(), str, str + strlen(str));
        m_data.push_back('\0');
    }

    const char *c_str() const {
        return &m_data[0];
    }
};

int main() {
    MyString my_string;

    std::cout << "Before assignment: " << (my_string.c_str() == nullptr ? "nullptr" : "not nullptr") << std::endl;

    my_string.assign("Hello, World!");

    std::cout << "After assignment:Cstr() " << my_string.c_str() <<"vector"<< std::endl;

    return 0;
}
