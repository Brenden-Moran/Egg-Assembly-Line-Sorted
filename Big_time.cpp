#include <iostream>
using namespace std;
#include "Big_time.h"


Big_time::Big_time():capacity(1), egglist(new Egg[1]), num_eggs(0){}

void Big_time::give_egg(Egg g){

  if (capacity == num_eggs){
    capacity = capacity*2;
    Egg* new_arr=new Egg[capacity];
    for (int i=0; i<(capacity/2); i++){
      new_arr[i]=egglist[i];
    }
    new_arr[num_eggs]=g;
    delete [] egglist;
    egglist = new_arr;

  }
  else{
    egglist[num_eggs]=g;
  }
  num_eggs++;

  int node = num_eggs-1;
  while (node >= 0){

      int parent_index = (node-1)/2;

      if (egglist[node] < egglist[parent_index] || egglist[node]==egglist[parent_index]){
        return;
      }
      else{
        Egg move = egglist[node];

        egglist[node]=egglist[parent_index];
        egglist[parent_index]=move;           // Possible to switch out with g
        node = parent_index;
      }
    }



}

bool Big_time::take_egg(Egg& g){
  int node = 0;
  if (num_eggs==0){
    return false;
  }
  else{
    g = egglist[0];
    num_eggs = num_eggs-1;

    egglist[0]=egglist[num_eggs];
    int child_index = 1;

    while (child_index < capacity) {
      Egg value_of_node = egglist[node]; 
      Egg max_value = value_of_node;
      int max_index = -1;
      for (int i=0; (i < 2) && (i+child_index < num_eggs); i++){

        if (max_value < egglist[i+child_index]) {
          max_value = egglist[i + child_index];
          max_index = i+child_index;

        }
      }
      if (max_value == value_of_node) {

        return true;
      }
      else {
        Egg move = egglist[node];
        egglist[node] = egglist[max_index];
        egglist[max_index] = move;

        node = max_index;
        child_index = 2*node+1;
      }
    }
  }

  return true;
}

Big_time::~Big_time(){

  delete [] egglist;
}
