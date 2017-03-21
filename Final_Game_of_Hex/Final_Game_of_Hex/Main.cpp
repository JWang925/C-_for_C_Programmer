//

#include <iostream>
#include "hexGraph.h"
#include "hexPlayer.h"


using namespace std;

int main() {


	srand(time(nullptr));
	int awin = 0; int bwin = 0;
	int ngame = pow(10, 2);
	clock_t begin = clock();
	for (int igame = 0; igame < ngame; igame++) { //running 10**5 games
		hexGraph graph(5); //game setup
		//graph.print();
		int i, j, temp;
		while (1) { //game running
			tie(i, j) = HexPlayer(graph, 1, "Random");
			temp = graph.place_bit(i, j, 1);
			//graph.print();
			if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); }
			if (graph.is_winner(1)) { awin++; break; }
			tie(i, j) = HexPlayer(graph, 2, "Random");
			temp = graph.place_bit(i, j, 2);
			//graph.print();
			if (temp != 0) { cout << "error occurs!" << endl; throw std::exception(); }
			if (graph.is_winner(2)) { bwin++; break; }
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