//use of enum class
//use of STL function: random_shuffle for C++11
//use of friend function and bit-shift operator overloading

#include <iostream>
#include <cassert> //assert()

using namespace std;

enum class suit :short {SPADE,HEART,DIAMOND,CLUB};

class pips {
public:
	pips(int val) :v(val) { assert(v > 0 && v < 14); } //constructor
	friend ostream& operator << (ostream& out, const pips& p) { cout << *p; }
	int get_pips() { return v; }
private:
	int v; //value of the card
};


int main() {

	pips card(2);

	cout << card;


	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}

