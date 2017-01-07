#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>
#include <random>
#include "../../utils.hpp"

std::unordered_map<char, std::string> rules = {
                    {'a',"dd"},
                    {'b',""},
                    {'c',"c"},
                    {'d',"d"}};

void replace_and_remove (std::string& str)
{
    auto new_len = 0;
    auto start_idx = 0;
    //debug(str);
    for(auto& s: str) {
        auto it = rules.find(s);
        if (it == rules.end()) {
            throw std::invalid_argument("char not int the alphabet");
        }
        new_len += rules[s].size();
        if (rules[s].size() > 0) {
            str[start_idx++] = s;
        }
    }
    //debug(new_len);
    str.resize(new_len);
    auto i = start_idx - 1;
    auto j = str.size() - 1;
    //debug(i);
    while (i >= 0) {
        const auto& x = rules[str[i]];
        for (int  k = x.size() - 1; k >= 0; --k) {
            str[j--] = x[k];
        }
        --i;
    }

}

std::string replace_and_remove_stupid (const std::string& str)
{
    auto new_len = 0;
    for(const auto& s: str) {
        auto it = rules.find(s);
        if (it == rules.end()) {
            throw std::invalid_argument("char not int the alphabet");
        }
        new_len += rules[s].size();
    }
    std::string res(new_len, 0);
    for (int i = 0, j = 0; i < str.size(); ++i) {
        const auto& x = rules[str[i]];
        for(auto k = 0; k < x.size(); ++k) {
            res[j++] = x[k];
        }
    }
    return res;
}

void test_replace_and_remove_stupid()
{
    assert(replace_and_remove_stupid("") == "");
    assert(replace_and_remove_stupid("b") == "");
    assert(replace_and_remove_stupid("bbbbbbb") == "");
    assert(replace_and_remove_stupid("dcdc") == "dcdc");
    assert(replace_and_remove_stupid("a") == "dd");
    assert(replace_and_remove_stupid("aaa") == "dddddd");
    assert(replace_and_remove_stupid("abc") == "ddc");
    assert(replace_and_remove_stupid("bac") == "ddc");
    assert(replace_and_remove_stupid("bca") == "cdd");

}
void test_replace_and_remove_basic()
{
    std::string str;

    str = "aa";
    replace_and_remove(str);
    //debug(str);
    assert(str == "dddd");


    str = "abc";
    replace_and_remove(str);
    //debug(str);
    assert(str == "ddc");


    str = "";
    replace_and_remove(str);
    assert(str == "");
    
    
    str = "b";
    replace_and_remove(str);
    assert(str == "");

    str = "bbbbbb";
    replace_and_remove(str);
    assert(str == "");

    str = "a";
    replace_and_remove(str);
    assert(str == "dd");

    str = "dcdc";
    replace_and_remove(str);
    assert(str == "dcdc");



    str = "bac";
    replace_and_remove(str);
    assert(str == "ddc");

    str = "bca";
    replace_and_remove(str);
    assert(str == "cdd");
}

void test()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> d(0, 30);

    test_replace_and_remove_basic();
    std::string str;
    for (auto& r: rules) {
        std::string tmp(d(gen), r.first);
        str += tmp;
    }

    for (int i = 0; i < 100; ++i) {
        std::random_shuffle(str.begin(), str.end());
        auto input = str;
        replace_and_remove(input);
        assert(input == replace_and_remove_stupid(str));
    }

}

int main (void)
{
    test_replace_and_remove_stupid();
    test();
    return 0;
}
