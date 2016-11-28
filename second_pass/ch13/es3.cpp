#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cassert>

bool is_constructible (std::stringstream& iss_letter, std::stringstream& iss_magazine)
{
    std::string word;
    char char_count[128] = {0};
    while (getline(iss_magazine, word)) {
        for (const auto& w: word) {
            assert(w >=0  && w < 128);
            ++char_count[w];
        }
    }
    while (getline(iss_letter, word)) {
        for(const auto& w: word) {
            assert(w >=0  && w < 128);
            --char_count[w];
            if (char_count[w] < 0) {
                return false;
            }
        }
    }
    return true;
}

