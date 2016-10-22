#include <iostream>
#include <vector>
#include <unordered_set>
#include <stdexcept>
#include <queue>
#include "../utils.hpp"


using XY_t = std::pair<int,int>;
namespace std {
    template <>
    struct hash<XY_t> {
        size_t operator() (const XY_t& xy) const {
            return std::hash<int>() (xy.first) ^ std::hash<int>() (xy.second);
        }
    };
    template <>
    struct equal_to<XY_t> {
        bool operator() (const XY_t& lhs, const XY_t& rhs) {
            return lhs.first == rhs.first&& lhs.second == rhs.second;
        }
    };
}

//can be extended passing color... next time :)
//0: black
//1: white
//
//
static const
XY_t moves[] = {{-1,0}, {1, 0}, {0,1}, {0,-1}};

static inline
bool is_valid_pos (const XY_t& pos, int N, int M)
{
    return (pos.first >= 0 && pos.first < N) && (pos.second >= 0 && pos.second < M);
}

static
void explore(const std::vector<std::vector<bool>>& canvas, const XY_t& pos, const bool color, 
        std::unordered_set<XY_t>& is_visited)
{
    if (is_visited.find(pos) != is_visited.end()) {
        throw std::logic_error("vertex already visted");
    }
    is_visited.insert(pos);

    for (const auto& m: moves) {
        XY_t next_pos{m.first + pos.first, m.second + pos.second};
        if (is_valid_pos(next_pos, canvas.size(), canvas[0].size())) {
            if (canvas[next_pos.first][next_pos.second] == color && is_visited.find(next_pos) == is_visited.end()) {
                explore(canvas, next_pos, color, is_visited);
            }
        }
    }
}

static
std::unordered_set<XY_t> find_boundary_regions (const std::vector<std::vector<bool>>& canvas, const bool color)
{
    std::unordered_set<XY_t> reacheable_pos;
    auto N = canvas.size();
    auto M = canvas[0].size();
    for (int i = 0; i < N; ++i) {
        //first column
        if (canvas[i][0] == color && reacheable_pos.find({i, 0}) == reacheable_pos.end()) {
            explore(canvas, {i, 0}, color, reacheable_pos);
        }
        //last coulmn
        if (canvas[i][M-1] == color && reacheable_pos.find({i, M-1}) == reacheable_pos.end()) {
            explore(canvas, {i, M-1}, color, reacheable_pos);
        }
    }
    for (int j = 0; j< M; ++j) {
        if (canvas[0][j] == color && reacheable_pos.find({0, j}) == reacheable_pos.end()) {
            explore(canvas, {0, j}, color, reacheable_pos);
        }
        if (canvas[N-1][j] == color && reacheable_pos.find({N-1, j}) == reacheable_pos.end()) {
            explore(canvas, {N-1, j}, color, reacheable_pos);
        }
    }
    return reacheable_pos;
}

//let's do bfs this time :)
static 
void flip_color(std::vector<std::vector<bool>>& canvas, const XY_t& start, bool color)
{
    std::queue<XY_t> Q;
    Q.push(start);
    while (!Q.empty()) {
        auto pos = Q.front(); Q.pop();
        canvas[pos.first][pos.second] = !canvas[pos.first][pos.second];
        for (const auto& m: moves) {
            auto candidate_pos = XY_t{m.first + pos.first, m.second + pos.second};
            if(is_valid_pos(candidate_pos, canvas.size(), canvas[0].size())) {
                if (canvas[candidate_pos.first][candidate_pos.second] == color) {
                    Q.push(candidate_pos);
                }
            }
        }
    }
}

void fill_regions (std::vector<std::vector<bool>>& canvas, const bool color)
{
    auto colored_boundary_regions = find_boundary_regions(canvas, color);
    for (int i = 1; i < canvas.size() - 1; ++i) {
        for (int j = 1; j < canvas[0].size() - 1; ++j) {
            auto is_not_boundary = colored_boundary_regions.find({i, j}) == colored_boundary_regions.end();
            if (is_not_boundary && canvas[i][j] == color) {
                flip_color(canvas, {i,j}, color);
            }
        }
    }
}

int main (void)
{
    std::vector<std::vector<bool>> canvas = {
        {0,0,0,0}};
    std::cout << canvas << std::endl;
    fill_regions(canvas, 0);
    std::cout << canvas << std::endl;
    fill_regions(canvas, 1);
    std::cout << canvas << std::endl;


    std::vector<std::vector<bool>> canvas2 = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}};
    std::cout << canvas2 << std::endl;
    fill_regions(canvas2, 0);
    std::cout << canvas2 << std::endl;
    fill_regions(canvas2, 0);
    std::cout << canvas2 << std::endl;




    std::vector<std::vector<bool>> canvas3 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}};
    std::cout << canvas3 << std::endl;
    banner("Filling 0 regions with 1");
    fill_regions(canvas3, 0);
    std::cout << canvas3 << std::endl;
    banner("Filling 1 regions with 0");
    fill_regions(canvas3, 1);
    std::cout << canvas3 << std::endl;

    return 0;
}
