#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../utils.hpp"


struct EliasGammaEconder {
    std::string encode (int n);
    std::vector<int> decode(const std::string& str);
    std::string encode (std::vector<int>& numbers);
};

std::string EliasGammaEconder::encode (int n) 
{
    int count = 0;
    std::stringstream ss_res;
    do {
        ss_res << (n%2);
        n /= 2;
        ++count;
    } while(n>0);

    while (count > 1) {
        ss_res << '0';
        --count;
    }

    std::string res = ss_res.str();
    std::reverse(res.begin(), res.end());
    return res;
}

std::string EliasGammaEconder::encode (std::vector<int>& numbers)
{
    std::string res; 
    for (const auto& n: numbers) {
        res += encode(n);
    }
    return res;
}


std::vector<int> EliasGammaEconder::decode (const std::string& str)
{
    std::vector<int> res_list;
    int i = 0;
    while (i < str.size()) {
        int res = 0;
        int n_zeros = 0;
        while(str[i] == '0') {
            ++n_zeros;
            ++i;
        }

        while (n_zeros >= 0) {
            res = (res << 1) + (str[i++] - '0');
            --n_zeros;
        }
        res_list.push_back(res);
    }
    return res_list;
}

int main (void)
{
    EliasGammaEconder egc;
    std::vector<int> numbers = {5, 5};
    auto encoded_str = egc.encode(numbers);
    auto decoded_n = egc.decode(encoded_str);
    std::cout << encoded_str << std::endl;
    std::cout << decoded_n << std::endl;


    return 0;
}

