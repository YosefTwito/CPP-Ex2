#include "FamilyTree.hpp"
#include <iostream>
using namespace std;
using namespace family;

Tree* getNode (Tree* ptr, string s){ //Done - Gotta test cases and Exceptions
	if (ptr->name==s) { return ptr; }
	if (ptr->f!=nullptr){ return getNode(ptr->f, s); }
	if (ptr->m!=nullptr){ return getNode(ptr->m, s); }
	throw "No such name in the tree";
}

Tree &Tree::addFather(string name, string father){ //Done - Gotta test cases and Exceptions
	Tree* ptr = getNode(this, name);
	if (ptr != nullptr) {
            if (ptr->f == nullptr){
                  ptr->f = new Tree(father);
                  ptr->f->s = ptr;
                  return *ptr;
            }
            else {
                  throw "This member already has a father !";
            }
	}
	else{
		throw "Could not find the...";
	}
}

Tree &Tree::addMother(string name, string mother) { //Done - Gotta test cases and Exceptions
	Tree* ptr = getNode(this, name);
	if (ptr != nullptr) {
            if (ptr->m == nullptr){
                  ptr->m = new Tree(mother);
                  ptr->m->s = ptr;
                  return *ptr;
            }
		else {
                  throw "This member already has a mother !";
		}
	}
	else{
		throw "Could not find the...";
	}
}

/** Got this function to print the tree from :
* https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
*
* Function to print the tree in 2D
* It does reverse inorder traversal
**/
void print2D(Tree *root, int space){
      if (root == NULL) return;//Base case
      space += 10;// Increase distance between levels

      print2D(root->f, space);// Process father node
      cout<<endl;// Print current node after space
      for (int i = 10; i < space; i++){ cout<<" "; }
      cout<<root->name<<"\n";
      print2D(root->m, space);// Process mother node
}
//
void Tree::display() { // Done !
      cout << "Display Tree:\n--------------------------------------------------------------" ;
      print2D(this, 0);
      cout << "--------------------------------------------------------------" << endl;
}

string Tree::relation(string s) {

	return "unrelated";
}

string Tree::find(string s) {

	return "uu";
}

void Tree::remove(string s) { // Done - Gotta see about remove for the root !!!!!!!!!
	Tree* ptr = getNode(this, s);
	if (ptr->s->m == ptr){ ptr->s->m = nullptr; }
	if (ptr->s->f == ptr){ ptr->s->f = nullptr; }
      delete ptr;
}
