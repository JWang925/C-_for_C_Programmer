//This work is a practice of class inheritance/virtual function/abstract base function

//This work builds a tree to evaluate Polish Notation


#include<iostream>
#include"tree.h"
int main() {

	int valtab[127];
	valtab['A'] = 3; valtab['B'] = 4; //'A' is converted to a number using ASCII Codes

	Tree t1 = Tree("*", Tree(("-", 5), Tree("+", 'A', 4)));



	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
	return 0;
}