#include <iostream>
#include <vector>
#include "../../utils.hpp"

using namespace std;



int lengthOfLIS(const vector<int>& nums) {
    auto K = std::vector<int>(nums.size()+1, 1);
    K[0] = 0;
    auto longest_idx = nums.empty() ? 0 : 1;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] <= nums[i]) {
                K[i+1] = std::max(K[i+1], K[j+1] + 1);
                longest_idx = (K[longest_idx] > K[i+1] + 1) ? longest_idx : i+1;
            }
        }
    }
    debug(nums);
    debug(K);
    //auto max_length = K[0];
    //for (auto& k: K) {
    //    max_length = std::max(max_length, k);
    //}
    return K[longest_idx];
}

bool increasingTriplet(const vector<int>& A) {
    if (A.size() < 3) {
        return false;
    }
    pair<int,int> lowests{std::numeric_limits<int>::max(),
                           std::numeric_limits<int>::max()};
    for (auto& a: A) {
        debug(lowests);
        if (a < lowests.first) {
            lowests.first = a;
            lowests.second = std::numeric_limits<int>::max();
        } else if (a > lowests.first && a < lowests.second) {
            lowests.second = a;
        } else if (a > lowests.second) {
            return true;
        }
    }
    return false;
 }

int main (void)
{
    //std::vector<int> A{10, 9, 2, 5, 3, 7, 101, 18};
    //std::vector<int> A{0,-1};
    auto res = increasingTriplet({1,0,0,1});
    debug(res);
    return 0;
}
