#include <vector>
#include <string>
#include <iostream>
#include<cstring>

template<typename Whole, typename Part>
class MyString {
private:
    std::vector<Part> m_data;

public:
    MyString() {}

    void assign(const Whole *str, size_t size) {
        m_data.clear();
        m_data.insert(m_data.end(), str, str + size);
        m_data.push_back('\0');
    }

    const Part *data() const {
        return m_data.data();
    }
};

int main() {
    MyString<wchar_t, char> my_string;

    std::wcout << "Before assignment: " << (my_string.data() == nullptr ? L"nullptr" : L"not nullptr") << std::endl;

    const wchar_t *str = L"Hello, World!";
    my_string.assign(str, wcslen(str));

    std::wcout << "After assignment: " << my_string.data() << std::endl;

    return 0;
}
