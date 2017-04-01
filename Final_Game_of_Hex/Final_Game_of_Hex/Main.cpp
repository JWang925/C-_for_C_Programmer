//

#include <iostream>
#include "hexGraph.h"
#include "hexPlayer.h"
#include <fstream>
#include <string>
using namespace std;

int main() {
	srand(time(nullptr)); //seed the random number generator
	int awin = 0; int bwin = 0; //running winning count
	int ngame = pow(10, 2); //total game count
	int boardsize;
	int nsimul; //number of MC simulation performed for the AI
	ifstream myfile;
	string dummy;
	myfile.open("settings.dat");
	if (myfile.is_open()) {
		myfile >> dummy;
		myfile >> boardsize;
		myfile >> dummy;
		myfile >> nsimul;

		myfile.close();
	}
	else std::cout << "Unable to open file";


	clock_t begin = clock();  //to time the game session time


	cout << "HEX GAME version 1.0 \n Board size =" << boardsize <<"\n" << endl;
	cout << "Would like to play the game or watch?(Y/N)" << endl;
	char temp;  cin >> temp;
	bool if_Human_Plays;
	switch (temp) {
	case 'Y': 
		if_Human_Plays = 1; 
		cout << "Welcome, Human Player" << endl;
		break;
	case 'N': 
		if_Human_Plays = 0;
		break;
	default: 
		cerr << "Invalid input, exiting program"; return 1;
	}

	for (int igame = 0; igame < ngame; igame++) { //each loop is one game
		hexGraph graph(boardsize); //game setup
		//graph.print();
		int i, j, temp;
		while (1) { //game running
			if (if_Human_Plays) {
				graph.print();
				cout << "Please input your stone coordinates in the format of 'x y' " << endl;
				cin >> i; cin >> j;
				//should check if it is a valid input
				temp = graph.place_bit(i, j, 1);
			}
			else {
				tie(i, j) = HexPlayer(graph, 1, Random);
				temp = graph.place_bit(i, j, 1);
			}

			if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); } //need to catch this exception later
			if (graph.is_winner(1)) { awin++; cout << "You win! Game is restaring!" <<endl; break; }

			tie(i, j) = HexPlayer(graph, 2, MC,nsimul);
			temp = graph.place_bit(i, j, 2);
			if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); }
			if (graph.is_winner(2)) { bwin++; cout << "You lose!"; break; }
		}
	}


	clock_t end = clock();
	cout << "elapsed time:" << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
	cout << "speed per game: " << double(end - begin) / CLOCKS_PER_SEC / ngame * 1000 * 1000 << "micro_second" << std::endl;

	cout << "A wins " << awin << " games whereas B wins " << bwin << "games" << endl;



	//end of code
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

	return 0;
}