#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "../utils.hpp"



bool is_interleaving (const std::string& s1,
        const int is1,
        const std::string& s2,
        const int is2,
        const std::string& t,
        const int it,
        std::vector<std::vector<int>>& K)
{
    //banner();
    //debug(is1);
    //debug(is2);
    //debug(it);
    //we match all t
    if(it == -1) {
        //debug("they match!");
        return true;
    }

    //one of the last letter must match
    bool is_partial_match = false;
    if (is1 >= 0) {
        is_partial_match |= s1[is1] == t[it];
    }
    if (is2 >= 0) {
        is_partial_match |= s2[is2] == t[it];
    }
    if (!is_partial_match) {
        //debug("not matching");
        return false;
    }

    if (K[is1+1][is2+1] != -1) {
        debug("cache hit");
        assert(is1+1 >= 0 && is2+1 >= 0);
        return K[is1][is2] == 1;
    }

    bool res = false;
    if (is1 >= 0 && s1[is1] == t[it]) {
        //debug("match s1");
        res |= is_interleaving(s1, is1 - 1, s2, is2, t, it - 1, K);
    }

    if (!res && is2 >= 0 && s2[is2] == t[it]) {
        //debug("match s2");
        res |= is_interleaving(s1, is1, s2, is2 - 1, t, it - 1, K);
    }

    K[is1+1][is2+1] = (res) ? 1 : 0;
    return K[is1+1][is2+1] == 1;
}


bool is_interleaving (const std::string& s1,
        const std::string& s2,
        const std::string& t)
{
    if (s1.size() + s2.size() != t.size()) {
        return false;
    }
    std::vector<std::vector<int>> K(s1.size()+1, std::vector<int>(s2.size()+1, -1));
    return is_interleaving(s1, s1.size() - 1, s2, s2.size() - 1, t, t.size() - 1, K);
}


int main (void)
{
    std::string s1("gtaa");
    std::string s2("atc");
    std::string t1("gtataac");
    std::string t2("gattaca");
    std::string t3("gatacta");
    auto res1 = is_interleaving(s1,s2,t1);
    debug(res1);
    auto res2 = is_interleaving(s1,s2,t2);
    debug(res2);
    auto res3 = is_interleaving(s1,s2,t3);
    debug(res3);
    return 0;

}
