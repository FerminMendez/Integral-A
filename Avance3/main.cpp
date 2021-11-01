#include <iostream>

#include <sstream>
#include <vector>
#include <cstring>
#include <string>

#include "stack.h"
#include "card.h"
#include "manage.h"
#include "bst.h"
using namespace std;

int main() {
  Manage m;
  
   cout<<"Original sorted. (ID) \n";
    vector<Card*> cards=m.getCards();
    cout<<m.printCards(cards);
    //Sorted by cost
    cout<<"By Cost \n";
    m.sortByCost(cards);
    cout<<m.printCards(cards);
    m.sortByName(cards);
    cout<<"By name \n";
    cout<<m.printCards(cards);
    
    cout<<"Example of a Stack created by cards\n";
    Stack<Card> mystack;
    mystack.add(*cards[1]);
    mystack.add(*cards[9]);
    mystack.add(*cards[6]);
    mystack.add(*cards[8]);
    mystack.add(*cards[12]);
    mystack.add(*cards[18]);
    mystack.add(*cards[2]);
    cout<<mystack.vaciar();

  cout<<"Example of a Stack created by the vector\n";
    Stack<Card> vstack(cards);
    cout<<vstack.vaciar();

  cout<<"Example of a Stack created by the BST\n";
    m.shuffle(cards);
   BST<Card> tree(cards);
   cout<<tree.print();
    cards=tree.getCards();
    m.save(cards);

  }