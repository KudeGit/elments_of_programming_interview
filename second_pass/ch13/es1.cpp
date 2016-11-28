#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "ch14.hpp"

//leetcode: https://leetcode.com/problems/anagrams/

anagram_set_t
partition_into_anagrams (const std::string& dict_file_name)
{
    std::ifstream dict_ifstream(dict_file_name);
    if (!dict_ifstream.good()) {
        return {};
    }
    anagram_set_t anagram_set;
    std::string line;
    while (getline(dict_ifstream, line)) {
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        auto sorted_str = line;
        std::sort(sorted_str.begin(), sorted_str.end());
        auto& x = anagram_set[sorted_str];
        x.emplace_back(line);
    }
    return anagram_set;
}
