#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

struct Convert {
    static std::unordered_map<char, int> char2val;
    static std::unordered_map<char, int> val2char;
    long int val;
    void atoi (const std::string& s, int b);
    std::string itoa(int b);
    std::string convert (const std::string& str, int b1, int b2);
};

std::string Convert::convert (const std::string& str, int b1, int b2)
{
    atoi(str, b1);
    return itoa(b2);
}



void Convert::atoi (const std::string& s, int b)
{
    val = 0;
    int i =0;
    bool is_negative = false;
    if (s[0] == '-') {
        is_negative = true;
        ++i;
    } 
    if (s[0] == '+') {
        ++i;
    }
    for (; i<s.size(); ++i) {
        auto c = s[i];
        auto it = Convert::char2val.find(c);
        if (it == Convert::char2val.end()) {
            std::cout << c <<" input char not known..." << std::endl;
            return;
        }
        if (Convert::char2val[c] > b) {
            std::cout << "Impossible converting " << s << " in base " << b << std::endl;
        }
        val = val * b + Convert::char2val[c];
    }
    if (is_negative) {
        val *= -1;
    }
}


std::string Convert::itoa(int b)
{
    std::string out_str;
    bool is_negative = false;
    if (val < 0) {
        is_negative = true;
        val *= -1;
    }
    while (val) {
        out_str.push_back(Convert::val2char[val%b]);
        val /= b;
    }
    if (is_negative) {
        out_str.push_back('-');
    }
    std::reverse(out_str.begin(), out_str.end());
    return out_str;
}

std::unordered_map<char, int> Convert::val2char  {
        {0, '0'},
        {1, '1'},
        {2, '2'},
        {3, '3'},
        {4, '4'},
        {5, '5'},
        {6, '6'},
        {7, '7'},
        {8, '8'},
        {9, '9'},
        {10, 'A'},
        {11, 'B'},
        {12, 'C'},
        {13, 'D'},
        {14, 'E'},
        {15, 'F'}
};

std::unordered_map<char, int> Convert::char2val  {
                                                    {'0', 0},
                                                    {'1', 1},
                                                    {'2', 2},
                                                    {'3', 3},
                                                    {'4', 4},
                                                    {'5', 5},
                                                    {'6', 6},
                                                    {'7', 7},
                                                    {'8', 8},
                                                    {'9', 9},
                                                    {'A', 10},
                                                    {'B', 11},
                                                    {'C', 12},
                                                    {'D', 13},
                                                    {'E', 14},
                                                    {'F', 15},
                                                    {'a', 10},
                                                    {'b', 11},
                                                    {'c', 12},
                                                    {'d', 13},
                                                    {'e', 14},
                                                    {'f', 15}
                                                   };




int main (void)
{
    Convert c;
    std::string s("10");
    c.atoi(s, 10);
    std::cout << c.val << std::endl;
    std::cout << c.itoa(2) << std::endl;
    return 0;
}
