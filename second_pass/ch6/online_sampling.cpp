#include <iostream>
#include <sstream>
#include <random>
#include "../../utils.hpp"

using namespace std;

std::vector<int> online_sampling(std::stringstream& iss, int k)
{
    std::vector<int> res;
    std::random_device rd;
    std::mt19937 gen(rd());
    auto curr = 0;
    auto n = 0;
    while (iss >> curr) {
        ++n;
        if (res.size() < k) {
            res.emplace_back(curr);
        } else {
            std::uniform_int_distribution<int> d(0,n);
            auto x = d(gen);
            if(x < k) {
                res[x] = curr;
            }
        }
    }
    return res;
}



vector<int> sortTransformedArray(const vector<int>& nums, int a, int b, int c) {
    auto f = [&a, &b, &c](int x) {return a*x*x + b * x + c; };
    std::vector<int> res(nums.size());
    if(a != 0) {
        int l = 0, r = nums.size() - 1;
        if (a > 0) {
            cout << "A" << endl;
            auto  k = res.size() - 1;
            while (l <= r && k >= 0) {

                debug(std::make_pair(nums[l], f(nums[l])));
                debug(std::make_pair(nums[r], f(nums[r])));
                if (f(nums[l]) >= f(nums[r])) {
                    res[k--] = f(nums[l++]);
                } else {
                    res[k--] = f(nums[r--]);
                }

                cout << res << endl;
            }
        } else {
            auto k = 0;
            while (l <= r && k < res.size()) {
                if (f(nums[l]) <= nums[r]) {
                    res[k++] = f(nums[l++]);
                } else {
                    res[k++] = f(nums[r--]);
                }
            }
        }
    } else {
        if (b > 0) {
            for (int i = 0; i < nums.size(); ++i) {
                res[i] = f(nums[i]);
            }
        } else {
            for (int i = nums.size() -1, k = 0; i >= 0; --i, ++k) {
                res[k] = f(nums[i]);
            }
        }
    }
    debug(res);
    return res;
}

int main (void)
{
    sortTransformedArray({-4,-2,2,4,5}, 1,3,5);

    return 0;
}
