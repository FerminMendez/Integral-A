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


int main(int argc, char* argv[]) {
  string ans = "";
  bool found = 0;
  Card carta1(6,"Skycraper",6,"Discard","Gain 4 stars");
  Card carta2(9,"Extra head",7,"Keep","You get 1 extra die");
  cout<<"Casos de prueba clase Card \n";

  ans="Skycraper";
	cout << "\n" <<"1.- esperada " << ans << "\n programa " << carta1.getName() << "\n";
  cout <<	(!ans.compare(carta1.getName()) ? "success\n" : "fail\n");

  ans="Extra head";
	cout << "\n" <<"2.- esperada " << ans << "\n programa " << carta2.getName() << "\n";
  cout <<	(!ans.compare(carta2.getName()) ? "success\n" : "fail\n");

  ans="6";
	cout << "\n" <<"3.- esperada " << ans << "\n programa " << carta1.getCost() << "\n";
  cout <<	(!ans.compare(to_string(carta1.getCost())) ? "success\n" : "fail\n");

  ans="7";
	cout << "\n" <<"4.- esperada " << ans << "\n programa " << carta2.getCost() << "\n";
  cout <<	(!ans.compare(to_string(carta2.getCost())) ? "success\n" : "fail\n");

  ans="Discard";
	cout << "\n" <<"5.- esperada " << ans << "\n programa " << carta1.getType() << "\n";
  cout <<	(!ans.compare(carta1.getType()) ? "success\n" : "fail\n");

  ans="Keep";
	cout << "\n" <<"6.- esperada " << ans << "\n programa " << carta2.getType() << "\n";
  cout <<	(!ans.compare(carta2.getType()) ? "success\n" : "fail\n");

  ans="6";
	cout << "\n" <<"7.- esperada " << ans << "\n programa " << carta1.getID() << "\n";
  cout <<	(!ans.compare(to_string(carta1.getID())) ? "success\n" : "fail\n");

  ans="9";
	cout << "\n" <<"8.- esperada " << ans << "\n programa " << carta2.getID() << "\n";
  cout <<	(!ans.compare(to_string(carta2.getID())) ? "success\n" : "fail\n");

  ans="Gain 4 stars";
	cout << "\n" <<"9.- esperada " << ans << "\n programa " << carta1.getDescription() << "\n";
  cout <<	(!ans.compare(carta1.getDescription()) ? "success\n" : "fail\n");

  ans="You get 1 extra die";
	cout << "\n" <<"10.- esperada " << ans << "\n programa " << carta2.getDescription() << "\n";
  cout <<	(!ans.compare(carta2.getDescription()) ? "success\n" : "fail\n");

  found = (carta1<carta2);
  cout << "\n" <<"11.- esperada " << 1 << " programa " << found << "\n";
  cout << " 6 " <<	(found == 1 ? "success\n" : "fail\n");

  found = (carta1>carta2);
  cout << "\n" <<"12.- esperada " << 0 << " programa " << found << "\n";
  cout << " 6 " <<	(found == 0 ? "success\n" : "fail\n");

  found = (carta1==carta2);
  cout << "\n" <<"13.- esperada " << 0 << " programa " << found << "\n";
  cout << " 6 " <<	(found == 0 ? "success\n" : "fail\n");

  ans="6-Skycraper with cost 6";
	cout << "\n" <<"14.- esperada " << ans << "\n programa " << carta1.showVal() << "\n";
  cout <<	(!ans.compare(carta1.showVal()) ? "success\n" : "fail\n");

  ans="9-Extra head with cost 7";
	cout << "\n" <<"15.- esperada " << ans << "\n programa " << carta2.showVal() << "\n";
  cout <<	(!ans.compare(carta2.showVal()) ? "success\n" : "fail\n");

  cout<<"Casos de prueba clase Manage \n";
  Manage m;
  vector<Card*> cards=m.getCards();
  m.sortById(cards);
  vector<Card*> aux;
  for(int i=0;i<3;i++){
    aux.push_back(cards[i]);
  }

  m.sortById(aux);
  ans =	"The card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\n";
	cout << "\n" <<"16.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  m.sortByCost(aux);
  ans =	"The card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\n";
	cout << "\n" <<"17.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  m.sortByName(aux);
  ans =	"The card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\n";
	cout << "\n" <<"18.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  aux.clear();
  for(int i=0;i<10;i++){
    aux.push_back(cards[i]);
  }

  m.sortById(aux);
  ans =	"The card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\nThe card number 4 is Nova Breath has a cost of 7 and is type Keep\nThe card number 5 is Rooting for the underdog has a cost of 3 and is type Keep\nThe card number 6 is Skycraper has a cost of 6 and is type Discard\nThe card number 7 is Corner store has a cost of 3 and is type Discard\nThe card number 8 is Friend of childre has a cost of 3 and is type Keep\nThe card number 9 is Extra head has a cost of 7 and is type Keep\nThe card number 10 is Background dweller has a cost of 4 and is type Keep\n";
	cout << "\n" <<"19.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  m.sortByCost(aux);
  ans =	"The card number 5 is Rooting for the underdog has a cost of 3 and is type Keep\nThe card number 7 is Corner store has a cost of 3 and is type Discard\nThe card number 8 is Friend of childre has a cost of 3 and is type Keep\nThe card number 10 is Background dweller has a cost of 4 and is type Keep\nThe card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\nThe card number 6 is Skycraper has a cost of 6 and is type Discard\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\nThe card number 4 is Nova Breath has a cost of 7 and is type Keep\nThe card number 9 is Extra head has a cost of 7 and is type Keep\n";
	cout << "\n" <<"20.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  m.sortByName(aux);
  ans =	"The card number 1 is Alpha Monster has a cost of 5 and is type Keep\nThe card number 3 is Apartament building has a cost of 5 and is type Discard\nThe card number 10 is Background dweller has a cost of 4 and is type Keep\nThe card number 7 is Corner store has a cost of 3 and is type Discard\nThe card number 9 is Extra head has a cost of 7 and is type Keep\nThe card number 2 is Frenezy has a cost of 7 and is type Discard\nThe card number 8 is Friend of childre has a cost of 3 and is type Keep\nThe card number 4 is Nova Breath has a cost of 7 and is type Keep\nThe card number 5 is Rooting for the underdog has a cost of 3 and is type Keep\nThe card number 6 is Skycraper has a cost of 6 and is type Discard\n";
	cout << "\n" <<"21.- esperada " << ans << "\n programa " << m.printCards(aux) << "\n";
  cout <<	(!ans.compare(m.printCards(aux)) ? "success\n" : "fail\n");

  cout<<"Casos de prueba stack \n";
  m.sortById(cards);
  Stack<Card> mystack;
  for(int i=10;i<20;i++){
    mystack.add(*cards[i]);
  }
  string temp=mystack.pop().print();
  ans="The card number 20 is Detritivore has a cost of 4 and is type Keep\n";
	cout << "\n" <<"22.- esperada " << ans << "\n programa " << temp << "\n";
  cout <<	(!ans.compare(temp) ? "success\n" : "fail\n");

  mystack.add(carta1);
  temp=mystack.pop().print();
  ans="The card number 6 is Skycraper has a cost of 6 and is type Discard\n";
	cout << "\n" <<"23.- esperada " << ans << "\n programa " << temp << "\n";
  cout <<	(!ans.compare(temp) ? "success\n" : "fail\n");
  
  temp=mystack.vaciar();
  ans="The card number 19 is Energy hoader has a cost of 3 and is type Keep\nThe card number 18 is Herbivore has a cost of 5 and is type Keep\nThe card number 17 is Oportunist has a cost of 3 and is type Keep\nThe card number 16 is Gourmet has a cost of 4 and is type Keep\nThe card number 15 is Acid attack has a cost of 6 and is type Keep\nThe card number 14 is It has a child has a cost of 7 and is type Keep\nThe card number 13 is Fire breathing has a cost of 4 and is type Keep\nThe card number 12 is Psychic probe has a cost of 3 and is type Keep\nThe card number 11 is Tank has a cost of 4 and is type Discard\n";	
  cout << "\n" <<"24.- esperada " << ans << "\n programa " << temp << "\n";
  cout <<	(!ans.compare(temp) ? "success\n" : "fail\n");

  cout<<"Casos de prueba BST \n";
  m.shuffle(aux);
  BST<Card> tree(aux);
  cout<<tree.print();
  ans="[\n1-Alpha Monster with cost 5\n2-Frenezy with cost 7\n3-Apartament building with cost 5\n4-Nova Breath with cost 7\n5-Rooting for the underdog with cost 3\n6-Skycraper with cost 6\n7-Corner store with cost 3\n8-Friend of childre with cost 3\n9-Extra head with cost 7\n10-Background dweller with cost 4]";
  cout << "\n" <<"25.- esperada " << ans << "\n programa " << tree.print() << "\n";
  cout <<	(!ans.compare(tree.print()) ? "success\n" : "fail\n");

  tree.add(*cards[15]);
  tree.add(*cards[18]);

  ans="[\n1-Alpha Monster with cost 5\n2-Frenezy with cost 7\n3-Apartament building with cost 5\n4-Nova Breath with cost 7\n5-Rooting for the underdog with cost 3\n6-Skycraper with cost 6\n7-Corner store with cost 3\n8-Friend of childre with cost 3\n9-Extra head with cost 7\n10-Background dweller with cost 4\n16-Gourmet with cost 4\n19-Energy hoader with cost 3]";
  cout << "\n" <<"26.- esperada " << ans << "\n programa " << tree.print() << "\n";
  cout <<	(!ans.compare(tree.print()) ? "success\n" : "fail\n");

  tree.remove(carta1);
  tree.remove(*cards[18]);
  ans="[\n1-Alpha Monster with cost 5\n2-Frenezy with cost 7\n3-Apartament building with cost 5\n4-Nova Breath with cost 7\n5-Rooting for the underdog with cost 3\n7-Corner store with cost 3\n8-Friend of childre with cost 3\n9-Extra head with cost 7\n10-Background dweller with cost 4\n16-Gourmet with cost 4]";
  cout << "\n" <<"26.- esperada " << ans << "\n programa " << tree.print() << "\n";
  cout <<	(!ans.compare(tree.print()) ? "success\n" : "fail\n");


  cout<<"Para comprobar las funciones shuffle y save, las correremos juntas al final y esto resultará en un cambio de orden en todas las cartas que se reflejará en el csv cada vez que se corran estos casos de prueba \n";
  m.shuffle(cards);
  m.save(cards);


}
