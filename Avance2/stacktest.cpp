#include <iostream>
#include "card.h"
#include <sstream>
#include <vector>
#include <cstring>
#include <string>
#include <fstream>

#include "stack.h"

int main() {

   Card card1("Nueva carta",8);
   Card card2("Hello",10);
    Card card3("good baay",10);
    std::vector<Card*> v;
    int n=8;
    while(n--){
        std::string s="Card "+std::to_string(n+1);
          v.push_back(new Card(s,n+1));
    } 
  
  Stack<Card> mystack;
  mystack.add(card1);
    mystack.add(card3);
    mystack.add(card2);
    std::cout<<mystack.pop().print();
    std::cout<<mystack.pop().print();
    std::cout<<mystack.pop().print();
    
    Stack<Card> vstack(v);

    std::cout<<vstack.pop().print();

  }