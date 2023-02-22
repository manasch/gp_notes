
##### Some copy funny business
```c++
#include <iostream>
using namespace std;

class C {
    public:
        int x, *y;
        C(int a) : x(a){
            y = &x;
        }
        C(const C &c1) {
            y = c1.y;       //shallow
            x = c1.x;       //idk why it's not shallow
        }
};

int main() {
    C c1(5);
    cout << "c1.y=" << *c1.y  << endl;
    // c1.x = 1;
    // cout << c1.x  << endl;
    C c2(c1);
    c1.x = 2;
    cout << "c1.y=" << *c1.y  << endl;
    cout << "c2.y=" << *c2.y  << endl;
    return 0;
}
```
---
##### Not sure why we did this
```c++
#include <iostream>
using namespace std;

template <typename T1>
class Engine{
    public:
        void start() {
            cout << "Engine started" << endl;
        }
        ~Engine() {
            cout << "Engine dead";
        }
    
};

template <typename T1, typename T2>
class Car {
    private:
        Engine<T1> engine;
    public:
        void start() {
            engine.start();
            cout << "Car started" << endl;
        }
        ~Car() {
            cout << "Car dead" << endl;    //called before engine destructor, kss not sure why
        }
};

int main() {
    Car<int, double> c1;
    c1.start();

    return 0;
}
```
---
##### Some templatization
```c++
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
class MyString {
    private:
        vector<T> m_data;
    public:
        MyString() {} //empty contructor
        void assign(const T *str) {
            m_data.clear();
            m_data.insert(m_data.end(), str, str + strlen(str));
            m_data.push_back('\0');
        }

        const T *c_str() const {
            return &m_data[0];
        }
};


int main() {
    MyString<char> s1;
    s1.assign("sample");
    cout << s1.c_str();
    return 0;
}
```
---
##### Need for explicit destruction
```c++
#include <iostream>
#include <vector>
// Here is an example of what happens if we dont 
// explcitily destroy children
 
class Person {
public:
    Person(const std::string& name) : name(name) {}
    ~Person() {
        std::cout << name << " died." << std::endl;
    }
    std::string name;
};
 
class House {
public:
    House(const std::string& address) : address(address) {}
    ~House() {
        std::cout << "House at " << address << " was destroyed." << std::endl;
    }
    std::string address;
};
 
class Town {
public:
    Town() {
        std::cout << "Town was created." << std::endl;
    }
    ~Town() {
        std::cout << "Town was destroyed." << std::endl;
    }
    void add_person(Person* person) {
        people.push_back(person);
    }
    void add_house(House* house) {
        houses.push_back(house);
    }
private:
    std::vector<Person*> people;
    std::vector<House*> houses;
};
 
int main() {
    std::cout << "Entering main." << std::endl;
    Town* town = new Town();
    town->add_person(new Person("John"));         //new initializes to heap
    town->add_house(new House("123 Main St."));
    delete town;
    std::cout << "Leaving main." << std::endl;
    return 0;
}
```
---
