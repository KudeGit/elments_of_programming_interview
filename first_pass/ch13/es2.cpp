#include <iostream>
#include <string>
#include <unordered_map>
#include "../utils.hpp"



bool is_palidromic (const std::string& word)
{
    char frequencies[128] = {0};
    for (const auto& c: word) {
        ++frequencies[c];
    }
    int odd_f = 0;
    int even_f = 0;
    for (int i = 0; i < 128; ++i) {
        if (frequencies[i] & 0x01ul) {
            ++odd_f;
        } else {
            ++even_f;
        }
    }
    if (((word.size() & 0x01ul) == 0x01ul) && odd_f > 1) {
        return false;
    }
    if (((word.size() & 0x01ul) == 0x00ul) && odd_f >= 1) {
        return false;
    }
    return true;
}

int main (void) 
{
    auto dictionary = load_dictionary();
    for(const auto& word: dictionary) {
        auto test = is_palidromic(word);
        std::cout << word << " is palidromic: " <<  test << std::endl;
    }
    return 0;
}

