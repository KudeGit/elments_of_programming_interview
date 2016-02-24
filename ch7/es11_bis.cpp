#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>
#include "../utils.hpp"

struct EliasGamma {
    std::string to_binary (const int n);
    int to_decimal(const std::string& str);
    std::string encode(const int n);
    std::string encode(const std::vector<int> &A);
    std::vector<int> decode (const std::string& str);
};

std::string EliasGamma::to_binary(int n)
{
    std::stringstream ss;
    while (n) {
        ss << (n & 0x01);
        n >>= 1;
    }
    auto res = ss.str();
    std::reverse(res.begin(), res.end());
    return res;
}

std::string EliasGamma::encode (const int n)
{
    auto s1 = to_binary(n);
    auto res = std::string(s1.size() - 1, '0') + s1;
    return res;
}

std::string EliasGamma::encode (const std::vector<int>& nums)
{
    std::stringstream ss;
    for (const auto& n: nums) {
        ss << encode(n);
    }
    return ss.str();
}

int EliasGamma::to_decimal (const std::string& str)
{
    int res = 0;
    for (int i = 0 ; i < str.size(); ++i) {
        res = res * 2 + (str[i] - '0');
    }
    return res;
}

std::vector<int> EliasGamma::decode (const std::string& str)
{
    std::vector<int> res;
    int i = 0;
    while (i < str.size()) {
        int n_zeros = 0;
        while (str[i] == '0') {
            ++i;
            ++n_zeros;
        }
        auto current = std::string(str.begin() + i, str.begin() + i + n_zeros + 1);
        int n = to_decimal(current);
        res.push_back(n);
        i += n_zeros + 1;
    }
    return res;
}

int main (void)
{
    EliasGamma el;
    std::vector<int> nums = {13,10,5};
    std::cout << "input: " << nums << std::endl;
    auto res = el.encode(nums);
    std::cout << "econded: " << res << std::endl;
    auto decoded = el.decode(res);
    std::cout << "decoded: " << decoded << std::endl;
    return 0;
}


