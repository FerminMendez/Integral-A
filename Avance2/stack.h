//estructura lineal para acceder al deck. Con esto podemos estar tomando la carta superior.


#ifndef STACK
#define STACK

#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <class T> class Stack;

template <class T>
class Link {
private:
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value;
	Link<T> *next;

	friend class Stack<T>;
};

/***Funciones Link***/

template <class T>
Link<T>::Link(T val) : value(val), next(0) {}

template <class T>
Link<T>::Link(T val, Link* nxt) : value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source) : value(source.value), next(source.next) {}

/**Inicio clase Stack**/

template <class T>

class Stack {

public:

    Stack();
    Stack(vector<T*>);
	~Stack();

	string toString() const;

	void addfirst(T);
	void deletefirst();

private:

    Link<T> *head;
    int size;

};

/**Constructores**/

template <class T>
Stack<T>::Stack() : head(0), size(0) {}

template <class T>
Stack<T>::Stack(vector<T*> source){
  size=source.size();
  for (int i = 0; i < size; i++) {
    T value=*source[i];
    addfirst(value);
    }
}


template <class T>
Stack<T>::~Stack() {
	Link<T> *p, *q;
	p = head;
	while (p != 0) {
		q = p->next;
		delete p;
		p = q;
	}
	head = 0;
	size = 0;
}




template <class T>
string Stack<T>::toString() const {
	stringstream aux;
	Link<T> *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->value;
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}
#endif