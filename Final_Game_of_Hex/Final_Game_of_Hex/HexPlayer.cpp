#include "hexPlayer.h"

std::tuple<int, int> HexPlayer(const hexGraph& graph, int player, std::string strategy) {
	std::cout << "player" << player << "is thinking";
	
	
	//get the data from graph
	int edge_length;
	std::vector<int> map;
	edge_length = graph.get_edge_length();
	map.resize(edge_length*edge_length);
	map = graph.get_map();


	//decide the i,j
	int i, j;
	srand(time(nullptr));
	while (1) {
		i = rand()%edge_length; j = rand()%edge_length;
		if (map[i* edge_length + j] == 0) break;
	}

	std::cout << "Player" << player << "is making a move at [" << i << "] ["<< j << "]" << std::endl;
	return std::make_tuple(i,j); 
}