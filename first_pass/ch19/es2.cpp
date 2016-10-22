#include <iostream>
#include <vector>
#include <unordered_set>
#include "../utils.hpp"

//enum class Color : bool {black, white};

using XY_t = std::pair<int,int>;


namespace std {
    template <>
    struct hash<XY_t> {
        size_t operator() (const XY_t& xy) const {
            return std::hash<int>()(xy.first) ^ std::hash<int>() (xy.second);
        }
    };
    template <>
    struct equal_to<XY_t> {
        bool operator()( const XY_t& lhs, const XY_t& rhs ) const {
            return lhs.first == rhs.first && lhs.second == rhs.second;
        }
    };
}


static inline bool is_valid_position (const XY_t& a, size_t N, size_t M)
{
    return (a.first >= 0  && a .first < N) && (a.second >= 0 && a.second < M);
}

static void flip_area (std::vector<std::vector<bool>>& canvas, const XY_t& pos, const bool c)
{
    const XY_t available_moves[] = {{-1, 0}, {1, 0}, {0, -1}, {-0, 1}};
    canvas[pos.first][pos.second] = !canvas[pos.first][pos.second];

    for (const auto& move: available_moves) {
        XY_t next_pos{move.first + pos.first, move.second + pos.second};
        //is a valid position, is not visited yet and is the same color
        if (is_valid_position(next_pos, canvas.size(), canvas[0].size()) && canvas[next_pos.first][next_pos.second] == c) {
            flip_area (canvas, next_pos, c);
        }
    }
}

void flip_area (std::vector<std::vector<bool>>& canvas, const XY_t& pos)
{
    //it is okay, but for performance it is probably better to use a bit array
    if(is_valid_position(pos, canvas.size(), canvas[0].size())) {
        //std::unordered_set<XY_t> is_visited;
        flip_area (canvas, pos, canvas[pos.first][pos.second]);
    }
}




int main (void)
{
    std::vector<std::vector<bool>> canvas = {
        {0,0,0,0}};
    std::cout << canvas << std::endl;
    flip_area(canvas, {0,0});
    std::cout << canvas << std::endl;
    flip_area(canvas, {0,0});
    std::cout << canvas << std::endl;


    std::vector<std::vector<bool>> canvas2 = {
        {0,0,0,0},
        {0,0,0,0},
        {0,0,0,0}};
    std::cout << canvas2 << std::endl;
    flip_area(canvas2, {2,1});
    std::cout << canvas2 << std::endl;




    std::vector<std::vector<bool>> canvas3 = {
        {0,0,0,0},
        {1,0,1,0},
        {0,1,1,0},
        {0,0,0,0}};
    std::cout << canvas3 << std::endl;
    flip_area(canvas3, {1,2});
    std::cout << canvas3 << std::endl;

    return 0;
}

