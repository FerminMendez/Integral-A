#ifndef CARD
#define CARD

#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>


class Card{
  private:
  std::string name;
  int cost;
  public:
  Card(std::string,int);
  std::string print();
  int getCost();
  std::string getName();
  
};

Card::Card(std::string _name,int _cost){
  name=_name;
  cost=_cost;
}

std::string Card::print(){
  std::stringstream sstm;
  sstm <<"The card "<< name << " has a cost of "<<cost<<'\n';
  std::string result = sstm.str();
  return result;
}

int Card::getCost(){
  return cost;
}

std::string Card::getName(){
  return name;
}



#endif