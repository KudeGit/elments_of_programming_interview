#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../utils.hpp"

using  namespace std;


vector<int> majorityElement(vector<int>& nums) {
    std::unordered_map<int, int> K;
    for (auto& n: nums) {
        for (auto& k: K) {
            k.second += n == k.first ? 1 : -1;
            cout << k.first << ", " << k.second << endl;
            if (k.second <= 0) {
                K.erase(k.first);
            }
        }
        if (K.size() < 3) {
            ++K[n];
        }
    }
    std::vector<int> res;
    for (auto& k: K) {  
        if (k.second > nums.size() / 3) {
            res.emplace_back(k.first);
        }
    }
    return res;
}

int main (void)
{
    std::vector<int> nums = {2,2,1,3};
    for (int i = 0; i < 100; ++i) {
        auto res = majorityElement(nums);
    }
    return 0;
}
