#include <iostream>
#include "Graph.hpp"

// sort team by height
// build graph, add direct edge between teamA and teamB iff
// teamA can be placed before teamB.
// Result should be a DAG. Test for cycle (DFS with two colors)
// Compute longest path on a DAG: topological sort nodes from the smallest
// and in order for each neigh update distance iff current distance is lower 
// than dist to the current node plus the weight of the edge to reach this neigh

int main (void) 
{
    banner("Longest Path");
    Graph<int> g9;
    g9.add_edge(0, 1, 5);
    g9.add_edge(0, 2, 3);
    g9.add_edge(1, 3, 6);
    g9.add_edge(1, 2, 2);
    g9.add_edge(2, 4, 4);
    g9.add_edge(2, 5, 2);
    g9.add_edge(2, 3, 7);
    g9.add_edge(3, 5, 1);
    g9.add_edge(3, 4, -1);
    g9.add_edge(4, 5, -2);
    std::cout << g9 << std::endl;
    if(g9.is_cycle() == true) {
        std::cout << "Graph is not a DAG" << std::endl;
        return 0;
    }
    
    auto dist = g9.longest_path(1);
    for (const auto& d: dist) {
        std::cout << *d.first << ": " << d.second << std::endl;
    }
    return 0;

}
