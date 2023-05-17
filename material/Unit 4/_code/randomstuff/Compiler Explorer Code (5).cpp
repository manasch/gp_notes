struct X {
   // constexpr ~X() {}
    constexpr ~X() = default;
};
int main()
{
    X x;
}