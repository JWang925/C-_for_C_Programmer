#include <iostream>
using namespace std;
#include "route.h"

//create a class called route, which has a boolean stating whether this route exists, and an double variable showing the distance if the route exists

	double route::get_dist() { return distance; }
	bool route::ifconnect() { return is_connect; }
	void route::set_connect(bool x) { is_connect = x; }
	void route::set_distance(double x) { distance = x; }

	route::route(bool x, double y):is_connect(x), distance(y) {}; //constructor //default value either exist in header file(declaration) or cpp file(definition).

	route::~route() { //destructor, use to delete items created on the heap
		cout << "destructor called" << endl;  //No need to delete any variables since nothing is defined on the heap
	}
