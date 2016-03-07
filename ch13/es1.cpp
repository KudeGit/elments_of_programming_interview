#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <fstream>
#include "../utils.hpp"
#include <cctype>
#include <algorithm>


std::vector<std::vector<std::string>> find_anagrams (const std::string& dict_name)
{
    std::ifstream fdicionary(dict_name);
    if (!fdicionary.good()) {
        throw std::invalid_argument("cannot open dictionary file");
    }
    std::string word;
    std::unordered_map<std::string, std::unordered_set<std::string>> anagrams;
    while(getline(fdicionary, word)) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        std::string sorted_word(word);
        std::sort(sorted_word.begin(), sorted_word.end());
        if (anagrams[sorted_word].find(word) == anagrams[sorted_word].end()) {
            anagrams[sorted_word].insert(word);
        }
    }
    std::vector<std::vector<std::string>> res;
    for (const auto& alist: anagrams) {
        if(alist.second.size() > 1) {
            std::vector<std::string> word_list;
            for (const auto& word: alist.second) {
                word_list.emplace_back(word);
            }
            res.emplace_back(word_list);
        }
    }
    return res;
}

int main (void)
{
    const std::string dict_name("/usr/share/dict/words");
    auto anagrams = find_anagrams(dict_name);
    for (const auto& a: anagrams) {
        std::cout << a << std::endl;
    }
    return 0;
}
