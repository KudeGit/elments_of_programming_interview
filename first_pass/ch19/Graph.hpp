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
#include <limits>
#include "Union.hpp"
#include <stack>


template <class T>
class Graph;

template <class T>
class GraphNode;


template <class T>
struct Edge {
    std::shared_ptr<GraphNode<T>> from;
    std::shared_ptr<GraphNode<T>> to;
    std::vector<int> weights; //support multiple edges with sorted by weight
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

enum class Color {WHITE, GREY, BLACK};

std::ostream& operator<< (std::ostream& out, const Color& c)
{
    switch(c) {
        case Color::WHITE: out << "WHITE";
                    break;
        case Color::BLACK: out << "BLACK";
                    break;
        case Color::GREY: out << "GREY";
                   break;
        default: out << "N/A";
                 break;
    }
    return out;
}

template <class T>
class GraphNode {
    std::vector<std::shared_ptr<Edge<T>>> adj_list;
    std::shared_ptr<T> data;
    int pre_visit_time = 0;
    int visit_time = 0;
    int post_visit_time = 0;
    Color is_visited = Color::WHITE;
    void swap(GraphNode<T>& other);



    public:
    void reset_stats () {
        pre_visit_time = 0;
        visit_time = 0;
        post_visit_time = 0;
        is_visited = Color::WHITE;
    }
    GraphNode () : data(nullptr) {std::cout << "I am default" << std::endl;}
    GraphNode (const std::shared_ptr<T>& data_ptr) : data(data_ptr) {}
    int get_pre_visit_time () const { return pre_visit_time; }
    int get_visit_time () const { return visit_time; }
    int get_post_visit_time () const { return post_visit_time; }
    Color get_is_visited () const { return is_visited; }
    std::shared_ptr<T> get_data() const {return data;}
    void set_pre_visit_time (int t) { pre_visit_time = t; }
    void set_visit_time (int t) { visit_time = t; }
    void set_post_visit_time (int t) { post_visit_time = t; }
    void set_is_visited (Color v) { is_visited = v; }
    void set_data (std::shared_ptr<T>& d) {data = d;}

    friend std::ostream& operator<< (std::ostream& out, const GraphNode<T>& gn) {
        out << "{" << *gn.data << "(" << gn.pre_visit_time << ", " <<
            gn.post_visit_time << ", " <<gn.is_visited <<")" << "}";
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
        << (*e.to) << ", " << e.weights[0] << ") ";
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
        auto explore_cycle(std::shared_ptr<GraphNode<T>> curr, std::shared_ptr<GraphNode<T>> prev);

        void topoSort(std::shared_ptr<GraphNode<T>>& node, std::stack<std::shared_ptr<GraphNode<T>>>& S, int& time);
        void topoSortParallel(std::shared_ptr<GraphNode<T>>& node, std::vector<std::vector<std::shared_ptr<GraphNode<T>>>>& parallel, int depth, int& time);
        
    public:
        Graph() {};
        void load_from_file (const std::string& filename);
        void add_edge (const T& from, const T& to, const int w = 1);
        void add_edge(const std::shared_ptr<GraphNode<T>> from, 
                const std::shared_ptr<GraphNode<T>> to, const int weight = 1);
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


        auto dijkstra_with_fewest_edges (const T& start) {
            if(nodes.find(start) == nodes.end()) {
                throw std::logic_error("dijkstra: node is not present");
            }
            return dijkstra_with_fewest_edges(nodes[start]);
        }
        auto dijkstra_with_fewest_edges (std::shared_ptr<GraphNode<T>>& start);


        auto bellman_ford (const T& start) {
            if(nodes.find(start) == nodes.end()) {
                throw std::logic_error("dijkstra: node is not present");
            }
            return bellman_ford(nodes[start]);
        }

        auto kruskal_min_spanning_tree();
        auto bellman_ford (const std::shared_ptr<GraphNode<T>>& start);

        auto is_cycle ();
        
        std::stack<std::shared_ptr<GraphNode<T>>> topoSort();
        auto longest_path(const T& start) {
            auto&node =  nodes[start];
            if(!node) {
                nodes.erase(start);
                throw std::logic_error("Node not present");
            } else {
                return longest_path(node);
            }
        };

        std::vector<std::vector<std::shared_ptr<GraphNode<T>>>> topoSortParallel() {
            reset_nodes_status();
            auto S = topoSort(); //find the first node;
            std::vector<std::vector<std::shared_ptr<GraphNode<T>>>> res;
            int depth = 0;
            int time = 0;
            reset_nodes_status();
            topoSortParallel(S.top(),res, 0, time);

            //process the rest of the graph
            for (auto& node_pair: nodes) {
                auto node = node_pair.second;
                if (node->is_visited == Color::WHITE) {
                    topoSortParallel(node,res, 0, time);
                }
            }
            return res;
        }


        auto longest_path(const std::shared_ptr<GraphNode<T>>& start);


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
void Graph<T>::add_edge(const std::shared_ptr<GraphNode<T>> from, 
        const std::shared_ptr<GraphNode<T>> to, const int weight)
{
    auto& edge = edges[std::pair<T,T>{*from->data, *to->data}];
    if (!edge) {
        edge = std::make_shared<Edge<T>>(Edge<T>{from, to});
    }
    edge->weights.emplace_back(weight);
    from->adj_list.emplace_back(edge);
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
void Graph<T>::add_edge(const T& a, const T& b, const int w)
{
    auto &node_a = nodes[a];
    if (!node_a) {
        auto a_node_ptr = std::make_shared<T>(a);
        node_a = std::make_shared<GraphNode<T>>(a_node_ptr);
    }
    auto& node_b = nodes[b];
    if (!node_b) {
        auto b_node_ptr = std::make_shared<T>(b);
        node_b = std::make_shared<GraphNode<T>>(b_node_ptr);
    }
    add_edge(node_a, node_b, w);
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
    int w;
    while (getline(input_file, line)) {
        if (line.size() > 1) {
            std::stringstream ss(line);
            ss >> a; ss >> b; ss >> w;
            add_edge(a, b, w);
        }
    }
    for (auto& edge: edges) {
        std::sort(edge.second->weights.begin(), edge.second->weights.end());
    }
}

template <class T>
template <class U>
void Graph<T>::explore(std::shared_ptr<GraphNode<T>>& curr, int& time, U& u)
{
    if (curr->is_visited != Color::WHITE) {
        throw std::logic_error("Visiting an already visited node");
    }
    curr->pre_visit_time = time++;
    curr->is_visited = Color::GREY;
    u(curr);
    for (auto& edge: curr->adj_list) {
        if (edge->from != curr) {
            throw std::logic_error("source edge node differes from current node");
        }
        if (edge->to->is_visited == Color::WHITE) {
            explore(edge->to, time, u);
        }
    }
    curr->is_visited = Color::BLACK;
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
            if(start->is_visited == Color::WHITE) {
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
    curr->is_visited = Color::BLACK;
    while(!curr->adj_list.empty()) {
        auto& e = curr->adj_list.front();
        if (e->to->is_visited == Color::WHITE) {
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
        if (Color::WHITE == start->is_visited) {
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
        if(node->is_visited == Color::WHITE) {
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

    return distance;
}


template <class T>
auto Graph<T>::dijkstra (const std::shared_ptr<GraphNode<T>>& start)
{
    auto pq_cmp = [] (const auto& a, const auto& b) {
        return a.second > b.second;
    };
    std::unordered_map<std::shared_ptr<GraphNode<T>>,
        std::tuple<std::shared_ptr<GraphNode<T>>, int>> dist;
    std::priority_queue< std::pair<std::shared_ptr<GraphNode<T>>, int>,
            std::vector< std::pair<std::shared_ptr<GraphNode<T>>, int>>,
        decltype(pq_cmp)> Q(pq_cmp);

    Q.push(std::make_pair(start, 0));
    dist[start] = std::make_tuple<std::shared_ptr<GraphNode<T>>, int>(nullptr, 0);
    while (!Q.empty()) {
        auto curr = Q.top(); Q.pop();
        auto curr_node = curr.first;
        auto curr_dist = curr.second;
        for (const auto& edge: curr_node->adj_list) {
            if (edge->to == start) {
                continue;
            }
            auto candidate_dist_it = dist.find(edge->to);
            if (candidate_dist_it == dist.end()) {
                auto candidate_dist = curr_dist + edge->weights.front();
                dist[edge->to] = std::make_tuple(curr_node, candidate_dist);
                Q.push(std::make_pair(edge->to, candidate_dist));
            } else {

                int candidate_dist = curr_dist + edge->weights.front();
                int curr_min_dist = std::get<1>(candidate_dist_it->second);
                if (candidate_dist < curr_min_dist) {
                    dist[edge->to] = std::make_tuple(curr_node, candidate_dist);
                    Q.push(std::make_pair(edge->to, candidate_dist));
                }
            }
        }
    }
    return dist;
}

template <class T>
auto Graph<T>::kruskal_min_spanning_tree (void)
{
    Union<GraphNode<T>> U;
    std::vector<std::shared_ptr<Edge<T>>>tmp_edges;
    for (const auto& node_pair: nodes) {
        U.makeset(node_pair.second);
    }
    for (const auto& edge: edges) {
        tmp_edges.emplace_back(edge.second);
    }
    std::sort(tmp_edges.begin(), tmp_edges.end(),
            [](const auto& lhs, const auto& rhs){
                return lhs->weights[0] < rhs->weights[0];
            });

    std::vector<std::shared_ptr<Edge<T>>> min_tree;
    for (const auto& e: tmp_edges) {
        const auto to = U.find(e->to);
        const auto from = U.find(e->from);
        if (to != from) {
            min_tree.emplace_back(e);
            U.union_find(e->to, e->from);
        }
    }
    return min_tree;

}


template <class T>
auto Graph<T>::bellman_ford (const std::shared_ptr<GraphNode<T>>& start)
{
    std::unordered_map<std::shared_ptr<GraphNode<T>>, 
        std::tuple<std::shared_ptr<GraphNode<T>>, long>> dist;
    for (const auto& node: nodes) {
        dist[node.second] = std::make_tuple<std::shared_ptr<GraphNode<T>>, long>(nullptr, 
                std::numeric_limits<int>::max());
    }
    std::get<1>(dist[start]) = 0;
    for (int i = 0; i < nodes.size() - 1; ++i) {
        for (const auto& edge_pair: edges) {
            auto& edge= edge_pair.second;
            auto from = edge->from;
            auto to = edge->to;
            auto &prev = std::get<0>(dist[to]);
            auto &curr_min = std::get<1>(dist[to]);
            if (curr_min > edge->weights.front() + std::get<1>(dist[from])) {
                curr_min = edge->weights.front() + std::get<1>(dist[from]);
                prev = from;
            }
        }
    }

    return dist;
}


template<class T>
auto Graph<T>::explore_cycle(std::shared_ptr<GraphNode<T>> curr, const std::shared_ptr<GraphNode<T>> prev)
{
    if (curr->is_visited == Color::GREY) {
        return true;
    }
    curr->is_visited = Color::GREY;
    for (auto& edge: curr->adj_list) {
        auto to = edge->to;
        if (curr != prev && to->is_visited != Color::BLACK) {
            if(explore_cycle(to, curr)) {
                return true;
            }
        }
    }
    curr->is_visited = Color::BLACK;
    return false;
}


template <class T>
auto Graph<T>::is_cycle ()
{
    reset_nodes_status();
    for (auto& node_pair: nodes) {
        auto node = node_pair.second;
        if (node->is_visited == Color::WHITE) {
            if(explore_cycle(node, nullptr)) {
                return true;
            }
        }
    }
    return false;

}


template <class T>
void Graph<T>::topoSort(std::shared_ptr<GraphNode<T>>& node,
        std::stack<std::shared_ptr<GraphNode<T>>>& S, int& time)
{
    node->set_pre_visit_time(time++);
    node->is_visited = Color::BLACK;
    for (auto edge: node->adj_list) {
        auto to = edge->to;
        if (to->is_visited == Color::WHITE) {
            topoSort(to, S, time);
        }
    }
    node->set_post_visit_time(time++);
    S.push(node);
}


template <class T>
std::stack<std::shared_ptr<GraphNode<T>>> Graph<T>::topoSort()
{
    reset_nodes_status();
    int time = 0;
    std::stack<std::shared_ptr<GraphNode<T>>> S;
    for (auto& node_pair: nodes) {
        auto& node = node_pair.second;
        if(node->is_visited == Color::WHITE) {
            topoSort(node, S, time);
        }
    }
    return S;
}



template <class T>
auto Graph<T>::longest_path(const std::shared_ptr<GraphNode<T>>& start)
{
    auto S = topoSort();



    std::unordered_map<std::shared_ptr<GraphNode<T>>, int> dist;
    for (const auto& node_pair: nodes){
        dist[node_pair.second] = std::numeric_limits<int>::min(); //inf dist
    }
    dist[start] = 0;

    while (!S.empty()) {
        auto curr_node = S.top();
        for (const auto& edge: curr_node->adj_list) {
            auto& to = edge->to;
            if (dist[to] < dist[curr_node] + edge->weights.back()) {
                dist[to] = dist[curr_node] + edge->weights.back();
            }
        }
        S.pop();
    }
    return dist;
}


template <class T>
void Graph<T>::topoSortParallel(std::shared_ptr<GraphNode<T>>& node, std::vector<std::vector<std::shared_ptr<GraphNode<T>>>>& parallel, int depth, int& time)
{
    node->is_visited = Color::BLACK;
    node->set_pre_visit_time(time++);
    if (depth >= parallel.size()) {
        parallel.emplace_back(std::vector<std::shared_ptr<GraphNode<T>>>());
        if (depth >= parallel.size()) {
            throw std::logic_error("Something is wrong...");
        }
    }
    parallel[depth].emplace_back(node);
    for (auto& edge: node->adj_list) {
        auto& to = edge->to;
        if (to->is_visited == Color::WHITE) {
            topoSortParallel(to, parallel, depth+1, time);
        }
    }
    node->set_post_visit_time(time++);
    return;

}


template <class X, class Y, class Z>
std::ostream& operator<< (std::ostream& out, const std::tuple<std::shared_ptr<X>,Y,Z>& t)
{
    out << "(" << *std::get<0>(t) << ", " << std::get<1>(t) << ", " <<std::get<2>(t) << ")";
    return out;
}

template <class T>
auto Graph<T>::dijkstra_with_fewest_edges (std::shared_ptr<GraphNode<T>>& start)
{
    auto cmp = [](const auto& a, const auto& b) {
        auto d_a = std::get<1>(a);
        auto d_b = std::get<1>(b);
        if (d_a > d_b) {
            return true;
        } else if (d_a == d_b) {
            return std::get<2>(a) > std::get<2>(b);
        } else {
            return false;
        }
    };

    std::unordered_map<std::shared_ptr<GraphNode<T>>,
        std::tuple<std::shared_ptr<GraphNode<T>>, int, int>> dist;
    std::priority_queue<
        std::tuple<std::shared_ptr<GraphNode<T>>, int, int>,
        std::vector<std::tuple<std::shared_ptr<GraphNode<T>>, int, int>>,
        decltype(cmp)> Q(cmp);

    auto first = std::make_tuple(start, 0, 0);
    Q.push(first);
    dist[start] =std::make_tuple<std::shared_ptr<GraphNode<T>>, int, int>(nullptr, 0, 0);
    while (!Q.empty()) {
        auto curr_elem = Q.top(); Q.pop();
        auto curr_node = std::get<0>(curr_elem);
        auto curr_dist = std::get<1>(curr_elem);
        auto curr_n_edges = std::get<2>(curr_elem);
        for (const auto& edge: curr_node->adj_list) {
            auto to = edge->to;
            if (to == start) {
                continue;
            }
            auto it = dist.find(to);
            if (it == dist.end()) {
                dist[to] = std::make_tuple(curr_node, curr_dist + edge->weights.front(), curr_n_edges + 1);
                Q.push(std::make_tuple(to, curr_dist + edge->weights.front(), curr_n_edges + 1));
            } else {
                auto candidate = std::make_tuple(to, curr_dist + edge->weights.front(), curr_n_edges + 1);

                if (cmp(dist[to], candidate)) {
                    Q.push(candidate);
                    dist[to] = std::make_tuple(curr_node, curr_dist + edge->weights.front(), curr_n_edges + 1);
                }
            }
        }

    }
    return dist;
}
