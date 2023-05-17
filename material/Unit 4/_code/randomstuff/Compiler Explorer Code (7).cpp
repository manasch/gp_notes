#include<iostream>
class Foo
{
public:
    constexpr explicit Foo(int i) : _i(i) {}
    constexpr int GetValue() const
    {
        return _i;
    }
private:
    int _i;
};

int main()
{
    constexpr Foo foo(5);
    constexpr int val = foo.GetValue();
    std::cout << "The value of foo is " << foo.GetValue() << std::endl;
}