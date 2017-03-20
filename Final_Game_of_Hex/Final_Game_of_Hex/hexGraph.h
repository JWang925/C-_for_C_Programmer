#pragma once

#include <vector>
#include <iostream>

class hexGraph {
public:
	hexGraph(int edge_length_) {  //constructor
		edge_length = edge_length_; //pass input to private variable, if the former exists
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
				for(auto it:edgelist[count-1]) std::cout << "edge list for i=" << i << " j=" << j << " is " << it << std::endl;
			}
	}
	void print() {
		for (int i = 0; i < edge_length; ++i) { 
			for (int k = 0; k < i; ++k) std::cout << " "; //indent
				for (int j = 0; j < edge_length; ++j) std::cout << map[i*edge_length+j] << " ";
			std::cout << std::endl;
		}
	}
	bool is_winner(int player) { //Find a spanning tree starting with all the nodes on one end, and check if the tree reaches the other end
		std::vector <int> close; //close-set
		int old_csize = 0;
		 
		if (player == 2) 
			for (int i = 0; i < edge_length; ++i) 
				if( map[i * edge_length + 0]) close.push_back(i * edge_length + 0);// First populate close set with qualified nodes on the left
		if (player == 1) 
			for (int j = 0; j < edge_length; ++j)
				if (map[0 * edge_length + j]) close.push_back(0 * edge_length + j);// First populate close set with qualified nodes on the top

		while (old_csize!=close.size()) { //continue to add hex into the close set
			old_csize = close.size();
			std::vector <int> temp{};
			for (auto it = close.begin(); it != close.end();++it) {
				std::cout << "for loop called" << std::endl;
				for (auto it2 = edgelist[*it].begin(); it2 != edgelist[*it].end(); ++it2) { //it2 iterates through all the points that it can reach
					if (map[*it2] == player && (std::find(close.begin(), close.end(), map[*it2]) == close.end())   ) temp.push_back(*it2);  //if it2 is also occupied by player, then add it to close list
				}
			}
			close.insert(close.end(),temp.begin(),temp.end());
			for (auto it = close.begin(); it != close.end(); ++it) std::cout << *it << std::endl;
		}
		for (int i = 0; i < edge_length; ++i) { //check if 
			if (player == 2 && std::find(close.begin(), close.end(), i*edge_length + edge_length - 1) != close.end()) return true; //check if right edge is in the close set
			if (player == 1 && std::find(close.begin(), close.end(), (edge_length-1)*edge_length + i) != close.end()) return true; //check if bottom edge is in the close set
		}
		return false;
	}


	int place_bit(int i, int j, int player) { //players are no.1 and no.2
		if (player != 1 && player != 2) { std::cout << "player does not exist"<<std::endl;  return 1; }
		if (map[i * edge_length + j] != 0) { std::cout << "That location is pre-occupied"<<std::endl; return 1; }
		map[i * edge_length + j] = player;
		return 0;
	}
	std::vector<int> get_map() const { return map; }
	int get_edge_length() const { return edge_length; }
private:
	int edge_length=11;
	std::vector<std::vector<int>> edgelist; //edge list is a 2-by-2 matrix, 1st dimension: all the nodes. 2nd dimension: A vector of all the nodes that it is connected to.
	std::vector<int> map;
};