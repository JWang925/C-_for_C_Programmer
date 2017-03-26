#pragma once
class Node {
	friend class Tree; //Node is a kissing-cousin with Tree;
	friend std::ostream& operator<<(std::ostream&, const Tree&);
	int use;
protected:
	Node() { use = 1; }; //constructor, initialize the node used by 1
	virtual void print(std::ostream&)=0; //pure virtual declaration
	virtual ~Node() {}; //pure virtual destructor
	virtual int eval() = 0; //pure virtual delcaration, to be overwritten
};

class Tree {
	friend class Node; //kissing cousin with Node;
	friend std::ostream& operator<<(std::ostream&, const Tree&); //ostream overload
	Node* p; //polymorphic hierarchy
public:
	Tree(int); // constructor
	Tree(char); // constructor
	Tree(char*, Tree); //unary op
	Tree(char*, Tree, Tree); // binary op
	Tree(const Tree& t) { p = t.p; ++p->use; }
	~Tree() { if (--p->use == 0) delete p; };
	void operator=(const Tree& t);
	int eval() { return p->eval(); }
}
};

