#ifndef CARD
#define CARD

#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>

//Clase card

class Card{

  private:
  //Elements of the card
  int id;                 //ID
  std::string name;       //Name
  int cost;               //Cost
  std::string type;       //Type
  std::string des;//Description

  public:
  //Constructor
  Card(int,std::string,int,std::string,std::string);

  //Getters
  int getID();            //Get ID
  std::string getName();  //Get name
  int getCost();          //Get cost
  std::string getType();  //Get type
  std::string getDescription();  //Get description
  
  //Mehtods
  std::string print();    //Print the card
};

//Constructor
Card::Card(int _id, std::string _name,int _cost,std::string _type, std::string _des):id(_id),name(_name),cost(_cost),type(_type),des(_des){}

//Getters
int Card::getID(){return id;}
std::string Card::getName(){return name;}
int Card::getCost(){return cost;}
std::string Card::getType(){return type;}
std::string Card::getDescription(){return des;}

//Methods

//Print
std::string Card::print(){
  std::stringstream sstm;
  sstm <<"The card number "<<std::to_string(id)<<" is "<< name << " has a cost of "<<cost<<" and is type "<< type<< '\n';
  std::string result = sstm.str();
  return result;
}



#endif