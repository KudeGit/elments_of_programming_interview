#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "../utils.hpp"

int match(const std::string& str, const std::string& pattern)
{
    if(pattern.size() > str.size()) {
        return -1;
    }

    for (int i = 0; i < str.size() - pattern.size() + 1; ++i) {
        int j = 0;
        for (j = 0; j < pattern.size() &&
                    str[i+j] == pattern[j]; ++j);
        if(j == pattern.size()) {
            return i;
        }
    }
    return -1;
}

std::vector<int> match_all(const std::string& str, const std::string& pattern)
{
    std::vector<int> result;
    if(pattern.size() > str.size()) {
        return {};
    }

    for (int i = 0; i < str.size() - pattern.size() + 1; ++i) {
        int j = 0;
        for (j = 0; j < pattern.size() &&
                    str[i+j] == pattern[j]; ++j);
        if(j == pattern.size()) {
            result.push_back(i);
        }
    }
    return result;
}

std::vector<int> rabin_karp (const std::string& str,
                            const std::string& pattern,
                            size_t d, size_t q)
{
    if(pattern.size() > str.size()) {
        return {};
    }
    std::vector<int> res;
    int m = pattern.size();
    size_t h = static_cast<size_t>(pow(d, m - 1)) % q;
    std::size_t p = 0;
    std::size_t t = 0;
    for(int i = 0; i < m; ++i) {
        auto p0 = pattern[i] - '0';
        auto t0 = str[i] - '0';
        p = (d*p + p0);
        t = (d*t + t0);
    }
    for (int i = m; i < str.size(); ++i) {
        if(t == p) {
            std::string current_sub_str(str.begin() + i - m, str.begin() + i + 1);

            int idx = match(current_sub_str, pattern);
            if (idx != -1) {
                res.push_back(i-m);
            }
        }
        auto t_0 = str[i-m] - '0';
        auto t_s = str[i] - '0';
        t = (d*(t - t_0*h) + t_s) % q;
    }
    if(t == p) {
        std::string current_sub_str(str.begin() + str.size() - m, str.end());
        int idx = match(current_sub_str, pattern);
        if (idx != -1) {
            res.push_back(str.size()-m);
        }
    }
    return res;
}

int main (int argc, char* argv[])
{
    if (argc != 3) {
        error("usage error: %s string pattern", argv[0]);
        return -1;
    }
    size_t q = (static_cast<size_t>(1) << static_cast<size_t>(32)) - static_cast<size_t>(1);
    auto indexes = rabin_karp(argv[1], argv[2], 10, q);
    std::cout << indexes << std::endl;
    return 0;
}

