#include<iostream>
struct knight
{
   void step_forth()
   {
      std::cout << "knight moves forward\n";
   }
   void step_back()
   {
      std::cout << "knight moves back\n";
   }
};
struct mage
{
   void step_forth()
   {
      std::cout << "mage moves forward\n";
   }
   void step_back()
   {
      std::cout << "mage moves back\n";
   }
};
template <typename T>
struct movable_unit : T
{
   void advance(size_t steps)
   {
      while (steps--)
         T::step_forth();
   }
   void retreat(size_t steps)
   {
      while (steps--)
         T::step_back();
   }
};
int main()
{
movable_unit<knight> k;
k.advance(3);
k.retreat(2);
movable_unit<mage> m;
m.advance(5);
m.retreat(3);
}
