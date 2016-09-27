#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include "Graph.hpp"

int main (void)
{
    Graph<std::string> g;
    g.load_from_file("graph.txt");
    g.dfs();
    std::cout << g << std::endl;
    return 0;
}
