#include <iostream>
#include <vector>
#include <limits>
#include "../../utils.hpp"

int minimumTotal (const std::vector<std::vector<int>>& T)
{
    std::vector<std::vector<int>> K(2,
            std::vector<int>(T.size(), std::numeric_limits<int>::max()));
    if (T.empty()) {
        return 0;
    }

    K[0][0] = T[0][0];
    for (int ii = 1; ii < T.size(); ++ii) {
        for (int jj = 0; jj <= ii; ++jj) {
            auto i = ii & 0x01;
            auto i_1 = i == 1 ? 0 : 1;
            auto j = jj;

            auto prev1 = K[i_1][j];
            auto prev2 = j > 0 ? K[i_1][j-1] : std::numeric_limits<int>::max();

            K[i][j] = T[ii][jj]+std::min(prev1, prev2);
        }
    }
    auto min_path = std::numeric_limits<int>::max();
    for (auto p: K[(T.size()-1) & 0x01]) {
        min_path = std::min(p, min_path);
    }
    return min_path;
}

int main (void)
{
    //std::vector<std::vector<int>> T{{-10}};
    //auto res = minimumTotal(T);
    //debug(res);

    std::vector<std::vector<int>> T = {{2},
        {3,4},
        {6,5,7},
        {4,1,8,3}};
    auto res = minimumTotal(T);
    debug(res);

    return 0;
}



