#include <iostream>
#include <string>
#include <memory>
#include <functional>
#include <vector>
#include "Graph.hpp"

int main (int argc, char* argv[])
{
    if (argc != 2) {
        std::cout << "usage error: " << argv[0] << " graph_file " << std::endl;
        return -1;
    }
    Graph<std::string> g;
    g.load_from_file(argv[1]);
    auto print_node = [](auto node) {std::cout << *node;};
    auto do_nothing = [](auto node) {return;};
    g.dfs(do_nothing);
    std::cout << g << std::endl;
    //auto sp = std::make_shared<int>(12);
    //GraphNode<int> A{GraphNode<int>(sp)};
    //GraphNode<int> B{std::move(A)};
    //GraphNode<int> C;
    //C = B;
    //std::cout << B << std::endl;
    //std::cout << C << std::endl;
    g.get_scc();


    g.bfs("G");




    return 0;
}


