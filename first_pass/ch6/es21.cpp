#include <iostream>
#include "../utils.hpp"

template <class T, std::size_t N>
void rotate(T (&A)[N][N])
{
    for (int k = 0; k <= N/2; ++k) {
        int tmp1, tmp2;
        for (int i = k; i < N - k-1; ++i) {
            tmp1 = A[i][N-1-k];
            A[i][N-1-k] = A[k][i];

            tmp2 = A[N-1-k][N-1-i];
            A[N-1-k][N-1-i] = tmp1;

            tmp1 = A[N-1-i][k];
            A[N-1-i][k] = tmp2;

            A[k][i] = tmp1;
        }
    }
}


#define N 5
int main (void) 
{
    int A[N][N] = {0};
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = i*N+j;
        }
    }
    std::cout << A << std::endl;
    rotate(A);
    std::cout << A << std::endl;
    return 0;
}
