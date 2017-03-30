#pragma once

#include <vector>
#include <iostream>

class hexGraph {
public:
	hexGraph(int edge_length_) {  //constructor
		edge_length = edge_length_; //pass input to private variable, if the later exists, if not, default size is 11.
		int count = 0; //an iterator for vector<vector<int>> edgelist;
		edgelist.resize(edge_length*edge_length); //create the edgelist
		map.resize(edge_length*edge_length);
		for (int i = 0; i < edge_length; ++i)
			for (int j = 0; j < edge_length; ++j) {
				if (i != 0 ) edgelist[count].push_back((i-1)*edge_length+j); //left top edge
				if (i != 0 && j != edge_length - 1)	edgelist[count].push_back((i - 1)*edge_length + j+1);	//right top edge
				if (j != 0) edgelist[count].push_back(i*edge_length + j - 1); //left edge
				if (j != edge_length-1) edgelist[count].push_back(i*edge_length + j + 1); //right edge
				if (i != edge_length-1 && j!=0) edgelist[count].push_back((i + 1)*edge_length + j -1); //left bottom edge
				if (i != edge_length-1)	edgelist[count].push_back((i + 1)*edge_length + j );	//right bottom edge
				count++;
			}
	}

	hexGraph(const hexGraph& graph) {
		edge_length = graph.edge_length;
		edgelist.resize(edge_length*edge_length);
		map.resize(edge_length*edge_length);
		map = graph.get_map();
		edgelist = graph.edgelist;
	}

	~hexGraph() {}

	void print(); //print out the board

	bool is_winner(int player); //Find a spanning tree starting with all the nodes on one end, and check if the tree reaches the other end

	int place_bit(int i, int j, int player); //place a stone for player at position <i,j>

	std::vector<int> get_map() const { return map; } //Return

	int get_stone(int i, int j) const { return map[i * edge_length + j]; }
	
	int get_stone(int k) const { return map[k]; }

	int get_edge_length() const { return edge_length; } //Return the edge length, e.g. 7 for a 7-by-7 map.

	int possible_move() { return ( std::count(map.begin(), map.end(), 0));    } //returns total number of possible moves that the player can make next



private:
	std::vector<int> map;
	int edge_length=11; 
	std::vector<std::vector<int>> edgelist; //edge list is a 2-by-2 matrix, 1st dimension: all the nodes. 2nd dimension: A vector of all the nodes that it is connected to.

};