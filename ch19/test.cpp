#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include "Graph.hpp"

int main (void)
{
    auto from = std::make_shared<std::string>("A");
    auto to   = std::make_shared<std::string>("B");
    auto n1 = std::make_shared<GraphNode<std::string>>(from);
    auto& n1_ref = n1;
    auto n2 = std::make_shared<GraphNode<std::string>>(to);
    std::vector<std::shared_ptr<GraphNode<std::string>>> nodes;
    nodes.emplace_back(n1_ref);

    Graph<std::string> g;
    g.add_edge(from, to);
    std::cout << g << std::endl;


    return 0;
}
