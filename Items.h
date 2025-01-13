#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>
#include <string>

using namespace std;

class Items{
protected:
//the p at the end of every variable stands for protected.
  string item_name_p;//items' names
  string item_info_p;//for inspecting items
  int item_ID_p;//items' ID
  string item_hint_p;//for inspecting item, gives hint to what it is     going to be used for

public:

 string get_item_name(){
   return item_name_p;
 }

//default constructor
  Items(){

    item_name_p = " ";
    item_info_p = " ";
    item_hint_p = " ";
  }

  //set function & constructor
  Items (string item_name, string item_info, string item_hint){
    item_name_p = item_name;
    item_info_p = item_info;
    item_hint_p = item_hint;
  }  

//base function that finds if a number is prime
bool IsPrime(int &n){
  if (n<=1){
    return false;
  }
  for (int i=2; i<=n/2; i++){
    if (n%i==0){
      return false;
    }  
  }
return true;
}

//uses last employee ID # and finds next one
int getitemID(int item_lastID){
  bool isprime = false;

  if (item_lastID==0){
    item_lastID = 60800073;
    item_ID_p = 60800073;
    return item_ID_p;
  }
  else {
    for (int i=item_lastID+2; isprime==false; i=i+2){
      if (IsPrime(i)==true){//using the function that finds a prime number to find the next 6 digit prime number
        item_ID_p = i;
        isprime = true;
        item_lastID = i;
      }
    }
  return item_ID_p;
  }
}

//prints first level information, the name. 
  virtual void print_item_name(){
    cout<<"Name: "<<item_name_p;
  }

//prints second level information as well as first, item ID, little info on the item,  hint on how the item will be used. 
  virtual void print_item_inspection_info(){
    cout<<"Name: "<<item_name_p<<"\nItem ID: "<<item_ID_p<<"\nAbout the item: "<<item_info_p<<"\nHint: "<<item_hint_p<<endl;
  }
};
#endif