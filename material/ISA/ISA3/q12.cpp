#include<iostream>
class Thing {
public:
  struct MemberFunctor {
    int operator() (int x) {return x*x;}   
  } mFunctor;
  static MemberFunctor sFunctor;
};

Thing::MemberFunctor Thing::sFunctor;

int main () {
  Thing thing;
  std::cout << thing.mFunctor(3); 
  std::cout << Thing::sFunctor(3); 
  return 0;
}

