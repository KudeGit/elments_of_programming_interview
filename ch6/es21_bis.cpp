#include <iostream>
#include <vector>
#include <array>


bool check_entry (int t, std::array<bool, 9>& check) 
{
    if (t == -1) {
        return false;
    }
    t -= 1;
    if (check[t]) {
        return true;
    } else {
        check[t] = true;
    }
    return false;
}

bool is_valid_sudoku (const std::array<std::array<int, 9>, 9> &A)
{
    std::array<bool, 9> rows;
    std::array<bool, 9> cols;
    std::array<bool, 9> sub_square;
    for (int i = 0; i < 9; ++i) {
        std::for_each(cols.begin(), cols.end(), [&](bool &x) {x = false;});
        std::for_each(rows.begin(), rows.end(), [&](bool &x) {x = false;});
        for (int j = 0; j < 9; ++j) {
            if(check_entry(A[i][j], cols)) {
                return false;
            }
            if (check_entry(A[j][i], rows)) {
                return false;
            }
        }
    }
    //check subsquare
    
    for (int i = 0; i < 9; i+=3) {
        for (int j = 0; j < 9; ++j) {
            std::for_each(sub_square.begin(), sub_square.end(), [&](bool &x) {x = false;});
            for (int ii = 0; ii < 3; ++ii) {
                for (int jj = 0; jj < 3; ++jj) {
                    int iii = i + ii;
                    int jjj = j + jj;
                    if (A[iii][jjj] != -1) {
                        if(sub_square[A[iii][jjj] - 1]) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}


int main (void)
{
    return true;
}
