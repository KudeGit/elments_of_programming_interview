#include <iostream>
#include <unordered_set>
#include "../utils.hpp"

template <std::size_t N, std::size_t M>
void set_row (bool (&chess)[N][M], int row, bool val)
{
    for (int j = 0; j < M; ++j) {
        chess[row][j] = val;
    }
}
template <std::size_t N, std::size_t M>
void set_col (bool (&chess)[N][M], int col, bool val)
{
    for (int i = 0; i < M; ++i) {
        chess[i][col] = val;
    }
}


template <std::size_t N, std::size_t M>
void attack_rooks (bool (&chess)[N][M])
{
    std::unordered_set<int> attackable_rows;
    std::unordered_set<int> attackable_cols;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(!chess[i][j]) {
                attackable_rows.insert(i);
                attackable_cols.insert(j);
            }
        }
    }
    for (const auto row: attackable_rows) {
        set_row(chess, row, false);
    }
    for (const auto col: attackable_cols) {
        set_col(chess, col, false);
    }
}

#define N 8
int main (void) 
{
    bool A[N][N];
    for (int i = 0; i < N; i++) {
        set_row(A, i, true);
    }
    A[0][1] = false;
    A[3][5] = false;
    A[4][3] = false;
    A[6][0] = false;
    A[6][6] = false;

    std::cout << A << std::endl;
    attack_rooks(A);
    std::cout << A << std::endl;
    return 0;
}
