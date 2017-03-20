#pragma once
#include "hexGraph.h"
#include <tuple>
#include <time.h>


//uses tuple to return more than one outputs.

//HexPlayer is a function which looks at the graph and decide which move to make. The decision is outputed through a tuple.
std::tuple<int,int> HexPlayer(const hexGraph& graph, int player, std::string strategy); 
