#include <iostream>
#include "Graph.hpp"
#include "../utils.hpp"
#include <tuple>


int main (void)
{
    Graph<char> g;
    g.add_edge('a','b', 3);
    g.add_edge('a','c', 2);

    g.add_edge('b','a', 4);
    g.add_edge('b','k', 1);

    g.add_edge('c','e', 8);

    g.add_edge('e','d', 7);

    g.add_edge('d','c', 5);
    g.add_edge('d','h', 5);

    g.add_edge('k','i', 1);

    g.add_edge('i','j', 6);

    g.add_edge('j','l', 7);
    g.add_edge('j','f', 1);

    g.add_edge('l','i', 9);

    g.add_edge('f','g', 6);

    g.add_edge('g','f', 7);
    g.add_edge('g','h', 4);

    std::cout << g << std::endl;


    auto min_paths = g.dijkstra_with_fewest_edges('a');
    std::cout << "Distancese from a: " << std::endl;
    for (const auto d: min_paths) {
        std::cout << *d.first << ": ";
        auto node = std::get<0>(d.second);
        auto dist = std::get<1>(d.second);
        auto n_edges = std::get<2>(d.second);
        if(node) {
            std::cout << *node << ", ";
        } else  {
            std::cout << "N/A" << ", ";
        }
        std::cout << dist << ", " << n_edges << std::endl;
    }
    return 0;

}
