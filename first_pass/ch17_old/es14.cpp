#include <iostream>
#include <vector>
#include <limits>
#include "../utils.hpp"

int get_min_weight_path (const std::vector<std::vector<int>>& A)
{
    std::vector<std::vector<int>> K(2, std::vector<int>(A.back().size(), 
                std::numeric_limits<int>::max()));
    K[0][0] = A[0][0];
    for (int i = 1; i < A.size(); ++i) {
        for (int j = 0; j < A[i].size(); ++j) {
            K[i & 1][j] = A[i][j] + std::min(K[(i-1)&1][j],
                    j > 0 ? K[(i-1)&1][j-1] : std::numeric_limits<int>::max());
        }
    }
    int min_weight_path = std::numeric_limits<int>::max();
    for (const auto& k: K[(A.size() - 1) & 1]) {
        min_weight_path = std::min(min_weight_path, k);
    }
    return min_weight_path;
}


int main (void)
{
    std::vector<std::vector<int>> A = {
        {55},
        {94, 48},
        //{95, 30, 96},
        //{77, 71, 26, 67}
    };
    auto res = get_min_weight_path(A);
    std::cout <<res << std::endl;
    return 0;
}
