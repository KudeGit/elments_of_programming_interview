//from leetcode 
//
//


#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
    unordered_map<char, int> H {
        {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
    unordered_map<char, unordered_set<char>> rules {
        {'I', {'V', 'X'}},
            {'X', {'L', 'C'}},
            {'C', {'D', 'M'}},
    };

    public:
    int romanToInt(string s) {
        auto res = 0;
        auto i = 0;
        while(i < s.size() - 1) {
            auto it = H.find(s[i]);
            if (it == H.end()) {
                return 0;
            }

            auto it_rule = rules.find(s[i]);
            if (it_rule == rules.end()) {
                res += it->second;
            } else {
                auto it_base = it_rule->second.find(s[i+1]);
                if (it_base == it_rule->second.end()) {
                    res += it->second;    
                } else {
                    auto base = H[*it_base];
                    res += base - it->second;
                    ++i;
                }
            }
            ++i;
        }
        if (i < s.size())  {
            res += H[s.back()];
        }
        return res; 
    }


    void intToRoman100(int n, string& res) {
        if(n <= 0 || n > 99) {
            return;
        }
        if (n >= 90 && n <= 99) {
            res += "XC";
            intToRoman100(n - 90, res);
            return;
        }
        //between 51 and 89
        if (n >= 50 && n <= 99) {
            res += "L";
            intToRoman100(n - 50, res);
            return;
        }
        //between 40 and 49
        if (n>= 40 && n <= 49) {
            res += "XL";
            intToRoman100(n - 40, res);
            return;
        }
        // between 11 and 39
        if (n >= 10 && n <= 39) {
            res += "X";
            intToRoman100(n - 10, res);
            return;
        }
        if (n >= 1 && n <= 9) {
            switch (n) {
                case 1: 
                    res += "I";
                    return;
                case 2: 
                    res += "II";
                    return;
                case 3: 
                    res += "III";
                    return;
                case 4: 
                    res += "IV";
                    return;
                case 5: 
                    res += "V";
                    return;
                case 6: 
                    res += "VI";
                    return;
                case 7: 
                    res += "VII";
                    return;
                case 8: 
                    res += "VIII";
                    return;
                case 9: 
                    res += "IX";
                    return;
            }
        }

        return;
    }

    vector<pair<char, int>> BigNumber{
        {'M', 1000},
            {'D', 500},
            {'C', 100}};

#define debug(x) cout << #x ": " << x << endl
    void intToRomanHelper(int num, string& res) {
        //debug(num);
        if (num < 100) {
            intToRoman100(num, res);
            return;
        }
        if (num >= 900 && num <= 999) {
            res += "CM";
            intToRomanHelper(num - 900, res);
            return;
        }
        if (num >= 400 && num <= 499) {
            res += "CD";
            intToRomanHelper(num - 400, res);
            return;
        }

        for (const auto& b: BigNumber) {
            auto curr = num/b.second;
            if (curr > 0) {
                res += string(curr, b.first);
                num -= curr*b.second;
                intToRomanHelper(num, res);
                break;
            }
        }
    } 
    string intToRoman(int num) {
        if (num < 1 || num > 3999) {
            return "";
        }

        string res;
        intToRomanHelper(num, res);

        return res;
    }
};


int main (void)
{
    return 0;
}
