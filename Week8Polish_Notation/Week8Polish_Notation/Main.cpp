//This work is a practice of class inheritance/virtual function/abstract base function

//This work builds a tree to evaluate Polish Notation


//global variables
int valtab[127];


#include<iostream>
#include"tree.h"


int main() {
	valtab['A'] = 3; valtab['B'] = 4; //'A' is converted to a number using ASCII Codes

	Tree t1 = Tree("*", Tree("-", 5), Tree("+", 'A', 4));
	std::cout << "t1=" << t1 << std::endl;
	std::cout << "t1:" << t1.eval() << std::endl;


	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();
	return 0;
}