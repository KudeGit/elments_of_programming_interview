#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <queue>
#include <limits>
#include "../utils.hpp"

using XY_t = std::pair<int,int>;

struct HashPair {
    size_t operator() (const XY_t &a) const {
        return std::hash<int>()(a.first) ^ std::hash<int>()(a.second);
    }
};

struct PairEqual {
    bool operator() (const XY_t &lhs, const XY_t& rhs) {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
};


static std::vector<XY_t> moves{{1,0}, {0,1}, {-1, 0}, {0, -1}};
XY_t operator+ (const XY_t& op1, const XY_t& op2) {
    return std::make_pair(op1.first + op2.first, op1.second + op2.second);
}

static inline auto is_a_valid_pos (const XY_t& pos, const std::vector<std::vector<int>>& A)
{
    int N = A.size();
    int M = A[0].size();
    return pos.first >= 0 && pos.first < N && pos.second >= 0 && pos.second < M;
}

bool find_exit (const std::vector<std::vector<int>>& A, const XY_t pos,
        std::unordered_set<XY_t, HashPair, PairEqual>& is_visited, std::vector<XY_t>& path)
{
    is_visited.insert(pos);
    if (A[pos.first][pos.second] == 2) {
        path.emplace_back(pos);
        return true;
    }
    for (const auto& m: moves) {
        auto next_pos = m + pos;
        if (is_a_valid_pos(next_pos, A) && is_visited.find(next_pos) == is_visited.end()) {
            if (A[next_pos.first][next_pos.second] != 1) {
                auto is_exit_found = find_exit(A, next_pos, is_visited, path);
                if (is_exit_found) {
                    path.emplace_back(pos);
                    return true;
                }
            }
        }
    }
    return false;
}

void find_exit (const std::vector<std::vector<int>>& A, const XY_t start)
{
    std::vector<XY_t> path;
    std::unordered_set<XY_t, HashPair, PairEqual> is_visited;
    find_exit(A, start, is_visited, path);
    std::reverse(path.begin(), path.end());
    std::cout << path << std::endl;
    return;
}



void find_exit_bfs (const std::vector<std::vector<int>>& A, const XY_t start)
{
    int N = A.size();
    int M = A[0].size();
    auto idx = [&](const XY_t curr_pos) {return curr_pos.first*M + curr_pos.second;};
    std::queue<XY_t> Q;
    std::vector<long> dist(N*M, std::numeric_limits<int>::max());
    std::vector<XY_t> prev(N*M, {-1,-1});
    dist[idx(start)] = 0;
    Q.push(start);
    auto exit = start;
    while (!Q.empty()) {
        auto curr_pos = Q.front(); Q.pop();
        if (A[curr_pos.first][curr_pos.second] == 2) {
            exit = curr_pos;
            break;
        }
        for (const auto& m: moves) {
            auto next_pos = m + curr_pos;
            if (is_a_valid_pos(next_pos, A) && dist[idx(next_pos)] > dist[idx(curr_pos)] + 1) {
                if(A[next_pos.first][next_pos.second] != 1) {
                    Q.push(next_pos);
                    dist[idx(next_pos)] = dist[idx(curr_pos)] + 1;
                    prev[idx(next_pos)] = curr_pos;
                }
            }
        }
    }
    std::cout << "Exit " << exit << " reached in " << dist[idx(exit)] << std::endl;
    auto curr_pos = exit;
    while (curr_pos.first != -1 && curr_pos.second != -1) {
        std::cout << curr_pos << ", ";
        curr_pos = prev[idx(curr_pos)];
    }
    return;

}

int main (void)
{
    std::vector<std::vector<int>> A= {
        {1, 0, 0, 0, 0, 0, 1, 1, 0, 2},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0},
    };
    auto start =  std::pair<int, int>{9,0};
   // find_exit(A, start);
    find_exit_bfs(A, start);
    return 0;
}

