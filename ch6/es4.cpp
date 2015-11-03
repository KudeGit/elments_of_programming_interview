#include <iostream>
#include <vector>
#include "../utils.hpp"

bool can_you_win (const std::vector<int>& A)
{
    int max_reacheable_pos = 0;
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > 0) {
            max_reacheable_pos = std::max(A[i]+i, max_reacheable_pos);
        } else {
            if(max_reacheable_pos <= i) {
                return false;
            }
        }
    }
    return max_reacheable_pos >= (A.size()-1);
}

int main (void)
{
    std::vector<int> A = {3,3,1,0,2,0,1};
    std::vector<int> B = {3,2,0,0,2,0,1};
    std::cout << can_you_win(A) << std::endl;
    std::cout << can_you_win(B) << std::endl;
    return 0;
}
