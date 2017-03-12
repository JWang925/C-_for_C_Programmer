#include<iostream>
#include<time.h> //for time()
#include<string> //need this to have string working with operator ">>"
#include<fstream>
#include<iterator> //for "istream_iterator
#include<algorithm> // std::count

//#include"route.h" //quotation mark for user-created header file, depreciated
using namespace std;

int main() {

	const clock_t begin_time = clock(); //to time the execution time

	//define the program parameters
	int size;
	double density;
	string filename;
	bool if_import_graph;
	cout << "Using Krushal's method to find the MST of an imported or generated graph" << endl;
	cout << "************************" <<endl;
	cout << "Do you want to generate a random graph or Read from text file? (0 for random graph, 1 for importing graph):";
	cin >> if_import_graph;

	bool** graph;
	int** color;
	int** cost;
	int total_cost;
	srand(time(0));

	if (if_import_graph) { //import graph
		bool is_imported = 0;
		cout << "please input file name:";
		cin >> filename;
		cout << endl << "Your input is:" << filename << endl;

		ifstream intp(filename.c_str()); //the constructor for ifstream takes a const char*
		istream_iterator<int> in(intp); //create an iterator in initialized at the beginning of input stream intp;
		istream_iterator<int> eos; //end of stream iterator
		
		size = *in;
		cout << endl << "import: size is:" << size;
		in++;

		//allocate the matrices based on the size given
		graph = new bool*[size];
		color = new int*[size];
		cost = new int*[size];
		for (int i = 0; i < size; ++i) {
			graph[i] = new bool[size](); //adding () initializes the array to be filled with zeros
			color[i] = new int[size]();
			cost[i] = new int[size]();
		}
		//Import the graphes with iterators
		while (in != eos) {
			int i, j;
			i = *in; in++;
			j = *in; in++;
			cost[i][j] = *in; in++;
			cout << "read:" << i << '\t' << j << '\t' << cost[i][j] << endl;
			graph[i][j] = 1;
		}
	}
	else { //generate graph
		cout << "generating random graph:" << endl;
		cout << "Graph size:";
		cin >> size;
		cout << "Graph density (0,1):";
		cin >> density;

		graph = new bool*[size];
		color = new int*[size];
		cost = new int*[size];

		//Initialization
		for (int i = 0; i < size; ++i) {
			graph[i] = new bool[size];
			color[i] = new int[size];
			cost[i] = new int[size];
		}


		//Define the routes that exists
		for (int i = 0; i < size; ++i) {
			for (int j = i; j < size; ++j) {
				if (i == j) graph[i][j] = false;
				else graph[i][j] = graph[j][i] = (static_cast<double>(rand()) / RAND_MAX<density);
			}
		}

		//Define the cost
		for (int i = 0; i < size; ++i) {
			for (int j = i; j < size; ++j) {
				if (graph[i][j]) cost[i][j] = cost[j][i] = static_cast<double>(rand()) / RAND_MAX * 30;
			}
		}

		cout << "output graph now..." <<endl;
		//Output the graph to graph.txt
		ofstream outp("graph.txt"); //A output directory, initialized at "graph.txt"
		outp << size << endl;
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (graph[i][j]) outp << i << '\t' << j << '\t' << cost[i][j] << endl;
			}
		}
		cout << "Done." << endl;
	}

	//(Graph,cost is defined at this moment)Find shortest route using Krushal's method
	//start at node 1.
	//Assuming graph is connected
	
	//Find the shortest route in the map

	bool** MST = new bool*[size]; //Initialized a map for MST
	for (int i = 0; i < size; ++i) {
		MST[i] = new bool[size]();
	}

	bool* close = new bool[size]();

	int c_size = 1, old_size = 0; //parameter to control the while loop
	int min_i = 0, min_j = 0, min_cost = 999;
	while ((old_size != c_size) && c_size != size) { //each iteration in the while loop should add one item to the close set
		old_size = c_size;
		min_cost = 999;
		for (int i = 0; i < size; ++i)
			for (int j = i+1; j < size; ++j) {
				//cout << "graph[" << i << "]["<< j << "] is " << graph[i][j] << close[i] << close[j]; //debug code
				
				if ((!graph[i][j]) || (close[i] && close[j])) continue;
				if (cost[i][j] < min_cost) {
					min_i = i; min_j = j; min_cost = cost[i][j]; //record the index for the minimal value
				}
			}
		if (min_i != 0 || min_j != 0) { //if true, then we have found a minimal previously
			close[min_i] = 1; close[min_j] = 1;
			MST[min_i][min_j] = 1;
			c_size = c_size + 1;
		}		

	}

	//Output the MST to MST.txt
	ofstream outp("MST.txt"); //A output directory, initialized at "graph.txt"
	outp << size << endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			if (MST[i][j]) outp << i << '\t' << j << '\t' << cost[i][j] << endl;
		}
	}


	cout << "Program finished. Time consumption:" << float(clock() - begin_time) / CLOCKS_PER_SEC << 's'; //output computation time

	//end of code
	cin.clear();
	cin.ignore(32767, '\n');
	cin.get();

	return 0;
}