#include <iostream>
#include "card.h"
#include "deck.h"
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

#include "stack.h"

int main() {

  /*Primer entregable
  Deck deck;
  std::cout<<"\nOriginal order: \n";
  std::cout<<deck.print();
  std::cout<<"\nSorted cards by cost: \n";
  deck.sort();
  std::cout<<deck.print();
  std::cout<<"\nSorted cards by name: \n";
  deck.sort2();
  std::cout<<deck.print();*/
  
  //Para este crearemos un stack a partir de las cartas
   Deck deck;
   Card card1("Nueva carta",8);
  Stack<Card> myStack(deck.getDeck());
  cout>>myStack.toString();
  }