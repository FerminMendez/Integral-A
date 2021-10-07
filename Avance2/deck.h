#ifndef DECK
#define DECK

#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <fstream>

#include "card.h"



class Deck{
  private:
  void swap(int,int);
  std::vector<Card*> cards;
  public:
  Deck();
  std::string print();
  void sort();
  void sort2();
  std::vector<Card*> getDeck();
};

Deck::Deck(){
  std::vector <std::string> vec;//Vector
  std::string line;
  std::ifstream myfile ("CardsData.csv");
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      vec.clear();
      std::stringstream ss(line);
     //std::cout << line << '\n';
      while( ss.good() )
        {
            std::string substr;
            getline( ss, substr, ',' );
            vec.push_back( substr );
        }
      std::string name=vec[0];
      std::stringstream s(vec[1]);
  
      // The object has the value 12345 and stream
      // it to the integer x
      int cost = 0;
      s >> cost;
      Card* ptr=new Card(name,cost);
      cards.push_back(ptr);
    }
    myfile.close();
  }
  else {
    std::cout << "Unable to open file"; 
  }
}

  std::string Deck::print(){
    std::vector<Card*>::iterator i;
    std::string x;
    std::string msg="";
    for(i = cards.begin(); i != cards.end(); ++i)
      {
      // Methos of the pointer i 
      msg=msg+x;
      x=(*i)->print();
      }
    return msg;
  }

  void Deck::swap(int i, int j) {
    Card* aux = cards[i];
    cards[i] = cards[j];
    cards[j] = aux;
  }
  void Deck::sort(){
    for (int i=0;i<cards.size();i++){
    int j=i;
      while (j>0 && cards[j]->getCost()<cards[j-1]->getCost()){
        swap(j,j-1);
        j=j-1;
      }
    }
  }

   void Deck::sort2(){
    for (int i=0;i<cards.size();i++){
    int j=i;
      while (j>0 && cards[j]->getName()<cards[j-1]->getName()){
        swap(j,j-1);
        j=j-1;
      }
    }
  }

   std::vector<Card*> Deck::getDeck(){
     return cards;
   }


#endif