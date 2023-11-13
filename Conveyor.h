#include <iostream>
using namespace std;
#include "Tray.h"


#ifndef CONVEYOR_H
#define CONVEYOR_H

class Conveyor {
  private:

    struct Harness {
     Tray* tray_head;
     Harness* next;

     Harness(Tray* head, Harness* tail);
     Harness();
     ~Harness();
    
};
    Harness* head;
    Harness* tail;
  public:
    Conveyor();
    ~Conveyor();
    void attach_back(Tray* tray_ptr);
    void attach_front(Tray* tray_ptr);
    void remove(const Tray& trays_to_remove);
    friend ostream& operator<<(ostream& os, Conveyor& lhs);
    Tray* detach_front();
};

#endif
