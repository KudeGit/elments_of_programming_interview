#include <iostream>
#include <vector>
#include "../utils.hpp"

void print_triangle (const std::vector<std::vector<int>>& triangle)
{
    for (const auto& row: triangle){
        std::cout << row << std::endl;
    }
}

std::vector<std::vector<int>> pascal_triagle(int n)
{
    std::vector<std::vector<int>> res(n, std::vector<int>());
    res[0] = std::vector<int>(1, 1);
    for (int i = 1; i < n; ++i) {
        res[i] = std::vector<int>(i+1, 0);
        res[i][0] = 1;
        res[i].back() = 1;
        for (int j = 1; j<res[i].size()-1; ++j) {
            res[i][j] = res[i-1][j-1]+res[i-1][j];
        }
    }
    return res;
}


int main (void)
{
    auto triangle = pascal_triagle(5);
    print_triangle(triangle);
    return 0;
}
