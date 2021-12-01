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

void welcome(){
  cout<<"Bienvenido. En este programa podrás manejar las cartas del poderosisimo juego de King of Tokyo"<<endl;
  cout<<"Carga algunas cartas para empezar"<<endl;
  cout<<"¿Qué quieres hacer?"<<endl;
}
void menu(){
  cout<<"0-Terminar programa"<<endl;
  cout<<"1-Cargar el deck del csv. 24 cartas registradas"<<endl;
  cout<<"2-Carga parcial. 15 cartas."<<endl;
}

void menu2(){
  cout<<"0-Terminar programa"<<endl;
  cout<<"1-Cargar las primeras 15 cartas ordenadas por ID"<<endl;
  cout<<"2-Cargar las primeras 15 cartas ordenadas por nombre"<<endl;
  cout<<"3-Cargar las primeras 15 cartas ordenadas por costo"<<endl;
}

void menu3(){
  cout<<"0-Terminar programa"<<endl;
  cout<<"1-Mezclar"<<endl;
  cout<<"2-Mostrar"<<endl;
  cout<<"3-Comprueba que tu carta está en el deck.(Busqueda por ID)"<<endl;
  cout<<"4-Añadir carta"<<endl;
  cout<<"5-Hacer del maso actual un stack"<<endl;
  cout<<"6-Guardar cambios en el csv. El maso actual sobreescribe el csv"<<endl;

}

Card createCard(){
  string name,des,type;
  int cost,id;
  cout<<"Ingresa el ID. Ingresa a partir del 30 para asegurar que no se repitan";
  cin>>id;
  cout<<"Ingresa el nombre";
  cin>>name;
  cout<<"Ingresa el costo";
  cin>>cost;
  cout<<"Ingresa el tipo Keep/Discard";
  cin>>type;
  cout<<"Ingresa la descripción";
  cin>>des;
  Card c(id,name,cost,type,des);
  cout<<"Tu carta creada es\n"<<c.print();
  return c;
}

int error(){
  cout<<"Opción inválida"<<endl;
  return 0;
}

int main() {
  Manage m;
  int op;
  vector<Card*> cards;
  vector<Card*> mycards;
  welcome();
  cout<<"Si deseas restaurar csv original presiona 1 si no presiona otro numero"<<endl;
  cin>>op;
  if(op==1){
    m.restoreCSV();
  }
  do{
    cards=m.getCards();
    mycards.clear();
    menu();
    cout<<"Escoge una opción "<<endl;
    cin>>op;
    if(op==1){
      mycards=cards;
    }
    else if(op==2){
      cout<<"Escoge una opción "<<endl;
      menu2();
      cin>>op;
      if(op==1){
        m.sortById(cards);
      }
      else if(op==2){
        m.sortByName(cards);
      }
      else if(op==3){
        m.sortByCost(cards);
      }
      else{
        op=error();
      }
      if(op!=0){
        for(int i=0;i<15;i++){
        mycards.push_back(cards[i]);
        }
      }
    }
    cout<<"¿Qué quieres hacer con tus cartas?"<<endl;
    do{
      menu3();
      cin>>op;
      if(op==1){
        m.shuffle(mycards);
        cout<<"Tus cartas han sido mezcladas"<<endl;
      }
      else if(op==2){
        cout<<"Tus cartas son: "<<endl;
        string a=m.printCards(mycards);
        cout<<m.printCards(mycards);
      }
      else if(op==3 || op==4 || op==5){
      BST<Card> tree(mycards);
      Card f(0,"",0,"","");
      if(op==3){
        int x;
        cout<<"Ingresa el ID que deseas buscar"<<endl;
        cin>>x;
        f=*cards[x-1];
        if(tree.find(f)){
          cout<<"Carta encontrada"<<endl;
        }
        else{
          cout<<"Carta no encontrada"<<endl;
        }
      }
      else if(op==4){
        f=createCard();
        tree.add(f);
      }
      else if(op==5){
      Stack<Card> mystack(mycards);
        do{
          cout<<"0-Salir"<<endl;
          cout<<"1-Sacar la carta de arriba"<<endl;
          cout<<"2-Vaciar Stack"<<endl;
          cout<<"Elige una opción"<<endl;
          cin>>op;
          if(op==1){
            cout<<"La carta que sacaste es "<<mystack.pop().print();
          }
          else if(op==2){
            cout<<"Vaciar stack:"<<endl;
            cout<<mystack.vaciar();
            cout<<"Stack vacio"<<endl;
          }
          else{
            op=error();
          }
        }while(op!=0 && !mystack.empty());
      }
     }
      else if(op==6){
        m.save(mycards);
      }
      else{
        op=error();
      }
    }while(op!=0);
  }while(op!=0);
  cout<<"Programa finalizado"<<endl;
}