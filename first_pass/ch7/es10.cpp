#include <iostream>
#include <string>
#include <sstream>
#include "../utils.hpp"


struct RunLenEncoding {
    std::string encode (const std::string &str);
    std::string decode (const std::string &str);
};

std::string RunLenEncoding::encode (const std::string& str)
{
    int i = 0;
    std::stringstream ss_res;
    while (i < str.size()) {
        char current_char = str[i];
        int count = 1;
        while (i < str.size() && str[++i] == current_char) {
            ++count;
        }
        ss_res << count << current_char;
    }
    return ss_res.str();
}

std::string RunLenEncoding::decode (const std::string& str)
{
    std::stringstream ss_res;
    int i = 0;
    while (i < str.size()) {
        int count = 0;
        while (str[i] >= '0' && str[i]<= '9') {
            count = count*10 + str[i]-'0';
            ++i;
        }
        while(count > 0) {
            ss_res << str[i];
            --count;
        }
        ++i;
    }
    return ss_res.str();
}


int main (void) 
{
    RunLenEncoding encoder;
    std::string str("aaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccaa");
    std::string encoded_str = encoder.encode(str);
    std::cout << encoded_str << std::endl;
    std::string decoded_str = encoder.decode(encoded_str);
    std::cout << decoded_str << std::endl;
    return 0;
}
