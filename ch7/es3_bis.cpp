#include <iostream>
#include <string>
#include <cctype>




bool is_palindromic (const std::string& str)
{
    int i = 0;
    int j = str.size() - 1;
    while (i <= j) 
    {
        while (i <= j && !isalpha(str[i])) {
            ++i;
        }
        while (i <= j && !isalpha(str[j])) {
            --j;
        }
        if (tolower(str[j]) != tolower(str[i])) {
            return false;
        }
        ++i; --j;
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
}
