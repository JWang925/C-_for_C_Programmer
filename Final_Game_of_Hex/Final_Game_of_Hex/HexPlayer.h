#pragma once
#include "hexGraph.h"
#include <tuple>
#include <time.h>

//Will develop this into an object



enum strategy {
	Random,
	MC
};

//uses tuple to return more than one outputs.
//HexPlayer is a function which looks at the graph and decide which move to make. The decision is outputed through a tuple.
std::tuple<int,int> HexPlayer(const hexGraph& graph, int player, strategy st); 


double MCsimulation(const hexGraph& graph, int k, int player, int nsimul); //this algorithm returns the value/ possibility of winning by placing a stone No.1 at position k 
