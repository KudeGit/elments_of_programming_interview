#include <iostream>
#include <vector>

int count_n_ways_to_traverse_2d_array (const int N, const int M)
{
    std::vector<std::vector<int>> K(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        K[i][0] = 1;
    }
    for (int j = 0; j < M; ++j) {
        K[0][j] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            K[i][j] = K[i-1][j] + K[i][j-1];
        }
    }
    return K.back().back();
}

int count_n_ways_to_traverse_2d_array (const std::vector<std::vector<bool>>& A)
{
    auto N = A.size();
    auto M = A[0].size();
    std::vector<std::vector<int>> K(N, std::vector<int>(M, 0));
    
    for (int i = 0; i < N; ++i) {
        K[i][0]= A[i][0] == true ? 1 : 0;
    }
    for (int i = 0; i < N; ++i) {
        K[0][i]= A[0][i] == true ? 1 : 0;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            K[i][j] = A[i][j] ? K[i-1][j] + K[i][j-1] : 0;
        }
    }
    return K.back().back();
}
int main (void)
{
    auto res = count_n_ways_to_traverse_2d_array(3,3);
    std::cout << res << std::endl;
    return 0;
}
