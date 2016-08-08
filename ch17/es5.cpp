#include <iostream>
#include <vector>
#include "../utils.hpp"



template <size_t N, size_t M>
long get_max_fish_path (int (&A)[N][M])
{
    int K[N][M] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            K[i][j] = std::max(i >= 1 ? K[i-1][j] : 0,
                    j >= 1 ? K[i][j-1] : 0) + A[i][j];
        }
    }
    return K[N-1][M-1];
}


int main (void)
{
    int A[5][5] = {
        {1,1,1,1,1},
        {0,0,0,0,1},
        {0,0,100,0,1},
        {2,0,0,0,1},
        {1,1,0,0,1}};
    //int A[5][5] = {
    //    {0,0,1,1,0},
    //    {0,1,2,0,1},
    //    {0,1,1,1,1},
    //    {2,0,1,0,2},
    //    {1,1,1,0,2}};

    auto res = get_max_fish_path(A);
    std::cout << res << std::endl;
    return 0;
}

