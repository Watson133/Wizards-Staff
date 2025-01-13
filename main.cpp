#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime> 

using namespace std;

#include "Items.h"
#include "Weapons.h"
#include "OneWayAreas.h"
#include "Areas.h"
#include "Creatures.h"

int main() {

  //player variables
  string player_name = " "; //name that the player chooses

  //item variables
  string item_name = " "; // Item Name, given to all items that enter the player's inventory
  int item_lastID = 0; //used for tracking the last ID number given to a item
  string item_info = " ";//Item Information, other information about an item
  string item_hint = " ";//gives hint for whta you can use it for
  int item_counter=0; //used for counting the number of items in the player's inventory
  int item_number_to_inspect = 1;//to inspect items using their assigned number in your inventory +1 (ex. item #1 = inventory[0]) cannot be 0 or else inspection loop will end imediately
  int item_number_to_use = 0;//for when entering item into mountain door and alter
  int min_weapon_damage = 0;//min amount of damage a weapon can do
  int max_weapon_damage = 0;//max amount of damage a weapon can do

  //area variables
  string area_name = " ";//area name
  bool can_move_left = false;//can you move left in this area
  bool can_move_right = false;//can you move right
  bool can_move_forward = false;//can you move forward 
  bool can_move_back = false;//can you move backward
  string area_script = " ";//print info about area
  string already_been_area_script = " ";//print info once already been there
  int conquered_areas = 0;//amount of areas where you have defeated the creature defending it

  //creature variables
  string creature_encounter_script;//prints right before you have to fight the creature
  string creature_name;
  int creature_health;
  int creature_damage;//amount of damage the creature can do to you
  string creature_death_script;//print when you kill the creature
  string creature_about_to_attack = " ";//print when the creature is about the attack
  string creature_can_be_attacked = " ";//prints when the creature is vulnerable and you can attack it
  int creature_attack_frequency = 1;//how often they attack, eg, every 3 turns, every 2 turns...

  //choice variables
  string quest_acceptance = " ";//used to take input for when the player is asked to accept or deny the quest
  bool item_continue = false;//for when player is choosing a weapon
  string choose_your_weapon = " "; //used when choosing your weapon
  string inspect_your_inventory = " ";//for choosing to look at your inventory closer or not

  //your inventory, an array of pointers
  Items *inventory[12];
  // will hold creature items, story items and weapons

  //make array of pointers
    Area *map[7];
  //holds the main map areas, 7 in total

  //all area information
  area_name = "Bar";
  area_script = "You have no money to pay the bartender back, so you run for the door. Out of no where... BONK! A beer mug is thrown at your head by the bartender.\n\nYou quickly pick up the cup and run out the door. You make your way down the street.\n\n(You escaped the bartender)\n\n([Beer Mug] enters your inventory)\n\n";
  One_Way_Area *bar = new One_Way_Area(area_name, area_script);

  area_name = "Market";
  area_script = "\n\nThe wizard beckons you inside. He seems eager to share a story.\n\nHe recounts, 'long ago my magic staff was lost to a terrible beast of fire and smoke. This beast has cursed our lands and can only be stopped with the retrieval of this artifact. Will you find the staff to heal our land? Be warned, as each piece of they key is protected by fierce and dangerous creatures. I'll pay you handsomely in return, of course.'\n\n";
  One_Way_Area *market = new One_Way_Area(area_name, area_script);

  area_name = "Outside_village_walls";
  area_script = "You walk outside the villages walls and find a farmers hay cart, they let you hitch a ride.\n\nBefore you hop on, you see a bag on the ground. You look closer and it's a big bag of carrots. No one is near you so you grab it incase you get hungry.\n\n([Bag of Carrots] enters your inventory)\n\n";
  One_Way_Area *out_vill_walls = new One_Way_Area(area_name, area_script);

  area_name = "Cart_drop_off";
  area_script = "\n\nThe cart skids to a sudden halt. The farmer says, 'this is as fare as I go'. You thank him for the the ride, then hop off onto a deserted path.\n\nAs you hear the cart pull away, you turn your eyes towards the horizon only to see that it is obstructed by a looming shadow. Mount Krampus.\n\nYour gaze returns to the winding dirt path ahead of you, and you begin your journey to the mountain.\n\n";
  One_Way_Area *cart_drop_off = new One_Way_Area(area_name, area_script);

  area_name = "Fork one";
  can_move_left = true;
  can_move_right = true;
  can_move_forward = true;
  can_move_back = false;

  area_script = "You reach a fork in the trail, to your left you see an empty grassland, to your right a dark foreboding cavern.\n\nIn front of you, the path continues for what seems like forever, meeting the mountains edge at the horizon. Where do yo go?\n";

  already_been_area_script = "\n\nYou're back at the first fork in the trail, the meadow is to your left, the cave is to your right, and the mountain path continues ahead of you.\n\n";

  Area *a = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[1] = new Area(*a);

    area_name = "Grass land";
  can_move_left = false;
  can_move_right = true;
  can_move_forward = false;
  can_move_back = false;

  area_script = "\n\nYou emerge onto the grasslands rolling green hills. Flowers dance on the breeze and a tree stands lonley ahead.\n";

  already_been_area_script = "\n\nThe grassland stands deserted. There is nothing left to see here.\n\n";

  Area *b = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[0] = new Area(*b);

    area_name = "Cave";
  can_move_left = true;
  can_move_right = false;
  can_move_forward = false;
  can_move_back = false;

  area_script = "\n\nYou cautiously approach the mouth of the cave. It looms dark in front of you and you notice remenants of bone surrounding its gaping entrance as you hear a deep growl echo from within.\n\n";

  already_been_area_script = "\n\nThe cave rests silent and empty. There are no longer any conquests to be made here.\n\n";

  Area *c = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[2] = new Area(*c);

  area_name = "Fork two";
  can_move_left = true;
  can_move_right = true;
  can_move_forward = true;
  can_move_back = true;

  area_script = "\n\nTo your left appears a thick forest, to your right, a murky lake, and ahead, the mountain grows ever closer.\n\n";

  already_been_area_script = "\n\nTo your left a forest, to your right a lake, and the mountain straight ahead.\n\n";

  Area *d = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[4] = new Area(*d);

  area_name = "Forest";
  can_move_left = false;
  can_move_right = true;
  can_move_forward = false;
  can_move_back = false;

  area_script = "\n\nThe forest grows gloomy as you venture within. The trees lean in towards you, suffocating. Crumbling remenants of a stone building lie deserted and overgrown, shrouded in shadows.\n\n";

  already_been_area_script = "\n\nThe trees seem almost less forboding, and flora and fauna has begun to grow as though a great burden has been lifted. You've done your part to help this forest.\n\n";

  Area *e = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[3] = new Area(*e);

  area_name = "Lake";
  can_move_left = true;
  can_move_right = false;
  can_move_forward = false;
  can_move_back = false;

  area_script = "\n\nMurky waters ripple out before you as you approach the waters edge. The darkness stretches on forever. Bubbles dance on the surface, something is lurking.\n\n";
  already_been_area_script = "\n\nYou're met with clear and peaceful waters. You observe schools of fish and flourishing coral beneath the sourface. You have restored their peacful homes.\n\n";

  Area *f = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[5] = new Area(*f);

  area_name = "Mountain door";
  can_move_left = false;
  can_move_right = false;
  can_move_forward = false;
  can_move_back = true;

  area_script = "\n\nMassive stone doors stand imposingly before you, stet in the mountain walls. Ancient writing borders 4 empty cavities carved into the door from what looks like eons ago.\n\n";
  already_been_area_script = "\n\nThe doors remain empty and abbandoned, waiting patiently for their keys.\n\n";

  Area *g = new Area(area_name, can_move_left, can_move_right, can_move_forward, can_move_back, area_script, already_been_area_script);

  map[6] = new Area(*g);

//all creature information
  creature_encounter_script = "\n\nSuddenly, the ground begins to shake, and you spot a massive hole in the ground before you. A fluffy figure bounds from the hole, landing in front of you. You're face to face with a giant fuzzy bunny the size of an elephant. It does not look happy.\n\n";

  creature_name = "Giant killer bunny";
  creature_health = 200;
  creature_damage = 15;
  creature_death_script = "\n\nThe bunny falls to the ground and disolves into a pile of carrots.\n\n(you have defeated the Giant Bunny)\n\nYou look through the pile of carrots and find a green gemstone and a huge rabbit's foot. You take them both.\n([Green Gemstone] enters your inventory)\n([Rabbit's Foot] enters your inventory)\n";

  creature_about_to_attack = "The bunny's beady eyes narrow at you, and its foot stomps the ground, shaking the earth.";
  creature_can_be_attacked = "The bunny sits back on its legs, and tilts it's head at you.";
  creature_attack_frequency = 4;

  Creatures *giant_bunny = new Creatures(creature_encounter_script,
  creature_name, creature_health, creature_damage, creature_death_script, creature_about_to_attack, creature_can_be_attacked, creature_attack_frequency);

  creature_encounter_script = "\n\nThe growls grow lounder and a shadow emerges from the darkness. An orc stands in front of you, club in it's fist, tusks protruding from it's mouth. It snorts, agitated by your presence.\n\n";
  creature_name = "Orc";
  creature_health = 250;
  creature_damage = 20;
  creature_death_script = "\n\nThe orc falls into the light of day from outside the cave. It's skin smoking in the sunlight suddenly turns to stone.\n\n(you have defeated the Orc)\n\nYou see something shiny in the orc's eye. You pull it out. It's light blue gemstone.\n([Light Blue Gemstone] enters your inventory)\nYou decide to take the orc club just in case.\n([Orc Club] enters your inventory)\n";
      item_name = "light blue gemstone";

  creature_about_to_attack = "The orc tightens his grip on his club.";
  creature_can_be_attacked = "The orc stares at you, intrigued. It doesn't seem to recognize the scent of human";
  creature_attack_frequency = 3;

  Creatures *orc = new Creatures(creature_encounter_script,
  creature_name, creature_health, creature_damage, creature_death_script, creature_about_to_attack, creature_can_be_attacked, creature_attack_frequency);

  creature_encounter_script = "\n\nCackles break the silence of the forest, as the bark of a nearby tree begins to peel back. A crooked figure emerges, bones from her past victims dangle from her head piece. She's wearing a human skull, all you can see of her face are her bloodshot eyes. She looks you up and down hungrily. 'You're next.'\n\n";
  creature_name = "Ancient bone witch";
  creature_health = 300;
  creature_damage = 25;
  creature_death_script = "\n\nShe lets out a cry as her body collapses to the ground. In seconds, all that remains is a pile of dust and bones.\n\n(you have defeated the Ancient Bone Witch)\n\nUnder the pile of bone lays a purple gemstone and an ancient yellowed skull. You take them both.\n([Purple Gemstone] enters your inventory)\n([Ancient Skull] enters your inventory)\n";

  creature_about_to_attack = "The witch grins, her hand drifts behind her back.";
  creature_can_be_attacked = "The witch cackles.";
  creature_attack_frequency = 3;

  Creatures *bone_witch = new Creatures(creature_encounter_script,
  creature_name, creature_health, creature_damage, creature_death_script, creature_about_to_attack, creature_can_be_attacked, creature_attack_frequency);

  creature_encounter_script = "\n\nScales break the water, a slythering serpent emerges from the depths. Its pointed head coils toward you and its snake like tounge darts in and out, licking its lips. 'You look like dinner'\n\n";
  creature_name = "Lake monster";
  creature_health = 350;
  creature_damage = 30;
  creature_death_script = "\n\nThe monster explodes into a thousand fish. They rain down into the lake, free of their captor.\n\n(you have defeated the Lake Monster)\n\n\nA fish falls down right in front of you and coughs out a dark blue gemstone which lands beside a conch shell. You pick them both up.\n([Dark Blue Gemstone] enters your inventory)\n([Conch Shell] enters your inventory)\n";

  creature_about_to_attack = "The serpent lowers itself into the lake, disapearing beneath the surface.";
  creature_can_be_attacked = "The serpent coils over and over itself.";
  creature_attack_frequency = 3;

  Creatures *lake_monster = new Creatures(creature_encounter_script,
  creature_name, creature_health, creature_damage, creature_death_script, creature_about_to_attack, creature_can_be_attacked, creature_attack_frequency);

//------------------------Area 1: The Bar
cout<<"\t\t\t\t\tQUEST FOR THE WIZARD'S STAFF\n\t\t\t\t\t   Chapter 1: The Quest\n\nYou awake in a bar, you have no recolection of last night but your name, which is...";

getline(cin, player_name);//input players name

cout<<"\nYou get up from your seat and head for the door. Suddenly a voice calls after you. 'HEY! You owe me for all those beers last night!'";


//------------------------------BREAK
  int type_any_number_to_continue;
  cout<<"\n\n\n\ttype any number to continue: ";
  cin>>type_any_number_to_continue;
  cout<<"\n\n\n";
  //is a break between sentences to give the player time to read and not be overwhelmed
//------------------------------BREAK


  bar->print_area_script();//print main bar area 

  //-------------------Item added to inventory
  item_name = "beer mug";//item name is created

  //item inspection info
  item_info = "A sturdy wooden beer mug.";

  item_hint = "Helpful for grabbing a beer.";

  Items *h = new Items(item_name, item_info, item_hint);//pointer to new item

  inventory[0] = new Items(*h);//item is added to inventory

  item_lastID = inventory[0]->getitemID(item_lastID);//this item ID becomes the last ID number

  item_counter++;//counting number of items currently in inventory

//------------------------------BREAK
  cout<<"\n\ttype any number to continue: ";
  cin>>type_any_number_to_continue;
  cout<<"\n\n\n";
//------------------------------BREAK

//-------------------------Area 2: The Market  
  cout<<"You reach a market, stalls cover every foot of the town square. You feel drawn to a tent in the corner and make your way towards it. \n\nYour eyes fall uppon a cloaked figure standing just outside, an old wizard.";

  //------------------------------BREAK
    cout<<"\n\n\n\ttype any number to continue: ";
    cin>>type_any_number_to_continue;
    cout<<"\n";
  //------------------------------BREAK

    market->print_area_script();

//----------------------Do you accept the quest
  cout<<"\tDo you accept the wizards quest? (type 'yes' or 'no')\n\n";

  cin>>quest_acceptance;

  while (quest_acceptance != "yes"){//loop continues until quest_acceptance is equal to yes

    //if no, game ends
    if (quest_acceptance == "no"){
      cout<<"\n\nThe wizard sighs in dissapointment and vanishes before your eyes. You leave the market and continue to live your meaningless life.\n\n\t\t\t\t\t\t\tThe End."<<endl;
      return 0;
    }

    //if wrong input, loop continues
    cout<<"wrong input\nTry again\n";
    cin>>quest_acceptance;
  }

  cout<<"\n\nYou accept the quest, you have nothing to lose. The wizard sends you to the black smith to acquire a weapon of your choosing.\n\nThe blacksmith offers you a choice, a sword or a bow, which one do you pick?' \n\n\t(type 'sword' or 'bow')\n\n\n";
  //choose your weapon
  cin>>choose_your_weapon;
    while (item_continue == false){//loops until player inputs sword or bow
      if (choose_your_weapon == "sword"){//if sword, adds sword to inventory
        cout<<"\n\n([Sword] enters your inventory)\n\n\n";

        item_name = "sword";
        item_info = "A steel long sword with rusted symbols carved into the blade, they look ancient.";
        item_hint = "I wouldn't want to be on the revieving end of this blade.";
        min_weapon_damage = 75;
        max_weapon_damage = 100;

        Weapon *i = new Weapon(item_name, item_info, item_hint, min_weapon_damage, max_weapon_damage);//name assigned to new item
        inventory[1] = new Weapon(*i);//pointer is set in inventory
        item_lastID = inventory[1]->getitemID(item_lastID);//this ID -> last ID
        item_counter++;//counting number of items currently in inventory
        item_continue = true;
      }
      else if (choose_your_weapon == "bow"){//ends loop if player inputs bow
        cout<<"\n\n([Bow] enters your inventory)\n\n\n";

        item_name = "bow";
        item_info = "A mahogany bow with a silk draw string and steel tipped arrows.";
        item_hint = "With the right skill, no one is safe from these deadly projectiles.";
        min_weapon_damage = 50;
        max_weapon_damage = 125;

        Weapon *i = new Weapon(item_name, item_info, item_hint, min_weapon_damage, max_weapon_damage);//name assigned to new item
        inventory[1] = new Weapon(*i);//pointer is set in inventory
        item_lastID = inventory[1]->getitemID(item_lastID);//this ID -> last ID
        item_counter++;//counting number of items currently in inventory
        item_continue = true;//ends loop
      } 
      else{

        cout<<"wrong input\nTry again\n";//if wrong input, loop keeps running
        cin>>choose_your_weapon;
      }
    }  
cout<<"You return to the wizard and he pulls out a map and points at mount Krampus. You look up and see a similar form in the distance. That must be it.\n\n'That's where my staff is, I wish you goodluck ' he says. You grab your weapon and the map and off you go.\n\n([map] enters your inventory)\n\n";

  item_name = "map";
  item_info = "The map shows a path leading to the montain doors.";
  item_hint = "There must be something pretty important behind those doors.";

  Items *j = new Items(item_name, item_info, item_hint);
  inventory[2] = new Items(*j);
  item_lastID = inventory[2]->getitemID(item_lastID);
  item_counter++;
//-------------------------Area 2: End

//------------------------------BREAK
  cout<<"\n\ttype any number to continue: ";
  cin>>type_any_number_to_continue;
  cout<<"\n\n\n";
//------------------------------BREAK

  cout<<"\t\t\t\t\t   Chapter 2: To The Mountain\n\n"<<endl;
//-------------------------Area 3: The Cart
  out_vill_walls->print_area_script();

  item_name = "bag of carrots";
  item_info = "A drawstring bag filled with 10 pounds of freshly pulled carrots.";
  item_hint = "Looks like a healthy energizing snack.";

  Items *k = new Items(item_name, item_info, item_hint);
  inventory[3] = new Items(*k);
  item_lastID = inventory[3]->getitemID(item_lastID);  

  cout<<"As you approach the mountains you take some time to make sure you have everything you need.\n\n\tDo you want to look at your inventory more closely? \n\n(type 'yes' or 'no')\n\n\n";

  cin>>inspect_your_inventory;

  if (inspect_your_inventory == "yes"){
    cout<<"\n\nYou completely empty your pockets. You have...\n\n";
      for (int i=0; i<=item_counter; i++){//prints your inventory
        cout<<"Item # "<<i+1<<" ";
        inventory[i]->print_item_name();
        cout<<"\n\n";
      }
    cout<<"\n\nWhat item do you want to inspect?\n\n\t(type item # of the item you are interested in, and type '0' if you want to end the inspection cycle)\n\n";

    while (item_number_to_inspect != 0){
      //loops until player inputs 0 to end
      cin>>item_number_to_inspect;
      cout<<"\n";
      if (item_number_to_inspect<=item_counter+1&&item_number_to_inspect>0){
//has to be in your inventory, cant be a negative number inventory space
        inventory[item_number_to_inspect-1]->print_item_inspection_info();
        cout<<endl;
      } 
      else if (item_number_to_inspect != 0){//if player inputs anything other than 0 or a number associated with an inventory space that has an item
        cout<<"wrong input\nTry again\n";
        //if wrong input, loop keeps running
      }
    } 
  }
  else {
    cout<<"\n\nYou find that is a waste of time. Instead you spend your time staring at the mountain as it ever so slowly gets closer. \n\n";
  }
//inspect inventory end

  cart_drop_off->print_area_script();

//------------------------------BREAK
  cout<<"\n\ttype any number to continue: ";
  cin>>type_any_number_to_continue;
  cout<<"\n\n\n";
//------------------------------BREAK

    cout<<"\t\t\t\t\t   Chapter 3: The Gemstones\n\n"<<endl;
//------------------------Area 4: Fork in the trail 1
  cout<<*map[1];
  map[1]->set_have_been_here_p();

  //------------------------------BREAK
    cout<<"\n\ttype any number to continue: ";
    cin>>type_any_number_to_continue;
    cout<<"\n\n\n";
  //------------------------------BREAK

  cout<<"(to go left type 'l', right 'r', forward 'f', backwards 'b')\n"<<endl;
    bool can_move = false;
    string move = " ";
    int area_map_location_number = 1;//is used to move through areas using their map location number

  //movement loop
  while (conquered_areas < 5){

    cin>>move;
    can_move = false;

    while (can_move == false){
      if (move == "l"||move == "r"||move == "f"||move == "b"){
        if (move == "l"){//for moving left
          if (map[area_map_location_number]->get_move_left()==false){
            cout<<"cannot move there.\nTry again"<<endl;
            cin>>move;
          }
          else{
            can_move = true;
              area_map_location_number --;
            cout<<"You move to the left...\n"<<endl;
            //move to next room
          }
        }
        else if (move == "r"){//for moving right
          if (map[area_map_location_number]->get_move_right()==false){
            cout<<"cannot move there.\nTry again"<<endl;
            cin>>move;
          }
          else{
            can_move = true;
              area_map_location_number ++;
            cout<<"You move to the right...\n"<<endl;
            //move to next room
          }
        }
        else if (move == "f"){//for moving forward
          if (map[area_map_location_number]->get_move_forward()==false){
            cout<<"cannot move there.\nTry again"<<endl;
            cin>>move;
          }
          else{
            can_move = true;
              if (area_map_location_number == 4){
                area_map_location_number = area_map_location_number + 2;
              }
              else{
                area_map_location_number = area_map_location_number + 3;
              }
            cout<<"You move forward...";
            //move to next room
          }
        }
        else if (move == "b"){//for moving backward
          if (map[area_map_location_number]->get_move_back()==false){
            cout<<"cannot move there.\nTry again"<<endl;
            cin>>move;
          }
          else{
            can_move = true;
            if (area_map_location_number == 6){
              area_map_location_number = area_map_location_number - 2;
            }
            else{
              area_map_location_number = area_map_location_number - 3;
            }
            cout<<"You move backward...";
            //move to next room
          }
        }
      }
      else{
        cout<<"wrong input\nTry again"<<endl;
        cin>>move;
      }
    }
    cout<<*map[area_map_location_number];

    if (area_map_location_number == 6 && conquered_areas == 4){//if you have defeated all enemies, go to mountain door area to end movement loop
      conquered_areas++;
    }

    //Grassland encounter
    if (area_map_location_number == 0&&map[area_map_location_number]->get_have_been_here() == false){
  //if its your first time here the encounter plays
      for (int ll = 0; ll<= item_counter; ll++){
        cout<<"item # "<<ll+1<<" ";
        cout<<inventory[ll]->get_item_name();
        cout<<endl;
      }
      //print creature encounter text
      giant_bunny->print_encounter_script();
      //send into fight loop
      giant_bunny->fight_sequence(min_weapon_damage, max_weapon_damage);

      item_name = "green gemstone";//item name is created
      //item inspection info
      item_info = "A shiny emerald.";
      item_hint = "Looks like it could be used at the door.";

      item_counter++;//counting number of items currently in inventory
      Items *l = new Items(item_name, item_info, item_hint);
      inventory[item_counter] = new Items(*l);
      item_lastID = inventory[item_counter]->getitemID(item_lastID);//this item ID becomes new last ID number

      item_name = "rabbit's foot";//item name is created
      //item inspection info
      item_info = "A fluffy ball of luck.";
      item_hint = "People feel drawn to its luck.";
      item_counter++;

      Items *m = new Items(item_name, item_info, item_hint);
      inventory[item_counter] = new Items(*m);
      item_lastID = inventory[item_counter]->getitemID(item_lastID);

      map[area_map_location_number]->set_have_been_here_p();
      conquered_areas++;
      area_map_location_number ++;
      cout<<*map[area_map_location_number];
    }
    //Cave encounter
        if (area_map_location_number == 2&&map[area_map_location_number]->get_have_been_here() == false){
    //if its your first time here the encounter plays
          for (int ll = 0; ll<= item_counter; ll++){
            cout<<"item # "<<ll+1<<" ";
            cout<<inventory[ll]->get_item_name();
            cout<<endl;
          }
          //print creature encounter text
          orc->print_encounter_script();
          //send into fight loop
          orc->fight_sequence(min_weapon_damage, max_weapon_damage);

          item_info = "A glistening diamond";
          item_hint = "Looks like it could be used at the door.";
          item_counter++;

          Items *n = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*n);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          item_name = "orc club";
          item_info = "A wooden club stained by something red.";
          item_hint = "A powerful weapon, anyone would be drawn to it.";
          item_counter++;

          Items *o = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*o);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          map[area_map_location_number]->set_have_been_here_p();
          conquered_areas++;
          area_map_location_number --;
          cout<<*map[area_map_location_number];
        }
    //Lake encounter
        if (area_map_location_number == 5&&map[area_map_location_number]->get_have_been_here() == false){
    //if its your first time here the encounter plays
          for (int ll = 0; ll<= item_counter; ll++){
            cout<<"item # "<<ll+1<<" ";
            cout<<inventory[ll]->get_item_name();
            cout<<endl;
          }
          //print creature encounter text
          lake_monster->print_encounter_script();
          //send into fight loop
          lake_monster->fight_sequence(min_weapon_damage, max_weapon_damage);

          item_name = "dark blue gemstone";
          item_info = "A gleaming saphire.";
          item_hint = "Looks like it could be used at the door.";
          item_counter++;

          Items *p = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*p);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          item_name = "Conch shell";
          item_info = "A huge shell, luckily nothing is hiding inside.";
          item_hint = "A shell this big would sure draw some attention.";
          item_counter++;

          Items *q = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*q);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          map[area_map_location_number]->set_have_been_here_p();
          conquered_areas++;
          area_map_location_number --;
          cout<<*map[area_map_location_number];
        }
    //Forest encounter
        if (area_map_location_number == 3&&map[area_map_location_number]->get_have_been_here() == false){
    //if its your first time here the encounter plays
          for (int ll = 0; ll<= item_counter; ll++){
            cout<<"item # "<<ll+1<<" ";
            cout<<inventory[ll]->get_item_name();
            cout<<endl;
          }
          //print creature encounter text
          bone_witch->print_encounter_script();
          //send into fight loop

          //print creature death script
          bone_witch->fight_sequence(min_weapon_damage, max_weapon_damage);

          item_name = "purple gemstone";
          item_info = "A lustrous amethyst.";
          item_hint = "Looks like it could be used at the door.";
          item_counter++;

          Items *r = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*r);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          item_name = "ancient skull";
          item_info = "A yellowed skull worn from time.";
          item_hint = "A ancient relic like this would sure draw in a crowd.";
          item_counter++;

          Items *s = new Items(item_name, item_info, item_hint);
          inventory[item_counter] = new Items(*s);
          item_lastID = inventory[item_counter]->getitemID(item_lastID);

          map[area_map_location_number]->set_have_been_here_p();
          conquered_areas++;
          area_map_location_number ++;
          cout<<*map[area_map_location_number];
        }
    map[area_map_location_number]->set_have_been_here_p();
  }

  cout<<"\n\t\t\t\t\t   Chapter 4: Inside The Mountain\n\n"<<endl;
//ending
  cout<<"You are standing in front of the door, it doesn't budge. It seems as though the gems in your inventory fit the empty slots in the door.\n(type in the item number of what you want to use at the door)\n\n";
  for (int ll = 0; ll<= item_counter; ll++){
    cout<<"item # "<<ll+1<<" ";
    cout<<inventory[ll]->get_item_name();
    cout<<endl;
  }
  item_continue = false;
  int gem_used_counter = 0;

  while (item_continue == false){
    cin>>item_number_to_use;

    if (item_number_to_use >= 13 || item_number_to_use <= -1){
    cout<<"\nNot in inventory\n";
    }
    if (item_number_to_use == 5){
      cout<<"\nIt snaps into place\n";
      gem_used_counter++;
    }
    if (item_number_to_use == 7){
      cout<<"\nIt snaps into place\n";
      gem_used_counter++;
    }
    if (item_number_to_use == 9){
      cout<<"\nIt snaps into place\n";
      gem_used_counter++;
    }
    if (item_number_to_use == 11){
      cout<<"\nIt snaps into place\n";
      gem_used_counter++;
    }
    if (gem_used_counter==4){
      item_continue = true;
    }
    else if (item_number_to_use <= 12 && item_number_to_use != 5 && item_number_to_use != 7 && item_number_to_use != 9 && item_number_to_use != 11){
      cout<<"\nNothing happens\n";
    }
  }
  cout<<"\n\nThe door slides open. Inside is a small room with stone  walls. In the center of the room floats the staff awaiting retrieval. To your right you see 4 pedestals resembling an alter.\n(type in the item number of what you want to use at the alter)\n\n";
  item_continue = false;
  int item_used_at_alter_counter = 0;

  while (item_continue == false){
    cin>>item_number_to_use;

    if (item_number_to_use == 6){
      cout<<"\nYou hear a click.\n";
      item_used_at_alter_counter++;
    }
    if (item_number_to_use == 8){
      cout<<"\nYou hear a click.\n";
      item_used_at_alter_counter++;
    }
    if (item_number_to_use == 10){
      cout<<"\nYou hear a click.\n";
      item_used_at_alter_counter++;
    }
    if (item_number_to_use == 12){
      cout<<"\nYou hear a click.\n";
      item_used_at_alter_counter++;
    }
    if (item_used_at_alter_counter==4){
        item_continue = true;
    }
    else if (item_number_to_use <= 13 && item_number_to_use != 6 && item_number_to_use != 8 && item_number_to_use != 10 && item_number_to_use != 12){
      cout<<"\nNothing happens\n";
    }
    else if (item_number_to_use >= 13 || item_number_to_use <= -1){
    cout<<"\nNot in inventory\n";
    }
  }
    cout<<"\n\nYou've filled each pedestal at the alter. Suddenly the wizard appears in front of you.\n\nThe wizard seems younger, healthier, not sick and tired like he was when we first met. 'Thank you "<<player_name<<". You have saved me and this world from our curse.'\n\nThe wizard offers you a final choice. Become a wizard like him to keep the worlds peace, or keep the gemstones, which would leave you richer than imaginable. (make you last choice now, type 'wizard' or 'gemstones')\n\n";

  string wizard_or_gems = " ";

  cin>>wizard_or_gems;

  while (wizard_or_gems != "wizard"){
    if (wizard_or_gems == "gemstones"){
      cout<<"You choose the gems. The wizard sighs, he forced a smile, and presents you with the gems. You return to the village and head straight for the bar. You pay off you racked up dept and whip out your beer mug and share a drink with the bartender.\n\n\t\t\t\t\t\t\tThe End.\n\n";
      return 0;
    }
    else{
      cout<<"wrong input\nTry again\n";
      cin>>wizard_or_gems;
    }
  }
  cout<<"You decide to follow in the wizards footsteps and become his apprentice. The wizard smiles, greatful for your choice. He takes your hand and you both vanish into thin air.\n\n\t\t\t\t\t\t\tThe End.\n\n";

  //memory dealocation
  for (int i = 0; i<=11; i++){
  delete [] inventory[i];
  }
  for (int i = 0; i<=6; i++){
  delete [] map[i];
  }
  delete giant_bunny;
  delete bone_witch;
  delete orc;
  delete lake_monster;
  delete bar;
  delete market;
  delete out_vill_walls;
  delete cart_drop_off;
}