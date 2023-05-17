template<typename Derived>
class Base {
public:
  constexpr void foo() const {
    static_cast<const Derived*>(this)->fooImpl();
  }
};

class DerivedA : public Base<DerivedA> {
public:
  constexpr void fooImpl() const {
    // implementation of foo for DerivedA
  }
};

class DerivedB : public Base<DerivedB> {
public:
  constexpr void fooImpl() const {
    // implementation of foo for DerivedB
  }
};

int main() {
  constexpr DerivedA a;
  constexpr DerivedB b;
  a.foo();
  b.foo();
  return 0;
}
