#include <iostream>
#include <string>
#include "../../utils.hpp"
#include "cassert"


using namespace std;



string look_and_say (int n)
{
    string res = "1";
    for (int i = 1; i < n; ++i) {
        string tmp; auto f = 1;
        for (int j = 1; j < res.size(); ++j) {
            if (res[j] != res[j-1]) {
                tmp += to_string(f) + res[j-1];
                f = 1;
            } else {
                ++f;
            }
        }
        tmp += to_string(f)  + res.back();
        res = tmp;
    }
    return res;
}


int main (void)
{
    vector<string> expected = {"1", "11", "21", "1211", "111221",
                                "312211", "13112221", "1113213211" };
    for (int i = 1 ; i < 9; ++i) {
        assert(look_and_say(i) == expected[i-1]);
    }
    return 0;
}
