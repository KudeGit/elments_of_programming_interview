#include <iostream>
#include <vector>
#include <utility>
#include "../../utils.hpp"

std::pair<int, std::vector<std::pair<int,int>>> plan_fisherman_trip (const std::vector<std::vector<int>>& A)
{
    auto N = A.size();
    auto M = A[0].size();
    std::vector<std::vector<int>> K(N, std::vector<int>(M, 0));
    std::vector<std::vector<std::pair<int, int>>> paths(N, 
            std::vector<std::pair<int,int>>(M, {0,0}));
    K[0][0] = A[0][0];
    paths[0][0] = {-1,-1};
    for (int i = 1; i < N; ++i) {
        K[i][0] = K[i-1][0] + A[i][0];
        paths[i][0] = {i-1, 0};
    }

    for (int j = 1; j < M; ++j) {
        K[0][j] = K[0][j-1] + A[0][j];
        paths[0][j] = {0, j-1};
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            if (K[i-1][j] > K[i][j-1]) {
                K[i][j] = K[i-1][j] + A[i][j];
                paths[i][j] = {i-1, j};
            } else {
                K[i][j] = K[i][j-1] + A[i][j];
                paths[i][j] = {i, j-1};
            }
        }
    }
    std::vector<std::pair<int,int>> best_path;
    std::pair<int, int> curr_pos = {N-1, M-1};

    while (curr_pos != paths[0][0]) {
        best_path.emplace_back(curr_pos);
        curr_pos = paths[curr_pos.first][curr_pos.second];
    };
    std::reverse(best_path.begin(), best_path.end());

    return {K.back().back(), best_path};
}


int main (void)
{
    std::vector<std::vector<int>> A = {
        {1,1,1,1,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {0,0,0,0,1},
        {1000,0,0,0,1}
    };

    auto res = plan_fisherman_trip(A);
    debug(A);
    debug(res.first);
    debug(res.second);
    return 0;
}
