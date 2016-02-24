#include <iostream>
#include <array>
#include "../utils.hpp"


template <size_t N>
int find_the_celebrity (const bool (&A)[N][N])
{
    int i = 0;
    int j = 1;
    while (j < N) {
        if(A[i][j] == true) {
            i = j++;
        } else {
            ++j;
        }
    }
    return i;
}


int main (void)
{
    bool A[5][5] = {
        {0,1,1,0,0},
        {0,0,1,1,0},
        {0,0,0,0,0},
        {0,1,1,1,0},
        {0,1,1,0,0},
    };
    std::cout << find_the_celebrity(A) << std::endl;
    return 0;
}
