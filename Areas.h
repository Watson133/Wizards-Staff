#ifndef AREAS_H
#define AREAS_H

#include <iostream>
#include <string>
#include "OneWayAreas.h"

using namespace std;

class Area : public One_Way_Area{

protected:
bool can_move_left_p;//can you move left from your current area, yes or no
bool can_move_right_p;
bool can_move_forward_p;
bool can_move_back_p;
bool have_been_here_p;//have you been in this area before, yes or no
string already_been_area_script_p;//smaller description of the area will print if you have already been there

public:

Area(){
  area_name_p = " ";
  can_move_left_p = false;
  can_move_right_p = false;
  can_move_forward_p = false;
  can_move_back_p = false;
  have_been_here_p = false;
  area_script_p = " ";
  already_been_area_script_p = " ";
}

Area(string area_name, bool can_move_left, bool can_move_right, bool can_move_forward, bool can_move_back, string area_script, string already_been_area_script){
  area_name_p = area_name;
  can_move_left_p = can_move_left;
  can_move_right_p = can_move_right;
  can_move_forward_p = can_move_forward;
  can_move_back_p = can_move_back;
  area_script_p = area_script;
  already_been_area_script_p = already_been_area_script;

}

  string get_area_name(){
    return area_name_p;
  }

  bool get_move_left(){
    return can_move_left_p;
  }

  bool get_move_right(){
    return can_move_right_p;
  }

  bool get_move_forward(){
    return can_move_forward_p;
  }

  bool get_move_back(){
    return can_move_back_p;
  }

  bool get_have_been_here(){
    return have_been_here_p;
  }

  string get_area_script_p(){
   return area_script_p;
  }

  string get_already_been_area_script_p(){
    return already_been_area_script_p;
  }

  void set_have_been_here_p(){
    have_been_here_p = true;
  } 

  friend ostream& operator<<(ostream& os, const Area& a)
  {
  if (a.have_been_here_p == false){
    os <<a.area_script_p<<endl;
  }
  else{
    os <<a.already_been_area_script_p<<endl;
  }
    return os;
  }
};
#endif