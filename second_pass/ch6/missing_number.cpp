#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include "../../utils.hpp"

int missing_number (const std::vector<int>& V)
{
    auto S = 0; auto expected = (V.size() + 1) * V.size() /2;
    for (auto& v: V) {
        S += v;
    }
    return expected - S;
}


int missing_number2 (const std::vector<int>& V)
{
    auto res = 0;
    for (int i = 0; i < V.size(); ++i) {
        res ^= i ^ V[i];
    }
    return res ^ V.size();
}

using namespace std;
int missing_number3 (std::vector<int>& nums)
{
    for (int i = 0; i < nums.size(); ++i) {
        while (nums[i] > 0 && nums[i] <= nums.size() &&
                nums[nums[i] - 1] != nums[i] &&
                nums[i] - 1 != i) {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            return i+1;
        }
    }
    return nums.size() + 1;
}


int missing_with_duplicate (std::vector<int>& A)
{
    for (int i = 0; i < A.size(); ++i) {
        auto idx = A[i] - 1;
        if (A[idx] > 0) {
            A[idx] *= -1;
        }
    }
    auto res = std::vector<int>{};
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] > 0) {
            res.emplace_back(i+1);
        }
    }
    return res;
}



int main (void)
{

    std::vector<int> V(10);
    std::iota(V.begin(), V.end(), 0);
    std::random_shuffle(V.begin(), V.end());
    V = {1,1};
    debug(V);
    auto res = missing_number3(V);
    debug(res);
    debug(V);



    return 0;

    debug(V);
    std::swap(V[1], V.back());
    std::swap(V[3], V[4]);
    V.pop_back();
    res = missing_number(V);
    debug(res);
    res = missing_number2(V);
    debug(res);

    return 0;

}

