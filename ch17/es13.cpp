#include <iostream>
#include <vector>
#include <limits>
#include "../utils.hpp"

int find_min_weight_path (const std::vector<std::vector<int>>& A)
{
    if (A.empty()) {
        return 0;
    }
    std::vector<std::vector<int>> K(A.size(),
            std::vector<int>(A.back().size(), 0));
    K[0][0] = A[0][0];
    for (int i = 1; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            K[i][j] = std::min(
                    j > 0 ? K[i-1][j-1] : std::numeric_limits<int>::max(), 
                    j < A[i-1].size() ? K[i-1][j] : std::numeric_limits<int>::max()) +
                A[i][j];
        }
    }
    debug(K);
    return K.back().back();
}


int main (void) 
{
    std::vector<std::vector<int>> A = {
        {1},
        {1,1},
        {1,2,1},
        {1,3,3,1},
    };
    debug(A);
    auto res = find_min_weight_path(A);
    std::cout << res << std::endl;
    return 0;
}
