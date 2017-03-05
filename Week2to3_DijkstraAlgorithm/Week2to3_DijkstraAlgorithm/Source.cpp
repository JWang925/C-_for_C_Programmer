#include<iostream>
#include<time.h> //for time()
using namespace std;

int main() {
	//create a class called route, which has a boolean stating whether this route exists, and an double variable showing the distance if the route exists
	class route {
	public:
		double get_dist() { return distance; }
		bool ifconnect() { return is_connect; }
		void set_connect(bool x) { is_connect = x; }
		void set_distance(double x) { distance = x; }

		route(bool x = 0, double y = 1.0) :is_connect(x), distance(y) {}; //constructor

		// ?? Should I delte "is_connect","distance"? If yes, how to do that?
		~route() { //destructor, use to delete items created on the heap
			cout << "destructor called" << endl;  //but when are they called in the program?
		}

	private:
		bool is_connect;
		double distance;
	};

	//create a random map of size x, undirectional.
	int size = 5;
	double density = 0.2;
	route** graph; //graph is an pointer to a 2D array of routes
	srand(time(0)); //seed a random number generator
	graph = new route*[size]; //graph is an array of pointers pointing to an array of "routes", on the heap.
	for (int i = 0; i < size; ++i) //then allocate all the "route" array on heap too.
		graph[i] = new route[size];

	//now populate the graph with a density.
	for (int i = 0; i < size; ++i)
		for (int j = i; j < size; ++j) {
			if (i == j)
				graph[i][j].set_connect(false); //this is redundant..but well, I'll keep it here for redundancy
			else {
				graph[i][j] = graph[j][i] = (rand() % 100 < 100 * density); //rand() generates a random integer number 
			}
			cout << graph[i][j].ifconnect() << endl; // << need to be overloaded for route
		}

	//print out of the map
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j)
			cout << graph[i][j].ifconnect() << ' ';
		cout << endl;
	}

	//find the shortest distance



	//end of code
			cin.clear();
			cin.ignore(32767, '\n');
			cin.get();

}