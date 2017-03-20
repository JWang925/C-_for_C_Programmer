//

#include <iostream>
#include "hexGraph.h"
#include "hexPlayer.h"


using namespace std;

int main() {
	hexGraph graph(5);
	graph.print();
	int winner;
	int i, j, temp;
	while (1) {
		tie(i, j) = HexPlayer(graph, 1, "Random");
		temp=graph.place_bit(i, j, 1);
		if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); }
		if (graph.is_winner(1)) { winner = 1; break; }
		graph.print();
		tie(i, j) = HexPlayer(graph, 2, "Random");
		temp=graph.place_bit(i, j, 2);
		if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); }
		if (graph.is_winner(2)) { winner = 2; break; }
		graph.print();
	}




	//end of code
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

	return 0;
}