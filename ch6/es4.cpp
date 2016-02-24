#include <iostream>
#include <vector>
#include "../utils.hpp"

bool can_you_win (const std::vector<int>& A)
{
    int reacheable_pos = A[0];
    for (int i = 1; i < A.size(); ++i) {
        if(i > reacheable_pos) {
            return false;
        }
        reacheable_pos = std::max(reacheable_pos, A[i]+i);
    }
    return true;
}

int main (void)
{
    std::vector<int> A = {3,3,1,0,2,0,1};
    std::vector<int> B = {3,2,0,0,2,0,1};
    std::cout << can_you_win(A) << std::endl;
    std::cout << can_you_win(B) << std::endl;
    return 0;
}
