#include<iostream>
class A {  
    private:
     int x;
     friend class B;
    public:
     void setty() { x = 10;}

};
class B {
    public:
    void static print(const A &a)
    {
        std::cout << "X" << a.x;
    }
    private:
    friend class c;
};
// class C{
//     public:
//     void static print(const A &a)
//     {
//         std::cout << "X" << a.x;
//     }

// };
int main()
{
    A a;
    a.setty();
    B::print(a);
    // C::print(a);
}
