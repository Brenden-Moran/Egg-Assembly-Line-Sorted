#include <iostream>
#include <vector>
#include <sstream>
#include "factory_utils.h"
using namespace std;

void load_conveyors(std::vector<Conveyor*>& assembly_line){
  string input;

  Conveyor* current_conveyor;                                                         // Creates a conveyor pointer
  Tray* current_tray;                                                                 // Creates a tray pointer
  while(getline(cin,input)){
    if(input[0]=='C'){
      current_conveyor=new Conveyor;
      assembly_line.push_back(current_conveyor);                                      // Puts a new conveyor at the end of the vector
    }
    else if(input[0]=='T'){
      current_tray=new Tray;
      assembly_line.back()->attach_back(current_tray);                                // Puts tray at the end of the last conveyor
    }
    else{
      float eggweight=stof(input);
      current_tray->place_back(Egg(eggweight));                                       // Puts egg in the last tray
    }
  }
}

std::string basic_report(const std::vector<Conveyor*>& assembly_line){
  ostringstream sout;

  for (unsigned int i=0; i<assembly_line.size(); i++){
    sout << *assembly_line.at(i) << "\n\n";

  }
  return sout.str();
}

std::string vertical_report(const std::vector<Conveyor*>& assembly_line){
  ostringstream sout;
  ostringstream fake;
  string str;
  unsigned int i=0;
  unsigned int j=0;
  unsigned int k=0;
  unsigned int check_val=0;
  string longest_str="";
  for (unsigned int x=0; x<assembly_line.size();x++){
    fake.str("");
    fake << *assembly_line[x];
    str = fake.str();
      if (longest_str.size() < str.size()){
        longest_str = str;
    }
    }

  while(i<=assembly_line.size()){

  	fake.str("");
  	fake << *assembly_line[i];
  	str = fake.str();
  	k=j;

  	if ((check_val) >= assembly_line.size()){
  	  break;
	  }  
	  if(i==0){
  	  check_val =0;
	  }
  	if (j>=str.size()){
  	  check_val++;

  	  if ((i+1)==assembly_line.size()){
  	    i=0;
        if (j<longest_str.size())
  	      sout << "       "<< endl;
		    j+=6;
  	  }
  	  else{
        if (j<longest_str.size())
  	  	  sout << "       ";
  	  	j=k;
  	  	i++;
		}
    }
	  else{

	    check_val = 0;
	    while (str[j] != '\n'){

	  	  sout << str[j];
	  	  j++;
	  }
	    if ((i+1)==assembly_line.size()){
	  	  i=0;
	  	  sout << "  " <<endl;
	  	  j++;
	  	
	  }
	    else{
	  	  sout << "  ";
	  	  j=k;
	  	  i++;
	  }	
	}
  	
  	
  	
  }
  return sout.str();
}

std::string horizontal_report(const std::vector<Conveyor*>& assembly_line){
  ostringstream sout;
  ostringstream fake;
  string str;
  unsigned int j=4;
  unsigned int k=0;
  string longest_str="";
  for (unsigned int x=0; x<assembly_line.size();x++){
	fake.str("");
	fake << *assembly_line[x];
	str = fake.str();
	  if (longest_str.size() < str.size()){
		  longest_str = str;
	}
  }

  for(unsigned int i=(assembly_line.size()-1); i<assembly_line.size();i--){

  	fake.str("");
  	fake << *assembly_line[i];
  	str = fake.str();
  	k=j;
  	while(j<=(longest_str.size()+5)){

	    if(j<str.size()){
		    if(str[j]=='\\'){
		      sout << '/';
          j+=6;
		}
		    else if (str[j]=='/'){
		      sout << '\\';
          j+=6;
		}
		    else if (str[j]=='-'){
		      sout << '|';
          j+=6;
		}
		    else if (str[j]=='|'){
		      sout << '-';
          j+=6;
		}
		    else{
		      sout<<str[j];
		      j+=6;
		}
	  }
	    else{
        while (j<(longest_str.size())){
          sout << " ";
          j+=6;
        }
		    sout << endl;
		    if ((k-1)>=0){
          k--;
		      j=k;
		}
	  }
	}
    j=4;

    while (j<=(longest_str.size())){



      sout << " ";
      j+=6;
        }

    sout << endl;
    j=4;
  }
  return sout.str();
}

