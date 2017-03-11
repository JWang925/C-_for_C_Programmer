#include<iostream>
#include<iomanip>
#include<time.h> //for time()
#include<string> //need this to have string working with operator ">>"
//#include"route.h" //quotation mark for user-created header file, depreciated
using namespace std;

int main() {
	const clock_t begin_time = clock(); //to time the execution time

	//define the program parameters
	int size;
	double density;
	bool if_import_graph;
	cout << "Graph size?" << endl;
	cin >> size;
	cout << "Graph density (0,1)?" << endl;
	cin >> density;
	cout << "Do you want to generate a random graph or Read from text file? (0 for random graph, 1 for importing graph)" << endl;
	cin >> if_import_graph;
	if (if_import_graph) {
		string filename;
		cout << "please input file name:" ;
		cin >> filename;
		cout << endl << "Your input is:" << filename << endl;
	}

	bool** graph;
	int** color;
	int** cost;
	srand(time(0));

	graph = new bool*[size];
	color = new int*[size];
	cost = new int*[size];

	//Initialization
	for (int i = 0; i < size; ++i) {
		graph[i] = new bool[size];
		color[i] = new int[size];
		cost[i] = new int[size];
	}

	//Initialize the graph


	//Find shortest route using Krushal's method









	cout << "Time consumption:" << float(clock() - begin_time) / CLOCKS_PER_SEC << 's'; //output computation time

	//end of code
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

	return 0;
}