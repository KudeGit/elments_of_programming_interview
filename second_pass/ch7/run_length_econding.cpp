#include <iostream>
#include <string>
#include <sstream>
#include "../../utils.hpp"
#include <cassert>
#include <random>

using namespace std;

string encode (const std::string& str)
{

    if (str.size() < 2) {
        return str.empty() ? "" : to_string(1) + str[0];
    }

    stringstream res;
    auto i = 1;
    auto f = 1;
    while (i < str.size()) {
        if (str[i-1] != str[i]) {
            res << f << str[i-1];
            f = 1;
        } else {
            ++f;
        }
        i++;
    }
    res << f << str.back();
    return res.str();
}


string decode(const std::string& str)
{
    if (str.empty()) {
        return "";
    }
    stringstream res;
    stringstream f_ss;
    for (auto& s: str) {
        if (s >= '0' && s <= '9') {
            f_ss << s;
        } else {
            auto f = stoi(f_ss.str());
            res << string(f, s);
            f_ss.str("");
        }
    }
    return res.str();
}



void test()
{
    random_device rd;
    mt19937 gen(rd());
    std::uniform_int_distribution<int> df(1, 10);
    std::uniform_int_distribution<char> dc('a', 'z');
    for (int i = 0; i < 100; ++i) {
        auto clear_str = string();
        for (int j = 0; j < 10; ++j) {
            auto c = dc(gen);
            auto f = df(gen);
            clear_str += string(f,c);
        }
        auto encoded_str = encode(clear_str);
        auto decoded_str = decode(encoded_str);
        assert(decoded_str == clear_str);
    }
}


int main (void)
{
    assert(encode("a") == "1a");
    assert(encode("") == "");
    assert(encode("aaaabcccaa") == "4a1b3c2a");
    assert(decode("1a") == "a");
    assert(decode("2a2b") == "aabb");
    assert(decode("") == "");
    test();


    return 0;
}
