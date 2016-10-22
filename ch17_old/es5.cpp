#include <iostream>
#include <tuple>
#include <vector>
#include <list>
#include "../utils.hpp"


using XY_t = std::tuple<int,int>;

std::list<XY_t> find_max_path (const std::vector<std::vector<int>>& sea)
{
    std::vector<std::vector<int>> K(sea.size(), std::vector<int>(
                sea.size() ? sea[0].size() : sea[0].size(), 0));
    for (int i = 0; i < sea.size(); ++i) {
        for (int j = 0; j < sea[0].size(); ++j) {
            K[i][j] = sea[i][j] + 
                std::max(i > 0 ? K[i-1][j] : 0, j > 0 ? K[i][j-1] : 0);
        }
    }
    int i = sea.size() - 1, j = sea.size() ? sea[0].size() - 1: -1;
    std::list<XY_t> path;
    while (i > 0 && j > 0) {
        path.push_front(std::make_tuple(i, j));
        if(K[i][j] - sea[i][j] == K[i-1][j]) {
            --i;
        } else {
            --j;
        }
    }
    while(i) {
        path.push_front(std::make_tuple(i, j));
        --i;
    }
    while(j) {
        path.push_front(std::make_tuple(i, j));
        --j;
    }
    path.push_front(std::make_tuple(i,j));
    return path;
}

int main (void)
{
    /*
    std::vector<std::vector<int>> sea = {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
    };
    */
    std::vector<std::vector<int>> sea1 = {
        {1, 0, 0, 0, 0},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
    };

    auto path = find_max_path(sea1);
    std::cout << path << std::endl;
    return 0;
}
