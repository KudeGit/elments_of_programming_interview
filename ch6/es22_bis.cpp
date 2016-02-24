#include <iostream>
#include <vector>
#include <array>

template <class T, size_t N>
void print_spiral (const std::array<std::array<T, N>, N> &A)
{
    int layer = N / 2 + (N & 1);
    for (int l = 0; l < layer; ++l) {
        //print upper row
        for (int i = l; i < N - l; ++i) {
            std::cout << A[l][i] << ", ";
        }
        //print right column
        for (int j = l + 1; j < N - l; ++j) {
            std::cout << A[j][N - 1 - l] << ", ";
        }
        //print bottom rows
        for (int i = N - 2 - l; i >= l; --i) {
            std::cout << A[N - 1 - l][i] << ", ";
        }
        //print right column
        for (int j = N - 2 - l; j >= l + 1; --j) {
            std::cout << A[j][l] << ", ";
        }
    }
    std::cout << std::endl;
}


int main (void) 
{
    std::array <std::array<int, 3>, 3> A =  {{ {{1,2,3}}, {{4,5,6}}, {{7,8,9}} }};
    std::array <std::array<int, 4>, 4> B =  {{ {{0,1,2,3}}, {{4,5,6,7}}, {{8,9,10,11}}, {{12,13,14,15}} }};
    print_spiral(A);
    print_spiral(B);
    return 0;
}
