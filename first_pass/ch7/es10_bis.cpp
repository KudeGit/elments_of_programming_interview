#include <iostream>
#include <string>
#include <sstream>
#include "../utils.hpp"

struct RunLenCode {
    std::string encode (const std::string& str);
    std::string decode (const std::string& str);
};

std::string RunLenCode::encode (const std::string& str)
{
    std::stringstream ss;
    for (int i = 0; i < str.size(); ++i) {
        int j = i + 1;
        while (j < str.size() && str[i] == str[j]) {
            ++j;
        }
        ss << (j - i) << str[i];
        i = j - 1;
    }
    return ss.str();
}

std::string RunLenCode::decode (const std::string& str)
{
    std::stringstream out;
    for (int i = 0; i < str.size(); ++i) {
        std::stringstream ss;
        while (i < str.size() && str[i] >= '0' && str[i] <= '9') {
            ss << str[i++];
        }
        int k; ss >> k;
        out << std::string(k, str[i]);
    }
    return out.str();
}

int main (void)
{
    RunLenCode rlc;
    //std::string origin("aaaabcccaa");
    std::string origin("abcdefg");
    auto encoded_str = rlc.encode(origin);
    std::cout << origin << " => " << encoded_str << std::endl;
    auto decoded_str = rlc.decode(encoded_str);
    std::cout << encoded_str << " => " << decoded_str << std::endl;
    std::cout << (decoded_str == origin) << std::endl;
    return 0;
}
