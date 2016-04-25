#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include "../utils.hpp"



template <class T>
class GraphNode {
    int id;
    T data;
    bool is_visited;
};

template <class T>
struct GraphNodeHash {
    std::size_t operator()(const GraphNode<T> k) const
    {
        return std::hash<int>()(k.id);
    }
};

template <class T>
struct GraphNodeEqual {
    bool operator()(const GraphNode<T>& lhs, const GraphNode<T>& rhs) const
    {
        return lhs.id == rhs.id;
    }
};


template <class T>
class Edge {
    std::shared_ptr<GraphNode<T>> from;
    std::shared_ptr<GraphNode<T>> to;
};

template <class T>
class Graph {
    std::unordered_map<GraphNode<T>, GraphNode<T>, 
        GraphNodeHash<T>, GraphNodeEqual<T>> nodes;
    std::vector<Edge<T>> edges;
    std::unordered_map<GraphNode<T>,
        std::unordered_set<std::shared_ptr<Edge<T>>>,
        GraphNodeHash<T>,
        GraphNodeEqual<T>> adjList;

    public:
    void build_from_file (const std::string& input_file);
};


template <class T>
void Graph<T>::build_from_file (const std::string& input_file)
{
    std::ifstream ifile(input_file);
    if (!ifile.good()) {
        error("cannot open input file");
        return;
    }
    std::string line;
    while (getline(ifile, line)) {
        ;
    }
    return;
}


