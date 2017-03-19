//use of enum class
//use of STL function: random_shuffle for C++11
//use of friend function and bit-shift operator overloading

#include <iostream>
#include <cassert> //assert()
#include <vector> //for vectors
#include <time.h> //to initialize srand()
#include <algorithm> // for random_shuffle
using namespace std;


//??? Should I put these lines into a header file?? If so, why?
enum class suit :short { SPADE, HEART, DIAMOND, CLUB }; //a enum class is a scoped enumeration

ostream& operator << (ostream& out, const suit& s) { // << overload for suit
	switch (s) {
	case suit::SPADE: out << "s"; break;
	case suit::HEART: out << "h"; break;
	case suit::DIAMOND: out << "d"; break;
	case suit::CLUB: out << "c"; break;
	}
		return out;
}

//class pips { //value of the card
//public:
//	pips(int val) :v(val) { assert(v > 0 && v < 14); } //constructor
//	friend ostream& operator << (ostream& out, const pips& p) { out << p.v; return out; } //overload for <<
//	int get_pips() { return v; } //get private data
//private:
//	int v; //value of the card
//};

enum class pips :short {ACE=1,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING}; //a enum class is a scoped enumeration

ostream& operator << (ostream& out, const pips& p) { // << overload for suit
	switch (p) {
	case pips::ACE: out << "A"; break;
	case pips::KING: out << "K"; break;
	case pips::QUEEN: out << "Q"; break;
	case pips::JACK: out << "J"; break;
	case pips::TEN: out << "T"; break;
	case pips::NINE: out << "9"; break;
	case pips::EIGHT: out << "8"; break;
	case pips::SEVEN: out << "7"; break;
	case pips::SIX: out << "6"; break;
	case pips::FIVE: out << "5"; break;
	case pips::FOUR: out << "4"; break;
	case pips::THREE: out << "3"; break;
	case pips::TWO: out << "2"; break;
	}
	return out;
}

class card {
public:
	card() {};
	card(suit s, pips v) :s(s), v(v) {};
	card(pips v, suit s) :s(s), v(v) {};
	friend ostream& operator << (ostream& out, const card c) { out << c.v << c.s << ' '; return out; }
	pips get_pips() { return v; }
	suit get_suit() { return s; }
private:
	suit s;
	pips v;
};

void init_deck(vector<card> &d) {
	for (int i = 1; i < 14; ++i) {
		card c1(suit::SPADE, pips(i)); d[i - 1] = c1;
		card c2(suit::HEART, pips(i)); d[i + 12] = c2;
		card c3(suit::DIAMOND, pips(i)); d[i + 25] = c3;
		card c4(suit::CLUB, pips(i)); d[i + 38] = c4;
	}
};

void print(vector<card>& deck) {
	for (auto it = deck.begin(); it != deck.end(); ++it)
		cout << *it;
	cout << endl;
}

//Identify if this is a flush
bool is_straight(vector<card>&hand) {
	int pips_v[5], i = 0;
	for (auto p = hand.begin(); p != hand.end(); ++p)
		pips_v[i++] = int (p->get_pips()); //use a cast to cast from enum class to int

	//for (i = 0; i < 5;i++) 
	//	cout << pips_v[i] << '\t';

	sort(begin(pips_v),end(pips_v));
	if (pips_v[0] != 1) 
		return (pips_v[0] == (pips_v[1] - 1)) && (pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1) && (pips_v[3] == pips_v[4] - 1);
	else 
		return (pips_v[0] == (pips_v[1] + 4)) && (pips_v[1] == pips_v[2] - 1) && (pips_v[2] == pips_v[3] - 1) && (pips_v[3] == pips_v[4] - 1); 
}

bool is_flush(vector<card>&hand) {
	suit s = hand[0].get_suit();
	for (auto it = hand.begin()+1; it != hand.end(); ++it)
		if (s != it->get_suit()) return false;
	return true;
}

int main() {
	//initialize a deck of cards, a deck of cards is a "vector" of cards
	vector<card> deck(52); //size 52
	init_deck(deck);
	srand(time(0));

	while (1) {
	random_shuffle(deck.begin(),deck.end());
	//print(deck);
	vector <card> hand(5); //To store the five-card hand
	int i = 0;
	for (auto p = deck.begin(); i < 5; ++p) hand[i++] = *p;
	print(hand);
	if (is_straight(hand))
		cout << "is_straight " << endl;
	if(is_flush(hand))
		cout << "is_flush" << endl;
	}

	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();
	return 0;
}