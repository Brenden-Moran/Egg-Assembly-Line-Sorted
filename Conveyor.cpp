#include <iostream>
using namespace std;
#include "Conveyor.h"
Conveyor::Harness::Harness(Tray* head, Harness* tail): tray_head(head), next(tail){}

Conveyor::Harness::~Harness(){
  delete tray_head;
}

void Conveyor::remove(const Tray& tray_to_remove){
  Harness fake_start(nullptr, head);
  Harness* new_ptr = &fake_start;
  int i = 0;
  int num_of_rotations = 1;

  while(new_ptr->next!=nullptr){
    i++;

    if(*new_ptr->next->tray_head == tray_to_remove){
      num_of_rotations++;
      Harness* to_delete=(new_ptr->next);
      (new_ptr->next) = (new_ptr->next->next);
      delete to_delete;
    }
    else{
      if (i==num_of_rotations){

        head = new_ptr->next;

      }
      new_ptr=new_ptr->next;
    }
  }
  if(new_ptr==&fake_start){

    head=tail=nullptr;
  }
  else{
    tail=new_ptr;

  }

}



Conveyor::Conveyor():head(nullptr), tail(nullptr){}

Conveyor::~Conveyor(){

  while(head){
    Harness* to_be_deleted = head;
    head=head->next;
    delete to_be_deleted;
  }

   }



void Conveyor::attach_back(Tray* tray_ptr){

  if(head==nullptr){                                                                    // If head is empty then the linked list is empty
    head = new Harness(tray_ptr, head);                                                 // have the head and tail pointers point to the same thing
    tail = head;
  }
  else{
    Harness* old_tail = tail;                                                           // Otherwise have tail point to the new harness
    tail = new Harness(tray_ptr, nullptr);                                              // and have the old tail's next value be the new tail
    old_tail ->next=tail;
  }
}

void Conveyor::attach_front(Tray* tray_ptr){

  if(head==nullptr){                                                                    // If head is empty then the linked list is empty
    head = new Harness(tray_ptr, head);                                                 // have the head and tail pointers point to the same thing
    tail = head;
  }
  else{                                                                                 // Otherwise have the new head value be the new harness and have 
    head = new Harness(tray_ptr, head);                                                 // it point to the old head value
  }
}

ostream& operator<<(ostream& os, Conveyor& lhs){
  lhs.tail = lhs.head;
  os << "  |  " << endl;
  while(lhs.tail){ 
    os << " / \\ " << endl << "/   \\" << endl;
    os << *lhs.tail->tray_head; 
 
    if (lhs.tail->next == nullptr){
      os << "\\   /" << endl << " \\ / " << endl << "  S  " << endl;
      break;
    }
    else{
      os << "\\   /" << endl << " \\ / " << endl << "  $  " << endl;
      lhs.tail=lhs.tail->next;
    }
 
  }
  return os;
}
Tray* Conveyor::detach_front(){
  if (head==nullptr)
    return nullptr;
  else{
    Tray* head_tray=head->tray_head;
    head->tray_head=nullptr;
    Harness* new_head=head->next;
    delete head;
    head=new_head;
    return head_tray;
  }
}
