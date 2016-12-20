#include <iostream>
#include <string>
#include <cassert>
#include <utility>
#include "utils.hpp"


using namespace std;

class Solution {
    public:

        bool match_here (const string& s, int i,
                const string& p, int j) {
            if (j == p.size()) {
                return true;
            }
            if (j == p.size()-1 && p.back() == '$') {
                return i == s.size();
            }
            if (j < p.size() - 1 && p[j+1] == '*') {
                do {
                    if(match_here(s, i, p, j +2)) {
                        return true;
                    }
                } while(i < s.size() && ( s[i++] == p[j] || p[j] == '.'));
            }
            if (p[j] == '.' || p[j] == s[i]) {
                return match_here(s,i+1,p,j+1);
            }
            return false;
        }
        bool isMatch(string s, string p) {
            if (p.empty()) {
                return true;
            }
            if (p[0] == '^') {
                return match_here(s, 0, p, 1);
            }
            for (int i = 0; i < s.size(); ++i) {
                if(match_here(s, i, p, 0)) {
                    return true;
                }
            }
            return false;
        }
};


void test()
{
    Solution s;
    assert( s.isMatch("aa", "a$")       == false);
    assert( s.isMatch("aa", "aa")       == true);
    assert( s.isMatch("aaa", "aa")      == false);
    assert( s.isMatch("aa", "a*")       == true);
    assert( s.isMatch("aa", ".*")       == true);
    assert( s.isMatch("ab", ".*")       == true);
    assert( s.isMatch("aab", "a*b")   == true);
    assert( s.isMatch("aab", "c*a*b")   == true);
}

int main (void)
{
    test();
    return 0;
}
