#include <iostream>
#include "Big_time.h"
#include "factory_utils.h"
#include <vector>
using namespace std;

int main(){
  vector<Conveyor*> assembly_line;
  load_conveyors(assembly_line);

  vector<Conveyor*> ordered_line;

  Big_time biggie;
  Egg e;



  for (unsigned int i=0; i < assembly_line.size(); i++){
    Conveyor* current_conveyor = new Conveyor;
    Tray* current_tray = assembly_line.at(i)->detach_front();
    while(current_tray){



      while (current_tray->take_back(e)){


        biggie.give_egg(e);

      }
      
      Egg current_egg;
      while(biggie.take_egg(current_egg)){
        current_tray->place_back(current_egg);


    }
      current_conveyor->attach_back(current_tray);
      current_tray = assembly_line.at(i)->detach_front();
      }
      ordered_line.push_back(current_conveyor);
    
  }
  string report = vertical_report(ordered_line);
  
  cout << "Ordered vertical report:\n" << report;

}

