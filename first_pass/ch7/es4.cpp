#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

void reverse_words2 (std::string &str)
{
    int j = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(!isalpha(str[i])) {
            if (j < i) {
                std::reverse(str.begin() + j, str.begin() + i);
            }
            j = i+1;
        }
    }
    std::reverse(str.begin() + j, str.end());
}

void reverse_words(std::string& str)
{
    std::reverse(str.begin(), str.end());
    reverse_words2(str);

}


int main (void) 
{
    std::vector<std::string> strs = {"",
             "Ciao",
             "Hello world!",
             "Hello, today is a very beatiful day",
             "Hello, today is a very beatiful day.",
             "Hello, today, is, a, very, beatiful, day.",
             "How are you? Very good, thank you!"};

    for (auto& str: strs) {
        reverse_words(str);
        std::cout << str << std::endl;
    }
    return 0;
    
}
