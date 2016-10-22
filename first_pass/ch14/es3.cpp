#include <iostream>
#include <string>
#include "../utils.hpp"

void print_occurences ( std::string str)
{
    std::sort(str.begin(), str.end());
    int i = 0;
    while (i < str.size()) {
        std::cout << "(" << str[i] << ", ";
        int j = i+1;
        while (str[i] == str[j]) {
            ++j;
        }
        std::cout << j-i << "); ";
        i = j;
    }
    std::cout << std::endl;
}

void print_occurences2 (const std::string& str)
{
    int freq[128] = {0};

    for (const auto c: str) {
        ++freq[c];
    }
    for (int i = 0; i < 128; ++i) {
        if(freq[i] > 0) {
            std::cout << "(" << static_cast<char>(i) << ", " << freq[i] << "); ";
        }
    }
    std::cout << std::endl;
}


int main (void)
{
    std::string str("banana");
    //std::string str("aaaaa");
    print_occurences2(str);
    return 0;
}
