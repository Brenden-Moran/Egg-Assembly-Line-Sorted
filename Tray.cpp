#include <iostream>
using namespace std;
#include "Tray.h"

Tray::~Tray(){
  delete [] eggptr;                                       // Deletes all elements in the array eggptr
}



void Tray::place_front(Egg yummers){                      // Takes in egg to add to the tray
	if(capacity==num_eggs){
		capacity+=2;                                          // Checks if the tray needs to be larger
	}
	Egg* new_arr = new Egg[capacity];                       // Creates new egg pointer with the size of the array being the capacity
	new_arr[0] = yummers;                                   // Places the new egg at the front of the new array
	for (int i=0; i<num_eggs; i++){
      	new_arr[i+1] = eggptr[i];                         // Places the other eggs from the old array behind the new egg
    }
  delete [] eggptr;
  eggptr = new_arr;
  num_eggs++;
	 	
}





void Tray::remove(Egg gross){
  int shift_c = 0;
  int eggs_removed = 0;
  for (int i=0; i<num_eggs; i++){
    if (eggptr[i] == gross){                              // Checks to ee if the current egg in array is to be removed
      shift_c++;                                          // If so then the shift of the tray must increment
      eggs_removed++;

  }
  	else{
      for (int j=i; j<num_eggs; j++){                     // If the next egg does not need to be removed then shift the eggptr's value 
        eggptr[j-shift_c] = eggptr[j];                    // To be pointing to the egg that was before the shift (one to be removed)
      }
      shift_c = 0;
    }
  }
  num_eggs = (num_eggs - eggs_removed);

}


void Tray::place_back(Egg yummers){
  if (capacity == num_eggs){
    Egg* new_arr = new Egg[capacity+2];
    for (int i=0; i<capacity; i++){
      new_arr[i] = eggptr[i];
    }
    capacity+=2;
    delete [] eggptr;
    eggptr = new_arr;
  }
  eggptr[num_eggs++]=yummers; 
}

Tray::Tray()
  :eggptr(new Egg[2]), capacity(2), num_eggs(0){};

ostream& operator<<(ostream& os, const Tray& rhs){
  os << "+---+" << endl;
  for (int i=0; i<rhs.capacity;i++){
  	if (i%2==0 && i!=0){
        os << "|" << endl << "|-+-|" << endl;
      }
    if ((i+1)<=rhs.num_eggs){
    	os << "|" << rhs.eggptr[i];
	}
	else{
		os << "| ";
	}
  }
  os << "|" << endl << "+---+" << endl;
  return os;
}


bool operator==(const Tray& lhs, const Tray& rhs){
  if (lhs.num_eggs == rhs.num_eggs){
  	
    Egg error(0);
    int left_c = 0;
    int right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == error){
        ++left_c;
      }
      if (rhs.eggptr[i] == error){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }
    
	Egg peewee(1.25);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == peewee){
        ++left_c;
      }
      if (rhs.eggptr[i] == peewee){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }
    
      
    Egg small(1.5);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == small){
        ++left_c;
      }
      if (rhs.eggptr[i] == small){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }

    Egg medium(1.75);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == medium){
        ++left_c;
      }
      if (rhs.eggptr[i] == medium){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }



 	Egg large(2.0);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == large){
        ++left_c;
      }
      if (rhs.eggptr[i] == large){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }
    

    Egg x_large(2.25);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == x_large){
        ++left_c;
      }
      if (rhs.eggptr[i] == x_large){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }
    

    Egg jumbo(2.5);
    left_c = 0;
    right_c = 0;
    for (int i=0; i<lhs.num_eggs; i++){
      if (lhs.eggptr[i] == jumbo){
        ++left_c;
      }
      if (rhs.eggptr[i] == jumbo){
      	++right_c;
	  }
    }
    if (right_c != left_c){
      return false;
    }
    
    return true;
  }


  else{
    return false;
  }

}
bool Tray::take_back(Egg& e){
  if (num_eggs==0)
    return false;
  else{
    e=eggptr[num_eggs-1];

    num_eggs--;
    return true;
  }
    }
