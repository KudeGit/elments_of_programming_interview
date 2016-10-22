#include <iostream>
#include "Graph.hpp"


//task scheduling problem
//Build a graph. Edge between taskA and taskB iff A must be completed before B.
//Check if a scheduling exists by checking for cycle: DFS with two colors
//Topologically sort nodes, dividing the node is buckets at the same depth. 
//Explore nodes in the same buckets and take the maximum Time of exectuion. 
//
//
//


int main (void)
{
    Graph<int> g;
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,4);
    g.add_edge(3,4);
    g.add_edge(3,5);
    g.add_edge(4,5);

    if (g.is_cycle()) {
        std::cout << "There is a cycle... impossible to compute the scheduling";
        return 0;
    }

    auto res = g.topoSortParallel();

    int level = 0;
    for (auto& nodes: res) {
        std::cout << level << ": " ;
        for (auto& node: nodes){
            std::cout << *node << ", ";
        }
        std::cout << std::endl;
        ++level;
    }
    return 0;
}
