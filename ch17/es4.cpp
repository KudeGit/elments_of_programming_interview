#include <iostream>
#include <vector>
#include "../utils.hpp"


int count_ways_helper (std::vector<std::vector<int>>& matrix,
         int i, int j)
{
    if (i == matrix.size() - 1 && j == matrix[0].size() - 1) {
        return 1;
    } else if (i < 0 || j < 0 || 
            i >= matrix.size() || j >= matrix[0].size()) {
        return 0;
    }
    if (matrix[i][j] == 0) {
        matrix[i][j] = count_ways_helper(matrix, i + 1, j) +
            count_ways_helper(matrix, i, j + 1);
    }
    return matrix[i][j];

}

int count_ways (int N, int M)
{
    std::vector<std::vector<int>> matrix(N,
            std::vector<int>(M, 0));
    int i = 0, j = 0;
    auto res = count_ways_helper(matrix, i, j);
    return res;
}


int main (void)
{
    auto res = count_ways(2,2);
    std::cout << res << std::endl;
    return 0;
}
