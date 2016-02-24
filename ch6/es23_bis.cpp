#include <iostream>
#include <vector>
#include "../utils.hpp"

template <class T>
void print_matrix (const std::vector<std::vector<T>>& A)
{
    for (const auto& a: A) {
        std::cout << a << std::endl;
    }
}

template <class T>
void rotate(std::vector<std::vector<T>> &A)
{
    int N = A.size();
    int layers = N/2 + (N & 1);
    for (int l = 0; l < layers; ++l) {
        for (int i = l; i < N - 1 - l; ++i) {
            T a = A[i][N - 1 - l];
            A[i][N - 1 - l] = A[l][i];
            T b = A[N - 1 - l][N - 1 - i];
            A[N - 1 - l][N - 1 - i] = a;
            a = A[N - 1 - i][l];
            A[N - 1 - i][l] = b;
            A[l][i] = a;
        }
    }
    return;
}


int main (void)
{
    std::vector<std::vector<int>> A = {{1,2,3,4},
                                       {5,6,7,8},
                                       {9,10,11,12},
                                       {13,14,15,16}};

    print_matrix(A);
    rotate(A);
    print_matrix(A);
    return 0;
}
