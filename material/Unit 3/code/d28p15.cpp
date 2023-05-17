#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class Object {
public:
    Object(int id) : m_id(id) {}

    int getID() const {
        return m_id;
    }

private:
    int m_id;
};

int main() {
    std::vector<Object> objects(5, Object(0));

    std::vector<int> ids(objects.size());
    std::iota(ids.begin(), ids.end(), 1);

    std::transform(ids.begin(), ids.end(), objects.begin(), [](int id) {
        return Object(id);
    });

    std::cout << "Object IDs: ";
    std::for_each(objects.begin(), objects.end(), [](const Object& obj) {
        std::cout << obj.getID() << " ";
    });

    return 0;
}
