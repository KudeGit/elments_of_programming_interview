#include <iostream>
#include <string>
#include <cassert>
#include <vector>
#include <numeric>
#include <utility>

#include "../../utils.hpp"

bool is_palindrome (const std::string& s, int a, int b)
{
    int m = a + ((b-a)>>1);
    auto l = m, r = m + (((b-a) & 0x01));
    while (l >= a && r <= b) {
        if (s[l] != s[r]) {
            return false;
        }
        --l; ++r;
    }
    return true;
}


int minCut (const std::string& s, const int a, 
        std::vector<int>& K) {
    if (a == s.size()) {
        return 0;
    }
    if (K[a] != -1) {
        return K[a];
    }
    int curr_min_cut = s.size() - a - 1; //# of cuts is current string length - 1
    for (int i = 1; i < s.size() - a; ++i) {
        if (is_palindrome (s, a, a+i)) {
            //debug(s.substr(a, i+1));
            //debug(std::make_pair(a, i));
            int curr_cut = (s.size() - a - 1) - i;  //removing i char from the # of cuts
            auto candidate = 1 + minCut(s, a + i, K);
            //debug(std::make_pair(curr_min_cut, candidate));
            curr_min_cut = std::min(curr_min_cut, std::min(curr_cut, candidate));
        }
    }
    K[a] = curr_min_cut;
    return K[a];
}

int min_cut (const std::string& s)
{
    std::vector<int> K(s.size(), -1);
    auto res = minCut(s, 0, K);
    //debug(K);
    return res;
}


int min_cut_dp (const std::string& s)
{
    std::vector<std::vector<bool>> K(s.size(),
            std::vector<bool>(s.size(), false));
    std::vector<int> M(s.size()+1);

    std::iota(M.rbegin(), M.rend(), -1);

    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = i; j < s.size(); ++j) {
            if (s[i] == s[j] && (i - j < 2 || K[i+1][j-1])) {
                K[i][j] = true;
                M[i] = std::min(M[i], M[j+1] + 1);
                debug(M);
            }
        }
        debug(K);
    }
    return M[0];
}


void test_is_palindrome()
{
    assert(is_palindrome("", 0, -1) == true);
    assert(is_palindrome("a", 0, 0) == true);
    assert(is_palindrome("aa", 0, 1) == true);
    assert(is_palindrome("aaa", 0, 2) == true);
    assert(is_palindrome("aaxx", 0, 3) == false);
    assert(is_palindrome("aaaaaa", 0, 5) == true);
    assert(is_palindrome("aaaaac", 0, 5) == false);
    assert(is_palindrome("012321",0, 5) == false);
    assert(is_palindrome("0123210", 0, 6) == true);
    assert(is_palindrome("01233210", 0, 7) == true);
}



int longestPalindrome (const std::string& s)
{
    auto P = std::vector<std::vector<bool>>(s.size(),
                    std::vector<bool>(s.size(), false));
    auto max_pal_len = 0;
    auto start_pos = -1;
    for (int i = s.size() - 1; i >= 0; --i) {
        for (int j = i; j < s.size(); ++j) {
            if ((s[i] == s[j]) && ((j-i) < 2 || (P[i+1][j-1]))) {
                P[i][j] = true;
                if(max_pal_len < j + 1 - i) {
                    max_pal_len = j+1-i;
                    start_pos = i;
                }
            }
        }
        debug(P);
        debug(max_pal_len);
    }
    debug(max_pal_len);
    return max_pal_len;
}


int check_pal_substring (const std::string& s, int l, int r)
{
    int start_pos = -1;
    auto curr_len = l==r ? -1 : 0;
    bool is_sub_pal = true;

    while ((l >= 0 && r < s.size()) && s[l] == s[r]) {
        --l; ++r;
        curr_len += 2;
    }
    return curr_len;

}

int longestPalindromeNoDP (const std::string& s)
{
    int max_pal_len = 0;
    int start_pos = -1;
    for (int i = 0; i < s.size(); ++i) {
        //check odd substring
        auto curr_len = check_pal_substring(s,i,i);
        if (curr_len > max_pal_len) {
            max_pal_len = curr_len;
            start_pos = i - (max_pal_len >> 1);
        }
        curr_len = check_pal_substring(s,i,i+1);
        if (curr_len > max_pal_len) {
            max_pal_len = curr_len;
            start_pos = i - (max_pal_len >> 1) + 1;
        }
    }
    debug(max_pal_len);
    debug(start_pos);
    return max_pal_len;
}

int main (void)
{
    test_is_palindrome();
    //////debug(min_cut("abccd"));
    //std::string s("0204451881");
    //auto res = min_cut_dp(s);
    //debug(res);
    //debug(min_cut_dp("0204451881"));
    longestPalindromeNoDP("aaaa");
    return 0;
}

