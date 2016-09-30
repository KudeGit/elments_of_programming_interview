#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <typeinfo>
#include <fstream>
#include <sstream>
#include <queue>
#include <tuple>
#include "../utils.hpp"


template <class T>
class Graph;

template <class T>
class GraphNode;


template <class T>
struct Edge {
    std::shared_ptr<GraphNode<T>> from;
    std::shared_ptr<GraphNode<T>> to;
    std::vector<int> weights; //support multiple edges with different weight
};


template <class T>
struct KeyHashEdge {
    size_t operator() (const Edge<T>& e) const {
        return std::hash<T>(*e->from.get_data()) ^
            std::hash<T>(*(e->to->get_data()));
    }
};


template <class T>
struct KeyEqualEdge {
    bool operator() (const Edge<T>& lhs, const Edge<T>& rhs) {
        return *(lhs->from->get_data()) == *(rhs->from->get_data()) &&
            *(lhs->to->get_data()) == *(rhs->to->get_data());
    }
};




template <class T>
class GraphNode {
    std::vector<std::shared_ptr<Edge<T>>> adj_list;
    std::shared_ptr<T> data;
    int pre_visit_time = 0;
    int visit_time = 0;
    int post_visit_time = 0;
    bool is_visited = false;
    void swap(GraphNode<T>& other);
    public:
    void reset_stats () {
        pre_visit_time = 0;
        visit_time = 0;
        post_visit_time = 0;
        is_visited = false;
    }
    GraphNode () : data(nullptr) {std::cout << "I am default" << std::endl;}
    GraphNode (const std::shared_ptr<T>& data_ptr) : data(data_ptr) {}
    //GraphNode (const GraphNode<T>& other);
    //GraphNode (GraphNode<T>&& other);
    //GraphNode& operator= (GraphNode<T> other);
    int get_pre_visit_time () const { return pre_visit_time; }
    int get_visit_time () const { return visit_time; }
    int get_post_visit_time () const { return post_visit_time; }
    bool get_is_visited () const { return is_visited; }
    std::shared_ptr<T> get_data() const {return data;}
    void set_pre_visit_time (int t) { pre_visit_time = t; }
    void set_visit_time (int t) { visit_time = t; }
    void set_post_visit_time (int t) { post_visit_time = t; }
    void set_is_visited (bool v) { is_visited = v; }
    void set_data (std::shared_ptr<T>& d) {data = d;}

    friend std::ostream& operator<< (std::ostream& out, const GraphNode<T>& gn) {
        out << "{" << *gn.data << "(" << gn.pre_visit_time << ", " <<
            gn.post_visit_time << ")" << "}";
        return out;
    }

    friend class Graph<T>;

};

template <class T>
bool operator== (const GraphNode<T>& lhs, const GraphNode<T>& rhs)
{
    return lhs.get_data() == rhs.get_data();
}

namespace std {
    template<class T>
    struct hash<GraphNode<T>> {
        size_t operator() (const GraphNode<T>& gn) const {
            return std::hash<T>()(*gn.get_data());
        }
    };
}

//template <class T>
//GraphNode<T>::GraphNode (GraphNode<T>&& other)
//{
//    std::cout << "I am the move" << std::endl;
//    data = other.data;
//    other.data = nullptr;
//    pre_visit_time = other.pre_visit_time;
//    visit_time = other.visit_time;
//    post_visit_time = other.visit_time;
//    is_visited = other.is_visited;
//}


//template <class T>
//GraphNode<T>::GraphNode(const GraphNode<T>& other)
//{
//    std::cout << "I am copy" << std::endl;
//    data = other.data;
//    pre_visit_time = other.pre_visit_time;
//    visit_time = other.visit_time;
//    post_visit_time = other.visit_time;
//    is_visited = other.is_visited;
//}

template <class T>
void GraphNode<T>::swap(GraphNode<T>& other)
{
    std::swap(data, other.data);
    std::swap(pre_visit_time, other.pre_visit_time);
    std::swap(visit_time, other.visit_time);
    std::swap(post_visit_time, other.post_visit_time);
    std::swap(is_visited, other.is_visited);
}

//template <class T>
//GraphNode<T>& GraphNode<T>::operator= (GraphNode<T> other)
//{
//    swap(other);
//    return *this;
//}
//
template <class T1, class T2>
struct KeyHashPair {
    size_t operator() (const std::pair<T1,T1>& p) const {
        return std::hash<T1>()(p.first) ^ std::hash<T2>()(p.second);
    }
};



template <class T>
std::ostream& operator<< (std::ostream& out, const Edge<T>& e)
{
    out << "(" <<  (*e.from)  << ", "
        << (*e.to) << ", " << e.weights.size() << ") ";
    return out;
}


//template <class T1, class T2>
//struct KeyEqualPair {
//    bool operator() (const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs) {
//        return lhs.first == rhs.first &&
//            lhs.second == rhs.second;
//    }
//};


template <class T>
class Graph {
    protected:
        std::unordered_map<T, std::shared_ptr<GraphNode<T>> > nodes;
        std::unordered_map<std::pair<T,T>, std::shared_ptr<Edge<T>>,
            KeyHashPair<T,T>> edges;
        void reset_nodes_status();
        template <class U>
        void explore(std::shared_ptr<GraphNode<T>>& curr, int& time, U& u);
        void reverse(std::shared_ptr<GraphNode<T>>& curr,
                std::unordered_set<std::shared_ptr<Edge<T>>>& reversed_edges);
    public:
        Graph() {};
        void load_from_file (const std::string& filename);
        void add_edge(const std::shared_ptr<T> from, 
                const std::shared_ptr<T> to, const int weight = 1);
        template <class U>
        void dfs (U& u);

        template <class U>
        void dfs (const std::shared_ptr<GraphNode<T>>& start, U& u) {
            reset_nodes_status();
            int t = 0;
            explore(start, t, u);
        }

        template <class U>
        void dfs (const T& start, U& u) {
            if(nodes.find(start) == nodes.end()) {
                throw std::logic_error("dfs: node is not present");
            }
            dfs(nodes[start], u);
        }

        void reverse();
        std::vector<std::vector<std::shared_ptr<GraphNode<T>>>> get_scc ();
        std::unordered_map<std::shared_ptr<GraphNode<T>>, int>  bfs(const std::shared_ptr<GraphNode<T>>& start);
        std::unordered_map<std::shared_ptr<GraphNode<T>>, int> bfs(const T& start) {
            if(nodes.find(start) == nodes.end()) {
                throw std::logic_error("bfs: node is not present");
            }
            bfs(nodes[start]);
        }

        auto dijkstra (const T& start) {
            if(nodes.find(start) == nodes.end()) {
                throw std::logic_error("dijkstra: node is not present");
            }
            return dijkstra(nodes[start]);
        }
        auto dijkstra (const std::shared_ptr<GraphNode<T>>& start);

    friend std::ostream& operator<< (std::ostream& out, const Graph<T>& g) {
        for (const auto& node_pair: g.nodes) {
            auto node = node_pair.second;
            out << *node << ": ";
            for (const auto& edge: node->adj_list) {
                out << *edge << ", ";
            }
            out << std::endl;
        }
        return out;
    }
};

template<class T>
void Graph<T>::add_edge(const std::shared_ptr<T> from, 
        const std::shared_ptr<T> to, const int weight)
{
    auto& source = nodes[*from];
    if (!source) {
        source = std::make_shared<GraphNode<T>>(from);
    }
    auto& destination = nodes[*to];
    if (!destination) {
        destination = std::make_shared<GraphNode<T>>(to);
    }
    auto tmp_edge = std::pair<T,T>{*from, *to};
    auto& edge = edges[std::pair<T,T>{*from, *to}];
    if (!edge) {
        edge = std::make_shared<Edge<T>>(Edge<T>{source, destination});
    }
    edge->weights.emplace_back(weight);
    source->adj_list.emplace_back(edge);
}


template <class T>
void Graph<T>::reset_nodes_status()
{
    for (auto& it: nodes) {
        auto node = it.second;
        node->reset_stats();
    }
}

template <class T>
void Graph<T>::load_from_file (const std::string& filename)
{
    std::ifstream input_file(filename);
    if (!input_file.good()) {
        std::cout << "Could not open file " << filename << std::endl;
        return;
    }
    std::string line;
    T a, b;
    while (getline(input_file, line)) {
        if (line.size() > 1) {
            std::stringstream ss(line);
            ss >> a; ss >> b;
            {
                auto a_node_ptr = std::make_shared<T>(a);
                auto b_node_ptr = std::make_shared<T>(b);
                add_edge(a_node_ptr, b_node_ptr);
            }
        }
    }
}

template <class T>
template <class U>
void Graph<T>::explore(std::shared_ptr<GraphNode<T>>& curr, int& time, U& u)
{
    if (curr->is_visited) {
        throw std::logic_error("Visiting an already visited node");
    }
    curr->pre_visit_time = time++;
    curr->is_visited = true;
    u(curr);
    for (auto& edge: curr->adj_list) {
        if (edge->from != curr) {
            throw std::logic_error("source edge node differes from current node");
        }
        if (!edge->to->is_visited) {
            explore(edge->to, time, u);
        }
    }
    curr->post_visit_time = time++;
}

template <class T>
template <class U>
void Graph<T>::dfs(U& u)
{
    auto time = 0;
    reset_nodes_status();
    for (auto& it: nodes) {
        auto start = it.second;
        try {
            if(!start->is_visited) {
                explore(start, time, u);
            }
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}



template <class T>
void Graph<T>::reverse(std::shared_ptr<GraphNode<T>>& curr,
        std::unordered_set<std::shared_ptr<Edge<T>>>& reversed_edges)
{
    curr->is_visited = true;
    while(!curr->adj_list.empty()) {
        auto& e = curr->adj_list.front();
        if (!e->to->is_visited) {
            reverse(e->to, reversed_edges);
        }
        std::swap(e->from, e->to);
        std::swap(curr->adj_list.front(), curr->adj_list.back());
        curr->adj_list.pop_back();
    }
}

template <class T>
void Graph<T>::reverse ()
{
    reset_nodes_status();
    std::unordered_set<std::shared_ptr<Edge<T>>> reversed_edges;
    for (auto& it: nodes){
        auto start = it.second;
        if (!start->is_visited) {
            reverse(start, reversed_edges);
        }
    }
    for (auto& edge_value_pair: edges) {
        auto e = edge_value_pair.second;
        nodes[*(e->from->get_data())]->adj_list.emplace_back(e);
    }
    reset_nodes_status();
}

template <class T>
struct SCC {
    std::vector<std::shared_ptr<GraphNode<T>>> scc;
    void operator() (const std::shared_ptr<GraphNode<T>>& node) {
        scc.emplace_back(node);
    }
};
template <class T>
std::ostream& operator<< (std::ostream& out, const SCC<T>& scc) {
    for (const auto& node: scc.scc) {
        out << *node << ", ";
    }
    return out;
}

template <class T>
std::vector<std::vector<std::shared_ptr<GraphNode<T>>>> Graph<T>::get_scc()
{
    reverse();
    auto do_nothing = [](auto a){return;};
    dfs(do_nothing);
    std::vector<std::shared_ptr<GraphNode<T>>> tmp_nodes;
    for (auto& node_pair: nodes){
        auto& node= node_pair.second;
        tmp_nodes.emplace_back(node);
    }
    std::sort(tmp_nodes.begin(), tmp_nodes.end(), [](auto& a, auto& b){
            return a->post_visit_time > b->post_visit_time;
        });
    
    std::vector<std::vector<std::shared_ptr<GraphNode<T>>>> res;
    reverse();
    int time = 0; 
    for (auto &node: tmp_nodes) {
        if(node->is_visited == false) {
            SCC<T> curr_scc;
            explore(node, time, curr_scc);
            res.emplace_back(curr_scc.scc);
        }
    }
    for (const auto& scc: res){
        std::cout << "scc: " ;
        for (auto& node: scc) {
            std::cout << *node << ", ";
        }
        std::cout << std::endl;
    }
    reset_nodes_status();
    return res;
}


template <class T>
std::unordered_map<std::shared_ptr<GraphNode<T>>, int> Graph<T>::bfs(const std::shared_ptr<GraphNode<T>>& start)
{
    std::unordered_map<std::shared_ptr<GraphNode<T>>, int> distance;
    std::queue<std::shared_ptr<GraphNode<T>>> Q;

    distance[start] = 0;
    Q.push(start);
    while (!Q.empty()) {
        auto curr = Q.front(); Q.pop();
        for (auto& edge: curr->adj_list) {
            auto to = edge->to;
            auto& candidate = distance[to];
            if (!candidate && to != start) {
                candidate = distance[curr] + 1;
                Q.push(to);
            }
        }
    }

    //std::cout << "Distance from " << *start << ": " << std::endl;
    //for (const auto& dist_pair: distance) {
    //    std::cout << "\t\t" << *dist_pair.first << ", " << dist_pair.second << std::endl;
    //}
    return distance;
}


template <class T>
auto Graph<T>::dijkstra (const std::shared_ptr<GraphNode<T>>& start)
{
    auto pq_cmp = [] (const auto& a, const auto& b) {
        return a.second > b.second;
    };
    std::unordered_map<std::shared_ptr<GraphNode<T>>, std::tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>, int>> dist;
    std::priority_queue<std::pair<std::shared_ptr<GraphNode<T>>, int>, std::vector<GraphNode<T>>, decltype(pq_cmp)> Q;
    Q.push(std::make_pair(start, 0));
    dist[start] = std::make_tuple<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>, int>(start, nullptr, 0);
    while (Q.empty()) {
        auto curr = Q.front(); Q.pop();
        auto curr_node = curr.first;
        auto curr_dist = curr.second;
        for (const auto& edge: curr_node->adj_list) {
            if (edge->to == start) {
                continue;
            }
            auto candidate_dist = dist[edge->to];
            if (!candidate_dist) {
                candidate_dist = curr_dist + edge->weight;
                dist[edge->to] = std::make_tuple(edge->to, curr_node, candidate_dist);
                Q.push(std::make_pair(edge->to, candidate_dist));
            } else if (curr_dist + edge->weight < candidate_dist) {
                candidate_dist = curr_dist + edge->weight;
                dist[edge->to] = std::make_tuple(edge->to, curr_node, candidate_dist);
                Q.push(std::make_pair(edge->to, candidate_dist));
            }
        }
    }
    return dist;
}




