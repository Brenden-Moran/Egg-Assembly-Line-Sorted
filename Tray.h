#include <iostream>
using namespace std;
#include "Egg.h"
#ifndef TRAY_H
#define TRAY_H

class Tray {
  private:
    Egg* eggptr;
    int capacity;
    int num_eggs;

   public:
    void place_back(Egg yummers);
    void place_front(Egg yummers);
    void remove(Egg gross);
    Tray();
    ~Tray();
    friend ostream& operator<<(ostream& os, const Tray& rhs);
    friend bool operator==(const Tray& lhs, const Tray& rhs);
    bool take_back(Egg& e);
};
#endif
