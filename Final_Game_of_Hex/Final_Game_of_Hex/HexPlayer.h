#pragma once
#include "hexGraph.h"
#include <tuple>
#include <time.h>

/*
Will develop this into an object, add in name of the player.
*/

//Type name strategy: it has 2 possible value "Random" or "MC"(i.e. Monte-Carlo)
enum strategy {
	Random,
	MC
};

/*
HexPlayer is a function which looks at the graph and decide which move to make. The decision is outputed by using Tuple.
Params: (const HexGraph, int Player number, and strategy type);
Returns: (first: i coordinate; second, j coordinate);
*/
std::tuple<int,int> HexPlayer(const hexGraph& graph, int player, strategy st, int nsimul=1000); //1000 being the default value.
/*
MCsimulation calculates the MC value(the tendency to be a good move) for each move. This info is used to decide the move for AI.
params: (const HexGraph, int Player number, strategy type and number of MC simulations to run);
return: (a number between 0 and 1 indicating the % of winning MC results)
*/
double MCsimulation(const hexGraph& graph, int k, int player, int nsimul);
