template <typename T, int N>
class Array{
 public:
    int getSize() const{
        return N;
    }
 private:
    T elem[N];
};

int main() {
    int x{5};
    const int y{5};
    Array<int, 5> myArr1;  // (1)
    Array<int, 10> myArr2; // (2)
    Array<int, 5> myArr3;  // (3)
    //Array<int, x> myArr4;  // (4)
    Array<int,y > myArry5;  // (5)
  
}
