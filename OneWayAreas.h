#ifndef ONEWAYAREAS_H
#define ONEWAYAREAS_H

#include <iostream>
#include <string>

using namespace std;

class One_Way_Area{

protected:
string area_name_p;
string area_script_p;//quick description of the area when you enter it

public:

One_Way_Area(){
  area_name_p = " ";
  area_script_p = " ";
}

One_Way_Area(string area_name, string area_script){
  area_name_p = area_name;
  area_script_p = area_script;
}

  string get_area_name(){
    return area_name_p;
  }
  string get_area_script_p(){
   return area_script_p;
  }

  void print_area_script(){
    cout<<area_script_p;
  }
};
#endif