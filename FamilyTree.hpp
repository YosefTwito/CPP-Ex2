#pragma once
#include <string>
#include <iostream>

using namespace std;

namespace family{
	class Tree {
	public:
		string name;
		Tree *f, *m, *s;
		string rel;

	public:

		Tree(string s):
			name(s),f(nullptr),m(nullptr),s(nullptr), rel("me"){};

		~Tree(){
                  if(m) delete m;
                  if(f) delete f;
                  //cout << "destruct -> " << this->name << endl;
		};

		Tree &addFather(string name, string father);
		Tree &addMother(string name, string mother);

		void display();
		void remove(string s);

		string relation(string s);
		string find(string s);
	};
};
