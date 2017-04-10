//

#include <iostream>
#include "hexGraph.h"
#include "hexPlayer.h"
#include <fstream>
#include <string>

int main() {
	srand(time(nullptr)); //seed the random number generator
	int awin = 0; int bwin = 0; //running winning count
	int ngame = pow(10, 1); //total game count
	int boardsize;
	int nsimul; //number of MC simulation performed for the AI
	std::ifstream myfile;
	std::string dummy;
	myfile.open("settings.dat");
	if (myfile.is_open()) {
		myfile >> dummy;
		myfile >> boardsize;
		myfile >> dummy;
		myfile >> nsimul;

		myfile.close();
	}
	else {
		std::cout << "Unable to open file" << std::endl;
		std::cout << "please check if settings.dat exists" << std::endl;
		std::cin.get();
	}


	clock_t begin = clock();  //to time the game session time
	std::cout << "HEX GAME version 1.0 \nBoard size =" << boardsize <<"\n" << std::endl;
	std::cout << "The goal of the game is for you (player 1) to form a continuous route from top to bottom of the map; The goal of the AI is to form a route from left to right" << std::endl;
	std::cout << "Each position is connected with the six surrounding positions (thus the name: HEX)"<< std::endl;
	std::cout << "Would like to play the game or watch some random game?(Y/N)" << std::endl;
	char temp;  
	std::cin >> temp;
	bool if_Human_Plays;
	switch (temp) {
	case 'Y': 
		if_Human_Plays = 1; 
		std::cout << "Welcome, Human Player" << std::endl;
		break;
	case 'N': 
		if_Human_Plays = 0;
		break;
	default: 
		std::cerr << "Invalid input, exiting program"; return 1;
	}
	system("CLS"); //clear the output

	for (int igame = 0; igame < ngame; igame++) { //each loop is one game
		hexGraph graph(boardsize); //game setup

		int i, j, temp;
		while (1) { //game running
			if (if_Human_Plays) { //if human is playing, input the move
				bool is_successful=0;
				while (!is_successful) { //loop until a stone is successfully occupied.
					graph.print();
					std::cout << "Please input your stone coordinates in the format of 'x y' " << std::endl;
					std::cin >> i; std::cin >> j;
					temp = graph.place_bit(i, j, 1); //temp = 0 if place_bit is executed correctly, if not it returns 1
					if (temp == 0) is_successful = 1;
				}
			}
			else { // if human is watching, input a random move
				graph.print();
				std::tie(i, j) = HexPlayer(graph, 1, Random);
				temp = graph.place_bit(i, j, 1);
			}

			if (graph.is_winner(1)) { awin++; std::cout << "You win! Game is restaring!" <<std::endl; break; }
			std::cin.get();


			system("CLS"); //clear the screen for next move

			//AI making a move
			std::cout << "please wait...";
			std::tie(i, j) = HexPlayer(graph, 2, MC,nsimul);
			temp = graph.place_bit(i, j, 2);
			if (temp != 0) { std::cout << "error occurs!" << std::endl; throw std::exception(); }

			if (graph.is_winner(2)) { bwin++; std::cout << "You lose!"; break; }//check if AI wins
		}
	}

	clock_t end = clock();
	std::cout << "elapsed time:" << double(end - begin) / CLOCKS_PER_SEC << "s" << std::endl;
	std::cout << "speed per game: " << double(end - begin) / CLOCKS_PER_SEC / ngame * 1000 * 1000 << "micro_second" << std::endl;

	std::cout << "A wins " << awin << " games whereas B wins " << bwin << "games" << std::endl;

	//end of code
	std::cin.clear();
	std::cin.ignore(32767, '\n');
	std::cin.get();

	return 0;
}