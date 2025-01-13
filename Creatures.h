#ifndef CREATURES_H
#define CREATURES_H

#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

class Creatures {

protected:
string creature_encounter_script_p;
string creature_name_p;
int creature_health_p;
int creature_damage_p;
string creature_death_script_p;
string creature_about_to_attack_p;
string creature_can_be_attacked_p;
int creature_attack_frequency_p;

public:

Creatures(string creature_encounter_script, string creature_name, int creature_health, int creature_damage, string creature_death_script, string creature_about_to_attack, string creature_can_be_attacked, int creature_attack_frequency){
  creature_encounter_script_p = creature_encounter_script;
  creature_name_p = creature_name;
  creature_health_p = creature_health;
  creature_damage_p = creature_damage;
  creature_death_script_p = creature_death_script;
  creature_about_to_attack_p = creature_about_to_attack;
  creature_can_be_attacked_p = creature_can_be_attacked;
  creature_attack_frequency_p = creature_attack_frequency;
}

void print_encounter_script(){
  cout<<creature_encounter_script_p;
}

void print_death_script(){
  cout<<creature_death_script_p;
}

int fight_sequence(int min_weapon_damage, int max_weapon_damage){
  int item_number_to_use = 0;
  int fight_rounds_counter = 1;
  string fight_or_dodge = " ";
  int player_health = 100;
  bool creature_going_to_attack = false;

    cout<<"What item will you use?\n\n";

    cin>>item_number_to_use;

    while (item_number_to_use != 2){
      cout<<"\nWrong input\n";
      cin>>item_number_to_use;
      }

    cout<<"\nYou pull out your weapon, the fight begins.\n\n";

//fighting
  while (creature_health_p > 0){
    if (fight_rounds_counter % creature_attack_frequency_p==0){
      cout<<creature_about_to_attack_p<<endl<<endl;
      creature_going_to_attack = true;
    }
    else if (fight_rounds_counter % creature_attack_frequency_p != 0){
    cout<<creature_can_be_attacked_p<<endl<<endl;
    creature_going_to_attack = false;
    }

    cout<<"what do you do? (fight 'f' or dodge 'd')"<<endl;

    cin>>fight_or_dodge;

    if (fight_or_dodge == "f" && creature_going_to_attack == true){

      //play sword use script, eg, you swing your sword
      cout<<" You used your weapon however, you were too slow. "<<creature_name_p<<" hits you. You take "<<creature_damage_p<<" amount of damage. ";

      player_health = player_health - creature_damage_p;
      cout<<"Your health is at "<<player_health<<endl;
    }

    if (player_health <= 0){
      cout<<"\nYou feel your energy draining, you can't go on with the battle without a snack. You quickly pull out a carrot and devour it in one bite.\n(player health = ";

      player_health = 100;
      cout<<player_health<<")"<<endl;
    }  
    else if (fight_or_dodge == "f" && creature_going_to_attack == false){

      srand((unsigned)time(0));
      int r;
      r = (rand()%max_weapon_damage)+min_weapon_damage;
      cout<<"You do "<<r<<" amount of damage.";

      creature_health_p = creature_health_p - r;
      cout<<" The creature's health is at "<<creature_health_p<<endl<<endl;
    }



    else if (fight_or_dodge == "d" && creature_going_to_attack == true){
      cout<<"You successfully dodge it's attack\n"<<endl;
    }

    else if (fight_or_dodge == "d" && creature_going_to_attack == false){
      cout<<"\nYou dodged for nothing\n"<<endl;
    }
    fight_rounds_counter++;
  }

  print_death_script();
  return creature_health_p;
}
};
#endif