#include <iostream>
#include <vector>

using namespace std;


int majorityElement(vector<int>& nums) {
    auto candidate = nums[0];
    int count = 1;
    for (int i = 1; i < nums.size(); ++i) {
        auto n = nums[i];
        count = (n == candidate) ? (count + 1) : (count - 1);
        if (count == 0) {
            candidate = n;
            count = 1;
        }
    }
    return candidate;
}


//tested on leetcode: 169. Majority Element
int main (void)
{
    return 0;
}
