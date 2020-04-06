#include "FamilyTree.hpp"
#include <iostream>
#include <exception>

using namespace std;
using namespace family;

Tree* getNode (Tree* ptr, string str){ //Done - Gotta test cases and Exceptions
	if (ptr->name==str) { return ptr; }
	if (ptr->f!=nullptr){
        Tree* ans = getNode(ptr->f, str);
        if(ans != nullptr)
            return ans;
    }
	if (ptr->m!=nullptr){
        Tree* ans = getNode(ptr->m, str);
        if(ans != nullptr)
            return ans;
    }
	return nullptr;
}

Tree &Tree::addFather(string name, string father){ //Done - Gotta test cases and Exceptions
	Tree* ptr = getNode(this, name);
	if (ptr != nullptr) {
            if (ptr->f == nullptr){
                  ptr->f = new Tree(father);
                  ptr->f->s = ptr;
                  //if's for the relation
                  if (ptr->rel == "me") ptr->f->rel = "father";
                  else if (ptr->rel == "father") ptr->f->rel = "grandfather";
                  else if (ptr->rel == "mother") ptr->f->rel = "grandfather";
                  else if (ptr->rel == "grandfather") ptr->f->rel = "great-grandfather";
                  else if (ptr->rel == "grandmother") ptr->f->rel = "great-grandfather";
                  else{
                       string temp = "great-"+ptr->rel;
                       for (int j=0; j<6; j++) temp.pop_back();
                       temp+="father";
                       ptr->f->rel = temp;
                  }
                  return *ptr;
            }
            else {
                  throw "This member already has a father !";
            }
	}
	else{ throw runtime_error(name+" is not in the tree"); }
}

Tree &Tree::addMother(string name, string mother) { //Done - Gotta test cases and Exceptions
	Tree* ptr = getNode(this, name);
	if (ptr != nullptr) {
            if (ptr->m == nullptr){
                  ptr->m = new Tree(mother);
                  ptr->m->s = ptr;
                  //if's for the relation
                  if (ptr->rel == "me") ptr->m->rel = "mother";
                  else if (ptr->rel == "mother") ptr->m->rel = "grandmother";
                  else if (ptr->rel == "father") ptr->m->rel = "grandmother";
                  else if (ptr->rel == "grandmother") ptr->m->rel = "great-grandmother";
                  else if (ptr->rel == "grandfather") ptr->m->rel = "great-grandmother";
                  else{
                        string temp = "great-"+ptr->rel;
                        for (int j=0; j<6; j++) temp.pop_back();
                        temp+="mother";
                        ptr->m->rel = temp;
                  }
                  return *ptr;
            }
		else {
                  throw "This member already has a mother !";
		}
	}
	else{ throw runtime_error(name+" is not in the tree"); }
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
      cout << "Display Tree:\n--------------------------------------------------------------";
      print2D(this, 0);
      cout << "--------------------------------------------------------------" << endl;
}

string Tree::relation(string str) {
      Tree* ptr = getNode(this, str);
      if (ptr != nullptr) return ptr->rel;
      return "unrelated";
}

Tree* findRecursive(Tree* ptr, string str){
      if (ptr->rel==str) { return ptr; }
      if (ptr->f!=nullptr){
            Tree* ans = findRecursive(ptr->f, str);
            if(ans != nullptr)
            return ans;
      }
      if (ptr->m!=nullptr){
            Tree* ans = findRecursive(ptr->m, str);
            if(ans != nullptr)
            return ans;
      }
      return nullptr;
}

string Tree::find(string str) {
      Tree* ptr = findRecursive(this, str);
      if (ptr != nullptr){ return ptr->name; }
	else{ throw runtime_error(str+" is not in the tree"); }
}

void Tree::remove(string str) { // Done - Gotta see about remove for the root !!!!!!!!!
	Tree* ptr = getNode(this, str);
	if(ptr!=nullptr){
            if (ptr->s->m == ptr){ ptr->s->m = nullptr; }
            if (ptr->s->f == ptr){ ptr->s->f = nullptr; }
            delete ptr;
      }
      else { throw runtime_error(str+" is not in the tree"); }
}