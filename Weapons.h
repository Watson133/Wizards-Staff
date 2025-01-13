#ifndef WEAPONS_H
#define WEAPONS_H

#include <iostream>
#include <string>

using namespace std;

#include "Items.h"

//--------------------Sub-class Weapons
class Weapon : public Items{

protected:
int min_weapon_damage_p;
int max_weapon_damage_p;

public:
//default constructor
  Weapon(){
    item_name_p = " ";
    item_info_p = " ";
    item_hint_p = " ";
  }

  Weapon (string item_name, string item_info, string item_hint, int min_weapon_damage, int max_weapon_damage){
    item_name_p = item_name;
    item_info_p = item_info;
    item_hint_p = item_hint;
    min_weapon_damage_p = min_weapon_damage;
    max_weapon_damage_p = max_weapon_damage;
  }

  void print_item_name(){
    cout<<"Name: "<<item_name_p;
  }

//weapon inspect info
  void print_item_inspection_info(){
    cout<<"Name: "<<item_name_p<<"\nItem ID: "<<item_ID_p<<"\nWeapon damage range: "<<min_weapon_damage_p<<"-"<<max_weapon_damage_p<<"\nAbout the item: "<<item_info_p<<"\nHint: "<<item_hint_p<<endl;
  }
};
#endif