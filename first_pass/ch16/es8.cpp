#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"
#include <tuple>
#include <unordered_set>

bool is_palidrome (const std::string& str)
{
    int i = 0;
    int j = str.size() - 1;
    while ( i < j) {
        if (str[i++] != str[j--]) {
            return false;
        }
    }
    return true;

}

/*
struct Hash {
    size_t operator() (const std::tuple<int, int>& A) const {
        return std::hash<int>()(std::get<0>(A)) ^ 
            std::hash<int>()(std::get<1>(A) << 5);
    }
};

void compute_palindrom_decomp_helper (
        const std::string& str,
        std::vector<std::string>& pal_decomps,
        std::unordered_set<std::tuple<int,int>, Hash>& cache,
        int start, int end)
{
    if (end == str.size()) {
        return;
    }
    auto idx = std::make_tuple(start, end);
    if (cache.find(idx) != cache.end()) {
        return;
    }

    compute_palindrom_decomp_helper(str, pal_decomps, cache, end+1, end+1);
    //debug(start);
    //debug(end);
    if (end + 1 - start > 1) {
        std::string candidate(str.begin() + start, str.begin() + end + 1);
        //debug(candidate);
        if (is_palidrome(candidate)) {
            pal_decomps.emplace_back(candidate);
        }
    }
    compute_palindrom_decomp_helper(str, pal_decomps, cache, start, end+1);
    cache.insert(std::make_tuple(start, end));
}
*/
using palindrome_decomp_t = std::vector<std::string>;

void compute_palindrom_decomp_helper (
        int start,
        const std::string& str,
        palindrome_decomp_t& current_decomp,
        std::vector<palindrome_decomp_t>& all_decomp)
{
    if (start == str.size()) {
        all_decomp.emplace_back(current_decomp);
        return;
    }
    for (int i = start; i < str.size(); ++i) {

        auto candidate = str.substr(start, i - start + 1);
        if (is_palidrome(candidate)) {
            current_decomp.push_back(candidate);
            compute_palindrom_decomp_helper(i+1, str,
                    current_decomp, all_decomp);
            current_decomp.pop_back();
        }
    }
    return;
}


std::vector<palindrome_decomp_t> compute_palindrom_decomp (
        const std::string& str)
{
    palindrome_decomp_t current;
    std::vector<palindrome_decomp_t> pal_decomps;
    compute_palindrom_decomp_helper(0, str,
            current, pal_decomps);
    return pal_decomps;
}





int main (void)
{
    //std::string str("aba");
    std::string str("0204451881");
    auto res = compute_palindrom_decomp(str);
    for (const auto& r: res) {
        std::cout << r << std::endl;
    }
    return 0;
}
