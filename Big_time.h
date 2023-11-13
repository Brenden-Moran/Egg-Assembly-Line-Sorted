#include <iostream>
#include "Egg.h"
#include "Tray.h"
#include "Conveyor.h"
#ifndef BIG_TIME_H
#define BIG_TIME_H
using namespace std;

class Big_time {
  private:
    int capacity;
    Egg* egglist;
    int num_eggs;
  public:
    Big_time();
    ~Big_time();
    void give_egg(Egg g);
    bool take_egg(Egg& g);
};
#endif
