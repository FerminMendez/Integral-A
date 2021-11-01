#ifndef BST_H
#define BST_H
//Fermín Méndez A01703366
//Libraries
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
////////Arbol BST
template<class T> class BST;
//Nodo
template<class T>
class Node{
    private:
        T value;
        Node<T>* left;
        Node<T>* right;

    //
    public:
        //Node constructors
        Node(T);
        Node(T,Node<T>*,Node<T>*);
        //Methods
        void add(T);
        bool find(T);
        void removeChilds();
        //orders
        void preorder(std::stringstream&) const;
        void inorder(std::stringstream&) const;
        void postorder(std::stringstream&) const;
        void levelbylevel(std::stringstream*);

        void getCards(std::vector<T*>&);

    friend class BST<T>;
};
//Constructors
template<class T>
Node<T>::Node(T val):value(val),right(0),left(0){}

template<class T>
Node<T>::Node(T val,Node<T>* le,Node<T>* ri):value(val),left(le),right(ri){}

//Methods
template<class T>
void Node<T>::add(T val){
    if(val < value){
        if(left==0){
            left=new Node(val);
        }
        else{
            left->add(val);
        }
    }
    else if(val>value){
        if(right==0){
            right=new Node(val);
        }
        else{
            right->add(val);
        }
    }
}

template <class T>
bool Node<T>::find(T val){
    if(value==val){
        return true;
    }
    else if(val>value){
        if(right==0){
            return false;
        }
        return right->find(val);
    }
    else if(val<value){
        if(left==0){
            return false;
        }
        return left->find(val);
    }
    return false;
}

template <class T>
void Node<T>::removeChilds() {
	if (left != 0) {
		left->removeChilds();
		delete left;
		left = 0;
	}
	if (right != 0) {
		right->removeChilds();
		delete right;
		right = 0;
	}
}

//Orders
template <class T>
void Node<T>::preorder(std::stringstream &aux) const{
    std::string s=value.showVal();
    aux<<s;//Dar a value un valor de string
    if(left!=0){
        aux<<" ";
        left->preorder(aux);
    }
    if(right!=0){
        aux<<" ";
        right->preorder(aux);
    }
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const{
    if(left!=0){
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
	}
	    aux << "\n";
    std::string s=value.showVal();
    aux<<s;
    if(right!=0){
        right->inorder(aux);
    }
}

template <class T>
void Node<T>::postorder(std::stringstream &aux) const{
    if(left!=0){
        left->postorder(aux);
    }
    if(right!=0){
        right->postorder(aux);
    }
    if (aux.tellp() != 1) {
	    aux << " ";
	}
    std::string s=value.showVal();
    aux<<s;
}

template <class T>
void Node<T>::levelbylevel(std::stringstream *ptr){
    if (ptr->tellp() != 0) {
	    *ptr << " ";
	}
    std::string s=value.showVal();
    *(ptr)<<s;
    if(left!=0){
        left->levelbylevel(ptr+1);
    }
    if(right!=0){
        right->levelbylevel(ptr+1);
    }

}

template <class T>
 void Node<T>::getCards(std::vector<T*> &aux){
      if(left!=0){
        left->getCards(aux);
    }
    aux.push_back(&value);
    if(right!=0){
        right->getCards(aux);
    }
 }
 
//BST implementation
template<class T> 
class BST{
    private:
        Node<T> *root;
    
    public:
        //BST Constructors and destructor
        BST();
        BST(std::vector<T*>&);
        ~BST();
        //Mehtods
        bool is_empty();
        void add(T);
        bool find(T);
        void clearAll();
        //Tarea
        std::string visit();
        std::string print();
        int height();
        std::string ancestors(T);
        T whatlevelamI(T);

        //Orders
        std::string preorder();
        std::string inorder();
        std::string postorder();
        std::string levelbylevel();

        std::vector<T*> getCards();

};
//BST Constructors and destructor
template <class T>
BST<T>::BST() :root(0){}

template <class T>
BST<T>::BST(std::vector<T*> &source){
    root=0;
     for (int i = 0; i < source.size(); i++){
	  T val=*source[i];
    add(val);
    }

}

template <class T>
BST<T>::~BST(){
    clearAll();
}

//BST Methods
template <class T>
bool BST<T>::is_empty(){
    if(root==0){
        return true;
    }
    else{
        return false;
    }
}

template <class T>
void BST<T>::add(T val){
    if(is_empty()){
        root=new Node<T>(val);
    }
    else{
        root->add(val);
    }
}

template <class T>
bool BST<T>::find(T val){
    if(!is_empty()){
        return root->find(val);
    }
    return false;
}

template <class T>
void BST<T>::clearAll(){
    if(!is_empty()){
        root->removeChilds();
    }
    delete (root);
    root=0;
}

//Tarea


template <class T>
std::string BST<T>::visit(){
    return preorder()+"\n"+inorder()+"\n"+postorder()+"\n"+levelbylevel();
}


template <class T>
T BST<T>::whatlevelamI(T val){
    if(is_empty() || !find(val)){
        return -1;
    }
    return root->findlevel(val,0);
}

//Orders
template <class T> 
std::string BST<T>::preorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string BST<T>::inorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string BST<T>::postorder(){
    std::stringstream aux;
    	aux << "[";
	if (!is_empty()) {
		root->postorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T> 
std::string BST<T>::levelbylevel(){
    std::stringstream aux;
    aux << "[";
    if(is_empty()){
        aux<<"]";
        return aux.str();
    }

    int h=height();
    std::stringstream array[h];
    std::stringstream *ptr;
    ptr=array;
    root->levelbylevel(ptr);

    //////////////////////////////////////
        for (int i=0;i<h;i++){
            if (aux.tellp() != 1) {
                aux << " ";
            }
            aux<<(ptr+i)->str();
        }
	    aux << "]";       
	return aux.str();
}

template <class T>
std::string BST<T>::print(){
   return inorder();
}

template <class T>
std::vector<T*> BST<T>::getCards(){
    std::vector<T*> aux;
	if (!is_empty()) {
		root->getCards(aux);
	}
	return aux;
}
#endif