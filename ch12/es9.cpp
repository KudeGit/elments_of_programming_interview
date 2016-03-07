#include <iostream>
#include <vector>
#include <tuple>
#include "../utils.hpp"



template <class T, std::size_t N>
std::tuple <int, int> find_in_matrix (const T (&A)[N][N], const T target)
{
    int row = 0;
    int col = N - 1;
    while (row < N && col > -1) {
        if (A[row][col] == target) {
            return std::make_tuple(row, col);
        } else {
            if(target < A[row][col]) {
                --col;
            } else {
                ++row;
            }
        }
    }
    return std::make_tuple(-1,-1);
}

int main (void)
{
    int A[5][5];
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            A[i][j] = i*5+j;
        }
    }
    std::cout << A << std::endl;
    auto res = find_in_matrix(A, 5);
    std::cout << "5 is in postion: " << res << std::endl;
    res = find_in_matrix(A, 100);
    std::cout << "100 is in postion: " << res << std::endl;

    return 0;
}
