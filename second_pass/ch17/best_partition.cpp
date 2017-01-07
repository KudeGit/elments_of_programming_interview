#include <iostream>
#include <vector>
#include <numeric>
#include "../../utils.hpp"


long best_partition (const std::vector<int>& A)
{
    long tot_sum = std::accumulate(A.begin(), A.end(), 0l);
    std::vector<std::vector<bool>> K((tot_sum >> 1) + 1,
            std::vector<bool>(A.size() + 1, false));

    for (int i = 0; i <= A.size(); ++i) {
        K[0][i] = true;
    }
    for (int j = 1; j <= (tot_sum >> 1); ++j) {
        int i = 1;
        for (auto& a: A) {
            K[j][i] = K[j][i-1];
            if (j >= a) {
                K[j][i] = K[j][i-1] || K[j-a][i-1];
            }
            ++i;
        }
    }

    for (int j = tot_sum >> 1; j >= 0; --j) {
        if (K[j].back()) {
            return tot_sum - j - j;
        }
    }
    return tot_sum;
}



bool canPartition(const std::vector<int>& A)
{
    auto diff = best_partition(A);
    return diff == 0;
}

int main (void)
{

    std::vector<int> A{65, 35, 245, 195, 65, 150, 275, 155,
                        120, 320, 75, 40, 200, 100, 220, 99};
    std::vector<int> B{89,49,21,31,74,56,34,23,35,15,74,59,75,47,16,81,1,32,42,75,4,3,
        54,55,95,65,10,90,15,23,19,30,24,91,3,84,11,76,6,96,78,84,58,80,28,96,11,46,36,
        84,3,14,32,86,67,8,60,70,65,57,63,15,61,79,66,55,92,44,62,76,19,52,59,72,2,60,75,52,37,100,1,92,1,40,11,68,61,22,88,70,50,82,81,39,80,75,67,31,3,55};
    auto res = best_partition(B);
    debug(res);
    return 0;

}
