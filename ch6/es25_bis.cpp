#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include "../utils.hpp"


void print_chess (const std::vector<std::vector<bool>> &A)
{
    for (const auto& a: A) {
        std::cout << a << std::endl;
    }
}

void attack (std::vector<std::vector<bool>> &A)
{
    std::unordered_set<int> rows;
    std::unordered_set<int> cols;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = 0; j < A[0].size(); ++j) {
            if(!A[i][j]) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    for (const auto& r: rows) {
        for(int c = 0; c < A[0].size(); ++c) {
            A[r][c] = false;
        }
    }

    for (const auto& c: cols) {
        for (int r = 0; r < A.size(); ++r) {
            A[r][c] = false;
        }
    }

}


int main (void)
{
    std::vector<std::vector<bool>> chess = {
            {1,0,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,0,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1},
            {1,1,1,0,1,1,1,1,1,1},
            };
    print_chess(chess);
    attack(chess);
    banner();
    print_chess(chess);
    return 0;
}
