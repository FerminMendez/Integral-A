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
  Card carta1(1, "Carta 1",8,"Keep", "Gain 8 stars");

  string in_ans = "", pre_ans = "";
  SplayTree<int> my_splay;
  bool found = 0;

  my_splay.add(15);
  in_ans =	"[15]";

	cout << "\n" <<"1.- esperada " << in_ans << "\n programa " << my_splay.inorder() << "\n";
  cout <<	(!in_ans.compare(my_splay.inorder()) ? "success\n" : "fail\n");

  my_splay.add(10);
  my_splay.add(17);
  my_splay.add(7);
  my_splay.add(13);
  my_splay.add(16);
  in_ans =	"[7 10 13 15 16 17]";
  pre_ans =	"[16 13 7 10 15 17]";

}
