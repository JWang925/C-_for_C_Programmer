#pragma once
#include<iostream>

extern int valtab[];

class Node {
	friend class Tree; //Node is a kissing-cousin with Tree;
	friend std::ostream& operator<<(std::ostream&, const Tree&);
	int use;
protected:
	Node() { use = 1; }; //default constructor, initialize the node used by 1
	virtual void print(std::ostream&)=0; //pure virtual declaration
	virtual ~Node() {}; //pure virtual destructor
	virtual int eval() = 0; //pure virtual delcaration, to be overwritten
};

class Tree {
	friend class Node; //kissing cousin with Node;
	Node* p; //polymorphic hierarchy
public:
	Tree(int n); // constructor with int input, add 1 to usage.
	Tree(char id); // constructor with char input, add 1 to usage.
	Tree(char* op, Tree opnd); //unary op defination
	Tree(char* op, Tree left, Tree right) ; // binary operator definition
	Tree(const Tree& t) { p = t.p; ++p->use; } //a shallow copy constrcutor
	~Tree() { if (--p->use == 0) delete p; }; //delete the item that the pointer is pointing to

	friend std::ostream& operator<<(std::ostream& out, const Tree& t) { t.p->print(out); return out; }; //overload for <<
	void operator=(const Tree& t) { p = t.p; ++p->use; };  //shallow, equal operation. add use by 1!

	int eval() { return p->eval(); }
};


//Leaf Node
class LeafNode :public Node {
	friend class Tree; //can this be removed?
	void print(std::ostream& ) = 0; //still pure virtual;
	virtual int eval() = 0; //still pure virtual;
};


//Integer Node, print and eval are both defined here
class IntNode : public LeafNode {  //members are private by default
	friend class Tree;
	int n;
	void print(std::ostream& out) { out << n; }
	IntNode(int k) :n(k) {}; //constructor
public:
	int eval() { return n; }
};

//Variable Node
class IdNode : public LeafNode {  //members are private by default
	friend class Tree;
	char name;
	void print(std::ostream& out) { out << name; }
	IdNode(char id) :name(id) {}; //constructor
public:
	int eval() { return valtab[name]; }
};

//Unary Node
class UnaryNode : public Node { //members are private by default
	friend class Tree;
	char* op;
	Tree opnd;
	UnaryNode(char* a, Tree b) :op(a), opnd(b) {} //constructor
	void print(std::ostream& out) { out << "(" << op << opnd << ")"; }
public:
	int eval() {
			switch (op[0]) {
			case '-': return (-opnd.eval());
			case '+': return (+opnd.eval());
			default: std::cerr << "no operand\n" << std::endl;
				return 0;
			}
	};
};

//Binary Operator Node
class BinaryNode : public Node {
	friend class Tree;
	char* op; // + - * / %
	Tree left;
	Tree right;
	BinaryNode(char* a, Tree b, Tree c) :op(a), left(b), right(c) {}; //constructor
	void print(std::ostream& out) { out << "(" << left << op << right << ")"; }
public:
	int eval() {
		switch (op[0]) {
		case '-': return(left.eval() - right.eval());
		case '+': return(left.eval() + right.eval());
		case '*': return(left.eval() * right.eval());
		default: std::cerr << "no operand \n" << std::endl;
			return 0;
		}
	};
};


