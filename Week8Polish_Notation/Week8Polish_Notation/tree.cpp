#include "tree.h"

Tree::Tree(int n) {p = new IntNode(n);}
Tree::Tree(char id) { p = new IdNode(id); }
Tree::Tree(char* op, Tree opnd) { p = new UnaryNode(op, opnd); }
Tree::Tree(char* op, Tree left, Tree right) { p = new BinaryNode(op, left, right); }