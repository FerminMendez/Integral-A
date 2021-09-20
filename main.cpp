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
  std::cout<<"\nSorted cards: \n";
  deck.sort();
  std::cout<<deck.print();
  }