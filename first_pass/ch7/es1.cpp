#include <iostream>
#include <string>

int stringToInt (const std::string& str)
{
    if (str.size() == 0) {
        return 0;
    }
    bool is_negative = str[0] == '-';
    int res = 0;
    for (int i = 0 + static_cast<int>(is_negative); i < str.size(); ++i) {
        res = str[i] - '0' + res * 10;
    }
    res = (is_negative) ? -res : res;
    return res;
}

std::string intToString(int a)
{
    std::string res;
    bool is_negative = a < 0;
    a = is_negative ? -a : a;
    do {
        res.push_back(a%10 + '0');
        a /= 10;
    } while(a!=0);
    if(is_negative) {
        res.push_back('-');
    }
    std::reverse(res.begin(), res.end());
    return res;
}


int main (void) 
{
    std::string a("1234");
    std::string b("-1234");
    std::string c("0");
    std::cout << stringToInt(a) << std::endl;
    std::cout << stringToInt(b) << std::endl;
    std::cout << stringToInt(c) << std::endl;
    std::cout << intToString(1234) << std::endl;
    std::cout << intToString(-123) << std::endl;
    std::cout << intToString(0) << std::endl;
    
    std::cout << intToString(stringToInt(a)) << std::endl;
    std::cout << intToString(stringToInt(b)) << std::endl;
    std::cout << intToString(stringToInt(c)) << std::endl;
    return 0;
}
