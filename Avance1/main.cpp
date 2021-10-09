#include <iostream>
#include "card.h"
#include "deck.h"
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

int main() {
  Deck deck;
  std::cout<<"\nOriginal order: \n";
  std::cout<<deck.print();
  std::cout<<"\nSorted cards by cost: \n";
  deck.sort();
  std::cout<<deck.print();
  std::cout<<"\nSorted cards by name: \n";
  deck.sort2();
  std::cout<<deck.print();
  
  }
