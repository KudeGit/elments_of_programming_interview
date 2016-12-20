#include <iostream>
#include <string>
#include <vector>
#include "../../utils.hpp"

bool is_palidrome (const std::string& str)
{
    int l = 0, r = str.size() - 1;
    while (l < r) {
        if (str[l++] != str[r--]) {
            return false;
        }
    }
    return true;
}


void helper (const std::string& str,
        std::vector<std::vector<std::string>>& res,
        std::vector<std::string>& curr_decomposition)
{
    if(str.empty()) {
        res.emplace_back(curr_decomposition);
        return;
    }
    for (int i = 1; i <= str.size(); ++i) {
        auto candidate = str.substr(0, i);
        if (is_palidrome(candidate)) {
            curr_decomposition.emplace_back(candidate);
            auto lefover = str.substr(i, str.size() - i);
            helper(lefover, res, curr_decomposition);
            curr_decomposition.pop_back();
        }
    }

}

std::vector<std::vector<std::string>>
partition (const std::string& str)
{
    std::vector<std::string> curr_decomposition;
    std::vector<std::vector<std::string>> res;
    helper(str, res, curr_decomposition);
    return res;
}


int main (void)
{
    auto s = "aab";
    auto res = partition(s);
    return 0;
}
