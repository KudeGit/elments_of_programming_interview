#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../../utils.hpp"
#include <random>
#include <cassert>


template <class T>
bool operator== (const std::vector<T>& lhs, const std::vector<T>& rhs)
{
    if (lhs.size() != rhs.size()) {
        return false;
    }
    for (size_t i = 0; i < lhs.size();++i) {
        if (lhs[i] != rhs[i]) {
            return false;
        }
    }
    return true;
}

using namespace std;

string to_binary (int n)
{
    if (n == 0) {
        return "0";
    }
    string res;
    while (n) {
        auto curr_bit = (n & 0x01) ? '1' : '0';
        res += curr_bit;
        n /= 2;
    }
    std::reverse(res.begin(), res.end());
    return res;
}


string elias_econde(const std::vector<int>& A)
{
    stringstream res;
    for (auto& a: A) {
        auto binary = to_binary(a);
        res << string(binary.size() - 1, '0') << binary;
    }
    return res.str();
}


int to_integer(const std::string str)
{
    auto res = 0;
    for (auto s: str) {
        res = 2*res + s - '0';
    }
    return res;
}

vector<int> elias_deconde (const std::string& str)
{
    auto i = 0;
    vector<int> res;
    while (i < str.size()) {
        auto n = 0;
        while (i < str.size() && str[i] == '0') {
            ++n; ++i;
        }
        stringstream bin_num;
        while (n >= 0 && i < str.size()) {
            bin_num << str[i];
            --n; ++i;
        }
        res.emplace_back(to_integer(bin_num.str()));
    }
    return res;
}


void test()
{
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<int> dl(1,1000);
    uniform_int_distribution<int> d(1,10000);
    for (auto i = 0; i < 100; ++i) {
        auto len = dl(gen);
        vector<int> input;
        for (; len >=0; --len) {
            input.emplace_back(d(gen));
        }
        auto encoded = elias_econde(input);
        auto decoded = elias_deconde(encoded);
        assert(input == decoded);
    }
}


int main (void)
{
    test();
    return 0;


}
