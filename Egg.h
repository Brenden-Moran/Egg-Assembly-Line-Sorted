#include <iostream>
#ifndef EGG_H
#define EGG_H
using namespace std;

 class Egg {
   private:
     float weight;
   public:
     friend ostream& operator<<(ostream& os, const Egg& rhs);
     friend bool operator==(const Egg& lhs, const Egg& rhs);
     Egg(float egg_weight);
     Egg();
     friend bool operator<(const Egg& lhs, const Egg& rhs);
 };
#endif

