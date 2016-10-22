#include <iostream>

#define print(x) std::cout << x << ","
template <std::size_t N>
void print_spiral(int (&A)[N][N]) 
{
    int K = N/2;
    for (int k = 0; k <= K; ++k) {
        for (int i = k; i < N - k; ++i) {
            print(A[k][i]);
        }
        for (int j = k + 1; j < N - k; ++j) {
            print(A[j][N-1-k]);
        }
        for (int i = N-2-k; i >= k; --i) {
            print(A[N-1-k][i]);
        }
        for (int j = N-2-k; j > k; --j) {
            print(A[j][k]);
        }
    }
    std::cout<<std::endl;
    return;
}


#define M 5
int main(void) 
{
    int A[M][M];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = i*M+ j;
        }
    }
    print_spiral(A);
    return 0;
}
