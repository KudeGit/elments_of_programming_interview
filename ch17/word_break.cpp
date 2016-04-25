#include <iostream>
#include <vector>
#include "../utils.hpp"

using dictionary_t = std::unordered_set<std::string>;



bool word_break_helper (const std::string& str,
        const dictionary_t& dict, dictionary_t& cache)
{
    if (str.size() == 0) {
        return true;
    }
    if (cache.find(str) != cache.cend()) {
        return false;
    }
    for (int i = 1; i <= str.size(); ++i) {
        auto curr_word = str.substr(0, i);
        //debug(curr_word);
        if (dict.find(curr_word) != dict.end()) {
            auto left_over = str.substr(i, str.size() - i);
            //debug(left_over);
            if(word_break_helper(left_over, dict, cache)) {
                return true;
            }
        }
    }
    debug(str);
    cache.insert(str);
    return false;
}


bool word_break (const std::string& str, const dictionary_t& dict) {
    dictionary_t cache;
    return word_break_helper (str, dict, cache);
}


int main (void)
{
    //auto dict = load_dictionary();
dictionary_t dict ={
    "they", "surrounded", "the", "divers", "and", "started",
    "clicking", "they", "seemed", "to", "be", "saying", "hello",
    "Read", "and", "then", "take", "a", "swim", "with", "whales",
    "in", "virtual", "reality,", "feature"};
    const std::string str = "surroundedtheywhalesdiversandfeaturethey";
    //startedclickingtheyseemedtobesayinghelloReadandthentakeaswimwithwhalesinavirtualrealityfeature";
    auto res = word_break(str, dict);
    debug(res);
    return 0;
}
