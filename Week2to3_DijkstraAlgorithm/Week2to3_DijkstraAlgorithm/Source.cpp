#include<iostream>
#include<iomanip>
#include<time.h> //for time()
using namespace std;

//create a class called route, which has a boolean stating whether this route exists, and an double variable showing the distance if the route exists
class route {
public:
	double get_dist() { return distance; }
	bool ifconnect() { return is_connect; }
	void set_connect(bool x) { is_connect = x; }
	void set_distance(double x) { distance = x; }

	route(bool x = 0, double y = 999) :is_connect(x), distance(y) {}; //constructor

	~route() { //destructor, use to delete items created on the heap
		cout << "destructor called" << endl;  //No need to delete any variables since nothing is defined on the heap
	}

private:
	bool is_connect;
	double distance;
};

void find_distance(double* distance, route**graph, int size, int start); //forward declaration

int main() {

	const clock_t begin_time = clock(); //to time the execution time


	//create a random map of size x, undirectional.
	int size = 50;
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
			else if (rand() % 100 < 100 * density){ //rand() generates a random integer number
				double dist;
				dist = rand() % 10 + 1;
				graph[i][j].set_connect(true);
				graph[i][j].set_distance(dist);
				graph[j][i].set_connect(true); 
				graph[j][i].set_distance(dist);
			}
		}

	////print out of the map connectivity
	//for (int i = 0; i < size; ++i) {
	//	for (int j = 0; j < size; ++j)
	//		cout << graph[i][j].ifconnect() << ' ';
	//	cout << endl;
	//}

	//print out distance
	//
	//for (int i = 0; i < size; ++i) {
	//	for (int j = 0; j < size; ++j)
	//		cout << setw(4) << graph[i][j].get_dist() << ' ';
	//	cout << endl;
	//}

	//find the shortest distance map starting at node x)
	int start = 0;
	double* distance = new double[size];
	for (int i = 0; i < size; ++i) distance[i] = 999;

	find_distance(distance, graph, size, start);

	for (int i = 0; i < size; ++i) //display the result
		cout << distance[i] << endl;

	cout << "Time consumption:" << float(clock() - begin_time) / CLOCKS_PER_SEC <<'s'; //output computation time


	//end of code
			cin.clear();
			cin.ignore(32767, '\n');
			cin.get();

}

void find_distance(double* distance, route**graph,int size, int start) { //Here this function is going to modify the matrix distance, defined in the main on the heap. ???Is it safe????
																			//Distance is pass by value but the value distance(a ptr) points to can be modified
	int old_size = 0, c_size = 0;
	
	//Open set and close set
	bool* close = new bool[size](); //A close set for breath-first search
	bool* open  = new bool[size](); //An open set for breath-first search
	double* short_dist = new double[size](); //This stores the shortest distance from start point

	for (int i = 0; i < size; ++i)
		open[i] = close[i] = false;
	open[start] = true; //At this point only the start point is in the open set (soon to be moved to close set with cost 0)
	close[start] = true;
	c_size = 1;
	distance[start] = 0;

	while ( (old_size != c_size) || c_size==size) { //the program runs until all points are explored or no more place can be reached
		old_size = c_size;
		for (int i = 0; i < size; ++i) { //iterate through all points in the close set
			if (close[i] == 0) continue; //if the point is not in the closed loop, no need to explore around that point
			
			for (int j = 0; j < size; ++j) {
				open[j] = open[j] || graph[i][j].ifconnect(); //put j into the open set if it can be reached
				if (graph[i][j].ifconnect()) { //If this destination can be reached by point i in the closed set-> proceed to assign value to distance
					if (distance[i] + graph[i][j].get_dist() <= distance[j]) //If the new way of approaching J is faster, then adopt and renew the value of distance
						distance[j] = distance[i] + graph[i][j].get_dist();
					close[j] = true; //add it to close set
				}
			}
		}
	}



}