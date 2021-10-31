#ifndef MANAGE
#define MANAGE

#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>
#include "card.h"
#include "stack.h"

//Random
#include <cstdlib>

class Manage{

  private:
  void swap(int,int,std::vector<Card*> &);

  public:
  //Constructor
  Manage();

  //Getters

  //Mehtods
  std::vector<Card*> getCards();    //Return a vector of pointer of the class Card that read in the .csv
  std::string printCards(std::vector<Card*> &); //Given a vector as we returned in the previus method print all the cards contained.
  void shuffle(std::vector<Card*> &);
  void sortByCost(std::vector<Card*> &);
  void sortByName(std::vector<Card*> &);
  void save(std::vector<Card*> &);
};

//Constructor
Manage::Manage(){}

//Getters


//Methods

std::vector<Card*> Manage::getCards(){//return the vector of pointers with all the cards
std::vector <std::string> vec;//Vector
    std::vector<Card*> cards;
  std::string line;
  std::ifstream myfile ("CardsData.csv");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vec.clear();
      std::stringstream ss(line);
      while( ss.good() )
        {
            std::string substr;
            getline( ss, substr, ',' );
            vec.push_back( substr );
        }
     int id=std::stoi(vec[0]);
      std::string name=vec[1];
      int cost=std::stoi(vec[2]);
      std::string type=vec[3];
      std::string des=vec[4];

      Card* ptr=new Card(id,name,cost,type,des);
      cards.push_back(ptr);
    }
    myfile.close();
  }
  else {
    std::cout << "Unable to open file"; 
  }
  return cards;
}

//Print cards
std::string Manage::printCards(std::vector<Card*> &cards){
   vector<Card*>::iterator i;
    string x;
    string msg="";
    for(i = cards.begin(); i != cards.end(); ++i)
      {
      // Methos of the pointer i 
      msg=msg+x;
      x=(*i)->print();
      }
    return msg;
}


  void Manage::swap(int i, int j,std::vector<Card*> &cards) {
    Card* aux = cards[i];
    cards[i] = cards[j];
    cards[j] = aux;
  }

  void Manage::sortByCost(std::vector<Card*> &cards){
    for (int i=0;i<cards.size();i++){
    int j=i;
      while (j>0 && cards[j]->getCost()<cards[j-1]->getCost()){
        swap(j,j-1,cards);
        j=j-1;
      }
    }
  }

   void Manage::sortByName(std::vector<Card*> &cards){
    for (int i=0;i<cards.size();i++){
    int j=i;
      while (j>0 && cards[j]->getName()<cards[j-1]->getName()){
        swap(j,j-1,cards);
        j=j-1;
      }
    }
  }

   void Manage::shuffle(std::vector<Card*> &cards){
    int m=cards.size();
    for (int i=0;i<m;i++){
      swap(i,rand()%m+1,cards);
      m--;
    }
  }

  void Manage::save(std::vector<Card*> &cards){
     std::ofstream myfile;
     std::string s;
     vector<Card*>::iterator i;
      myfile.open ("CardsData.csv");
       for(i = cards.begin(); i != cards.end(); ++i)
      {
        s=std::to_string((*i)->getID())+","+(*i)->getName()+","+std::to_string((*i)->getCost())+","+(*i)->getType()+","+(*i)->getDescription()+"\n";
      myfile <<s;
      }
      myfile.close();
      std::cout<<"\nSaved\n";
  }




#endif