#include <iostream>
#include <sstream>
#include <string>

std::string next_look_and_say(std::string& str)
{
    if (str.size() == 0) {
        return std::string("");
    }

    std::stringstream ss("");
    for (int i = 0; i < str.size(); ++i) {
        int k = 1;
        for (int j = i+1; j < str.size() && str[j] == str[i]; ++j) {
            ++k;
        }
        ss << k << str[i];
        i += k - 1;
    }
    return ss.str();
}

std::string next_look_and_say (int n) 
{
    std::string s("1");
    for (int i = 0; i < n; ++i) {
        s =  next_look_and_say(s);
    }
    return s;
}


int main (void)
{
    for (int i = 0; i <= 8; ++i) {
        std::cout << next_look_and_say(i) << std::endl;
    }
    return 0;
}
