#include <iostream>
#include <string>
#include <cctype>

bool is_palindromic(const std::string& str)
{
    int i = 0, j = str.size() - 1;
    while (i<j) {
        if (!isalpha(str[i])) {
            ++i;
        } else if (!isalpha(str[j])) {
            --j;
        } else {
            if(tolower(str[i++]) != tolower(str[j--])) {
                return false;
            }
        }
    }
    return true;
}


int main (void)
{
    std::string str1("A man, a plan, a canal, Panama");
    std::string str2("Able was I, ere I saw Elba!");
    std::string str3("Ray a Ray");
    std::cout << is_palindromic(str1) << std::endl;
    std::cout << is_palindromic(str2) << std::endl;
    std::cout << is_palindromic(str3) << std::endl;
    return 0;
}
