#define MIN1(a,b) (((a)<(b))?(a):(b))
#define MIN2(a,b) (a<b?a:b)
#include<iostream>
int main()
{ std::cout << MIN2((2+4),(3+1));
  std::cout << MIN1((2+4),(3+1));
    
}
//Which of the MIN produces correct output
//correct output
// MIN1
// MIN2
// neither
// both