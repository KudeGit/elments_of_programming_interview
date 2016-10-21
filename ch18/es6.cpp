#include <iostream>
#include <vector>
#include <unordered_set>
#include "../utils.hpp"


std::vector<std::vector<int>> twoSumSorted (const std::vector<int>& nums, const int target, int start, int end) {
    std::vector<std::vector<int>> res;
    if (start < 0 || end > nums.size() -  1) {
        throw std::logic_error("indexes out of boundaries");
    }
    debug(start);
    debug(end);
    debug(target);
    while(start < end) {
        auto current = nums[start] + nums[end];
        if(current == target) {
            debug(current);
            res.emplace_back(std::vector<int>({nums[start], nums[end]}));
            while (start < end && nums[start] == nums[start + 1]) ++start;
            ++start;
            while (start < end && nums[end] == nums[end - 1]) --end;
            --end;
        } else if (current < target) {
            while (start < end && nums[start] == nums[start + 1]) ++start;
            ++start;
        } else {
            while (start < end && nums[end] == nums[end - 1]) --end;
            --end;
        }
    }
    return res;
}
std::vector<std::vector<int>> threeSum(const std::vector<int>& nums, const int target)
{   
    if (nums.size() < 3) {
        return {};
    }
    std::vector<std::vector<int>> res;
    for (int i = 0; i <= nums.size() - 3; ++i) {
        auto two_sum_res_all = twoSumSorted(nums, target - nums[i], i+1, nums.size()-1);
        if (!two_sum_res_all.empty()) {
            for (const auto& two_sum_res: two_sum_res_all) {
                res.emplace_back(std::vector<int>({nums[i], two_sum_res[0], two_sum_res[1]}));
            }
        }
        while (nums[i] == nums[i+1] && i < nums.size() - 3) {
            ++i;
        }
    }
    return res;
}

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return threeSum(nums, 0);
}


//tested on leetcode: 3Sum

int main (void)
{
    return 0;
}
