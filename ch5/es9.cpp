#include <iostream>
#include <string>




int ssDevodeCollID (const std::string &str)
{
    int val = 0;
    for (const auto c: str) {
        val = val*26 + (c-'A' + 1);
    }
    return val;
}


int main (void)
{
    std::string s("AA");
    std::cout << ssDevodeCollID(s) << std::endl;
    return 0;
}
