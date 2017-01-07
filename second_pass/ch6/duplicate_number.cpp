#include <istream>
#include <vector>
#include "../../utils.hpp"
#include <cassert>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
        auto idx = nums[i];
        while (idx > nums.size()) {
            idx -= nums.size();
        }
        nums[idx-1] += nums.size();
    }
    debug(nums);

    vector<int> res{};
    for (int i = 0; i < nums.size(); ++i) {
        if ((nums[i] - 2*nums.size() > 0) && (nums[i] - 2*nums.size() <= nums.size())) {
            res.emplace_back(i+1);
        }
    }
    return res;
}


int main (void)
{
    //std::vector<int> A{3,11,8,16,4,15,4,17,14,14,6,6,2,8,3,12,15,20,20,5};
    std::vector<int> A = {27,40,6,21,14,36,10,19,44,10,41,26,39,20,25,19,14,7,29,27,40,38,11,44,4,6,48,39,9,13,7,45,41,23,31,8,24,1,3,5,28,11,49,29,18,4,38,32,24,15};
    debug(A.size());
    auto res = findDuplicates(A);
    debug(res);
}
