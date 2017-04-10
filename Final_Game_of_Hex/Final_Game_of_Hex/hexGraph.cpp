#include "hexGraph.h"


void hexGraph::print() {//print out the board
	std::cout << "  ";
	for (int i = 0; i < edge_length; ++i) std::cout << i << ' '; //coordinates
	std::cout << std::endl;

	for (int i = 0; i < edge_length; ++i) { //each for iteration prints a line
		if(i<=9) std::cout << i << ' '; //prints line number
		else std::cout << i;
		for (int k = 0; k < i; ++k) std::cout << " "; //indent
		for (int j = 0; j < edge_length; ++j) std::cout << map[i*edge_length + j] << " ";
		std::cout << std::endl;
	}
}


bool hexGraph::is_winner(int player) { //Find a spanning tree starting with all the nodes on one end, and check if the tree reaches the other end
	std::vector <int> close; //close-set
	int old_csize = 0;

	if (player == 2)
		for (int i = 0; i < edge_length; ++i)
			if (map[i * edge_length + 0] == player) close.push_back(i * edge_length + 0);// First populate close set with qualified nodes on the left
	if (player == 1)
		for (int j = 0; j < edge_length; ++j)
			if (map[0 * edge_length + j] == player) close.push_back(0 * edge_length + j);// First populate close set with qualified nodes on the top


	int i = 0; //i is the number of points in the close set which has been checked their neiborgh for legal points
	while (old_csize != close.size()) { //continue to add hex into the close set
		old_csize = close.size();
		for (; i != close.size(); ++i) { //iterate through vector(the close set) of which the size changes
										 //for (int i_temp : close) std::cout << i_temp << ' '; std::cout << std::endl; //output all the points in the close set //range base for loop
			for (auto it = edgelist[close[i]].begin(); it != edgelist[close[i]].end(); ++it) { //it iterates through all the points that it can reach
				if (map[*it] == player && (std::find(close.begin(), close.end(), *it) == close.end())) close.push_back(*it);  //if it is also occupied by player, then add it to close list
			}
		}

	}
	for (int i = 0; i < edge_length; ++i) { //check if 
		if (player == 2 && std::find(close.begin(), close.end(), i*edge_length + edge_length - 1) != close.end()) return true; //check if right edge is in the close set
		if (player == 1 && std::find(close.begin(), close.end(), (edge_length - 1)*edge_length + i) != close.end()) return true; //check if bottom edge is in the close set
	}
	return false;
}


int hexGraph::place_bit(int i, int j, int player) { //players are no.1 and no.2
	
	if (i >= edge_length || j >= edge_length) { std::cout << "input is out of range" << std::endl;  return 1; }
	if (player != 1 && player != 2) { std::cout << "player does not exist" << std::endl;  return 1; }
	if (map[i * edge_length + j] != 0) { std::cout << "That location is pre-occupied" << std::endl; return 1; }
	map[i * edge_length + j] = player;
	return 0;
}