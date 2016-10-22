#include <iostream>
#include <vector>

int count_path (const size_t N, const size_t M)
{
    std::vector<std::vector<int>> K(N, std::vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        K[i][0] = 1;
    }
    for (int i = 0; i < M; ++i) {
        K[0][i] = 1;
    }
    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            K[i][j] = K[i-1][j] + K[i][j-1];
        }
    }
    return K.back().back();
}

int count_path_with_obstacle (const std::vector<std::vector<bool>> &A)
{
    if(A.empty()) {
        throw std::invalid_argument("empty matrix");
    }
    std::vector<std::vector<int>> K(A.size(), std::vector<int>(A[0].size(), 0));
    if(!A[0][0]) {
        throw std::invalid_argument("starting position contains an obstacle");
    }
    const size_t N = A.size(), M = A[0].size();
    K[0][0] = 1;
    for (int i = 1; i < N; ++i) {
        K[i][0] = A[i][0] == true ? K[i-1][0] : 0;
    }
    for (int j = 1; j < M; ++j) {
        K[0][j] = A[0][j] == true ? K[0][j-1] : 0;
    }

    for (int i = 1; i < N; ++i) {
        for (int j = 1; j < M; ++j) {
            K[i][j] = A[i][j] == true ? K[i-1][j] + K[i][j-1] : 0;
        }
    }
    return K.back().back();
}


int main (void)
{
    auto n = count_path(5, 5);
    std::cout << n << std::endl;
    
    std::vector<std::vector<bool>> A(5, std::vector<bool>(5, true));
    A[3][3] = false;
    auto n_with_obstacle = count_path_with_obstacle(A);
    std::cout << n_with_obstacle << std::endl;

    return 0;
}
