#include <iostream>
#include <vector>
#include <queue>
#include "../utils.hpp"


struct GraphNode {
    int id;
    std::vector<GraphNode*> neighs;
    int d = -1;
};

std::ostream& operator<< (std::ostream& out, const GraphNode& node)
{
    out << node.id;
    return out;
}

bool BFS (GraphNode* curr)
{
    std::queue<GraphNode*> Q;
    Q.push(curr);
    while(!Q.empty()) {
        auto curr = Q.front();
        Q.pop();
        for (auto& neigh: curr->neighs) {
            if (neigh->d  == -1) {
                Q.push(neigh);
                neigh->d = curr->d + 1;
            } else if (neigh->d == curr->d) {
                return false;
            }
        }
    }
    return true;
}


bool feasible_placement (std::vector<GraphNode>& nodes)
{
    for (auto& node: nodes) {
        if (node.d == -1) {
            node.d = 0;
            if (!BFS(&node)) {
                return false;
            }
        }
    }
    return true;
}


int main(void)
{

    std::vector<GraphNode> nodes(3);
    nodes[0].id = 0;
    nodes[1].id = 1;
    nodes[2].id = 2;

    nodes[0].neighs.emplace_back(&nodes[1]);
    nodes[0].neighs.emplace_back(&nodes[2]);

    nodes[1].neighs.emplace_back(&nodes[0]);
    nodes[1].neighs.emplace_back(&nodes[2]);

    nodes[2].neighs.emplace_back(&nodes[0]);
    nodes[2].neighs.emplace_back(&nodes[1]);
    

    auto res = feasible_placement(nodes);
    std::cout << res << std::endl;

    return 0;
}
