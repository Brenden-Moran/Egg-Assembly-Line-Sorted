#include <iostream>
using namespace std;
#include "Egg.h"

Egg::Egg(float egg_weight){
  weight = egg_weight;
 
};
Egg::Egg(){
  weight = 0;
}

ostream& operator<<(ostream& os, const Egg& rhs){ 
  if (rhs.weight < 1.25 ){
    os << "E";
  }
  else if (rhs.weight < 1.5){
    os << ".";
  }
  else if (rhs.weight < 1.75){
    os << "*";
  }
  else if (rhs.weight < 2.0){
    os << "o";
  }
  else if (rhs.weight < 2.25){
    os << "O";
  }
  else if (rhs.weight < 2.5){
    os << "0";
  }
  else{
    os << "@";
  }
  return os;
}

bool operator==(const Egg& lhs, const Egg& rhs){
  if ((lhs.weight < 1.25) && (rhs.weight < 1.25)){
    return true;
  }
  else if ((lhs.weight >= 1.25 && lhs.weight < 1.5) && (rhs.weight >= 1.25 && rhs.weight < 1.5)){
      return true;
      }
  else if ((lhs.weight >= 1.5 && lhs.weight < 1.75) && (rhs.weight >= 1.5 && rhs.weight < 1.75)){
      return true;
      }
  else if ((lhs.weight >= 1.75 && lhs.weight < 2.0) && (rhs.weight >= 1.75 && rhs.weight < 2.0)){
      return true;
      }
  else if ((lhs.weight >= 2.0 && lhs.weight < 2.25) && (rhs.weight >= 2.0 && rhs.weight < 2.25)){
      return true;
      }
  else if ((lhs.weight >= 2.25 && lhs.weight < 2.5) && (rhs.weight >= 2.25 && rhs.weight < 2.5)){
      return true;
      }
  else if ((lhs.weight >= 2.5) && (rhs.weight >= 2.5)){
      return true;
      }
  else {
    return false;
    }
}
bool operator<(const Egg& lhs, const Egg& rhs){
  if (lhs.weight<rhs.weight)
    return true;
  else
    return false;
}
