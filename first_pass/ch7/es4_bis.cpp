#include <iostream>
#include <string>


void reverse_words (std::string& str)
{
    std::reverse(str.begin(), str.end());
    int start = 0;
    for (int i = 0; i < str.size(); ++i) {
        if(!isalpha(str[i])) {
            std::reverse(str.begin() + start, str.begin() + i);
            start = i + 1;
        }
    }
    std::reverse(str.begin() + start, str.end());
}

int main (void)
{
    std::string str1("Bob likes Alice");
    std::cout << str1 << std::endl;
    reverse_words(str1);
    std::cout << str1 << std::endl;

}
