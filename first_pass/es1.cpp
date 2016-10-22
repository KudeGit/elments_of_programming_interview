#include <iostream>
#include <array>
#include <tuple>
#include <limits>
#include <unordered_map>
#include <queue>
#include <functional>
#include "../utils.hpp"



template <size_t N, size_t M>
using maze_t = std::array<std::array<int, N>, M>;

using XY_t = std::tuple<int, int>;

template <size_t N, size_t M>
bool check_valid_step (const int x, const int y, const maze_t<N,M>& maze)
{
    auto is_valid = (x >= 0 && x < maze.size() &&
            y >= 0 && y < maze[0].size() &&
            maze[x][y] != -1 &&
            maze[x][y] != 2);
    return is_valid;
}

std::array<std::tuple<int, int>, 4> moves = {{
    {1, 0},{-1, 0}, {0, 1}, {0, -1}
}};

template <size_t N, size_t M>
bool find_path_helper (int x, int y,
        std::vector<XY_t>& path, maze_t<N,M>& maze)
{
    if (maze[x][y] == 1) {
        path.push_back(std::make_tuple(x,y));
        return true;
    }

    maze[x][y] = 2; //mark as visited
    bool found_path = false;
    path.push_back(std::make_tuple(x,y));

    for (const auto& move: moves) {
        auto next_x = x + std::get<0>(move);
        auto next_y = y + std::get<1>(move);
        if (check_valid_step(next_x, next_y, maze)) {
            found_path = find_path_helper(next_x, next_y,
                    path, maze);
            if (found_path) {
                return true;
            }
        }
    }
    path.pop_back();
    return false;
}


template <size_t N, size_t M>
std::vector<XY_t> find_exit (XY_t start, maze_t<N,M>& maze)
{
    std::vector<XY_t> path;
    auto exit_found = find_path_helper(std::get<0>(start), std::get<1>(start), path, maze);
    if (!exit_found) {
        throw std::invalid_argument("Could not find an exit");
    }
    return path;
}


template <size_t M>
struct tuple_hash {
    size_t operator()(const XY_t& a) const {
        return std::hash<int>()(std::get<0>(a)*M+std::get<1>(a));
    };
};

struct key_equal {
    bool operator()(const XY_t& a, const XY_t& b) const {
        return std::get<0>(a) == std::get<0>(b) &&
            std::get<1>(a) == std::get<1>(b);
    }
};


template <size_t N, size_t M>
std::vector<XY_t> find_shortest_path(maze_t<N,M>& maze, XY_t start)
{
    std::array<int,N*M> dist;
    for (auto& d: dist) {
        d = std::numeric_limits<int>::max(); //x*maze[0].size() + y;
    }


    key_equal test;
    std::unordered_map<XY_t, XY_t,
        tuple_hash<M>, key_equal> prev;
    prev[start] = std::make_tuple(-1,-1);
    auto get_index = [&](const int x, const int y) {
        int idx = x * maze[0].size() + y;
        if (idx < 0 || idx >= dist.size()) {
            throw std::logic_error("out of bound index");
        }
        return idx;
    };

    dist[get_index(std::get<0>(start), std::get<1>(start))] = 0;
    std::queue<XY_t> Q;
    Q.push(start);
    auto exit = std::make_tuple(-1,-1);
    while (!Q.empty()) {
        auto current = Q.front();
        auto x = std::get<0>(current);
        auto y = std::get<1>(current);
        Q.pop();
        if (maze[x][y] == 1) {
            exit = current;
            break;
        }
        for (auto const& move: moves) {
            auto next_x = x + std::get<0>(move);
            auto next_y = y + std::get<1>(move);
            if (next_x >= 0 && next_x < maze.size() && 
                    next_y >=0 && next_y < maze[0].size() &&
                    maze[next_x][next_y] != -1) {
                if (dist[get_index(next_x, next_y)] == std::numeric_limits<int>::max()) {
                    dist[get_index(next_x, next_y)] = dist[get_index(x,y)] + 1;
                    auto next_node = std::make_tuple(next_x, next_y);
                    prev[next_node] = std::make_tuple(x,y);
                    Q.push(next_node);
                }
            }
        }
    }


    std::vector<XY_t> res;
    do {
        res.push_back(exit);
        exit = prev[exit];
    } while (std::get<0>(exit) != -1 && std::get<1>(exit) != -1);
    std::reverse(res.begin(), res.end());
    return res;

}


int main (void)
{
    maze_t<10, 10> A = {{
        {{-1, 0, 0, 0, 0, 0,-1,-1, 0, 1}},
        {{ 0, 0,-1, 0, 0, 0, 0, 0, 0, 0}},
        {{-1, 0,-1, 0, 0,-1,-1, 0,-1,-1}},
        {{ 0, 0, 0,-1,-1,-1, 0, 0,-1, 0}},
        {{ 0,-1,-1, 0, 0, 0, 0, 0, 0, 0}},
        {{ 0,-1,-1, 0, 0,-1, 0,-1,-1, 0}},
        {{ 0, 0, 0, 0,-1, 0, 0, 0, 0, 0}},
        {{-1, 0,-1, 0,-1, 0,-1, 0, 0, 0}},
        {{-1, 0,-1,-1, 0, 0, 0,-1,-1,-1}},
        {{ 0, 0, 0, 0, 0, 0, 0,-1,-1, 0}},
    }};
    //auto exit = find_exit(std::make_tuple(9,0), A);
    auto shortest_path = find_shortest_path(A, std::make_tuple(9,0));
    //std::cout << exit << std::endl;
    std::cout << shortest_path << std::endl;
    return 0;
}

