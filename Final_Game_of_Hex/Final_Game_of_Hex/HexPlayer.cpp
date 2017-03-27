#include "hexPlayer.h"
#include <algorithm>

std::tuple<int, int> HexPlayer(const hexGraph& graph, int player, strategy st) {
	//get the data from graph
	int edge_length;
	edge_length = graph.get_edge_length();




	//decide the i,j
	int i, j;

	switch (st) {
	case Random:
		while (1) {
			i = rand() % edge_length; j = rand() % edge_length;
			if (graph.map[i* edge_length + j] == 0) break;
		}
		break;
	case MC:
		std::vector<double> value(edge_length*edge_length,0); // a value table to store the value of each possible move
		for (int k = 0; k < edge_length*edge_length; ++k) { // iterate through all the possible place for stones
			if (graph.map[k] != 0) continue; //skip it if it is already occupied 
			value[k] = MCsimulation(graph, k, player, 500);
			//std::cout << k << " " << value[k] << std::endl; //debug option

		}
		auto max = std::max_element(value.begin(), value.end());
		std::cout << "Max element is" << *max;
		std::cout << "at position" << std::distance(value.begin(), max) << std::endl;
		i = std::distance(value.begin(), max) / edge_length;
		j = std::distance(value.begin(), max) % edge_length;

	}


	//std::cout << "Player" << player << "is making a move at [" << i << "] ["<< j << "]" << std::endl;
	return std::make_tuple(i,j); 
}

double MCsimulation(const hexGraph& graph, int k, int player, int nsimul) { //this algorithm returns the value/ possibility of winning by placing a stone for player at position for n simulations 
	hexGraph MCgraph(graph);
	MCgraph.place_bit(k / MCgraph.get_edge_length(), k%MCgraph.get_edge_length(), player);
	//std::cout << "MCgraph" <<std::endl;
	//MCgraph.print();

	if (MCgraph.possible_move() == 0) return 1; //return  a random value (e.g. 1) if there was only one plausible move, there is no need to run MC in this case 
	
	//std::vector<int> One_and_Two(MCgraph.possible_move());
	//for (int i = 0; i < MCgraph.possible_move();++i) {
	//	One_and_Two[i]= (i%2==0) ? (3-player):(player);
	//}

	int win = 0;
	for (int isimul = 0; isimul < nsimul; ++isimul) {
		hexGraph MC2graph(MCgraph);
		for (int k = 0; k < MCgraph.possible_move(); ++k) { //make n move
			int i, j; //allocate i,j to store intended move
			while (1) { //pick a possible move
				i = rand() % MC2graph.get_edge_length(); j = rand() % MC2graph.get_edge_length();
				if (MC2graph.map[i* MC2graph.get_edge_length() + j] == 0) break;
			}

			MC2graph.place_bit(i,j, (k%2==0)?(3-player):(player));
		}
		if (MC2graph.is_winner(player) == 1) win++;
	}
	return 1.0* win / nsimul;
}