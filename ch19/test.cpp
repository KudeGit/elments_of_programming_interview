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
    //g.dfs(do_nothing);
    std::cout << g << std::endl;
    //auto sp = std::make_shared<int>(12);
    //GraphNode<int> A{GraphNode<int>(sp)};
    //GraphNode<int> B{std::move(A)};
    //GraphNode<int> C;
    //C = B;
    //std::cout << B << std::endl;
    //std::cout << C << std::endl;
    //g.get_scc();


    //auto path = g.bfs("G");


    auto min_path = g.dijkstra("A");
    banner("Dijkstra:");
    for (const auto& d: min_path) {
        auto& curr_node = d.first;
        auto& prev = (std::get<0>(d.second) ? 
                std::get<0>(d.second) : curr_node);
        auto& min_dist = std::get<1>(d.second);
        std::cout << *curr_node << ": prev: " << *prev 
            << " / dist: " << min_dist << std::endl;
    }

    auto min_path2 = g.bellman_ford("A");
    banner("Bellman-Ford:");
    for (const auto& d: min_path2) {
        auto& curr_node = d.first;
        auto& prev = (std::get<0>(d.second) ? 
                std::get<0>(d.second) : curr_node);
        auto& min_dist = std::get<1>(d.second);
        std::cout << *curr_node << ": prev: " << *prev 
            << " / dist: " << min_dist << std::endl;
    }
    banner("Kruskal:");
    Graph<char> g1;
    g1.load_from_file("graph5.txt");
    std::cout << g1 << std::endl;

    auto min_tree = g1.kruskal_min_spanning_tree();
    for (const auto& edge: min_tree) {
        std::cout << *edge << std::endl;
    }


    Graph<std::string> gg;
    gg.load_from_file(argv[1]);

    std::cout << gg.is_cycle() << std::endl;
    
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
    
    auto S = g9.topoSort();
    while (!S.empty()) {
        std::cout << *S.top() << std::endl;
        S.pop();
    }
    auto dist = g9.longest_path(1);
    for (const auto& d: dist) {
        std::cout << *d.first << ": " << d.second << std::endl;
    }

    return 0;
}


