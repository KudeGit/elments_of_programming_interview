#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cassert>
#include "../../utils.hpp"


using namespace std;

#define N_HOURS 4
#define N_MINS  6

void helper (int n, int hours, int mins, int pos, vector<string>& res)
{
    if (n == 0) {
        auto tmp = to_string(hours) + (mins < 10 ? ":0" : ":") + to_string(mins);
        //debug(tmp);
        res.emplace_back(tmp);
        return;
    }
    for (int i = pos; i < N_HOURS + N_MINS; ++i) {
        if (i < N_HOURS) {
            hours += (1 << i);
            //debug(hours);
            if (hours < 12) {
                helper(n - 1, hours, mins, i+1, res);
            }
            hours -= (1 << i);
        } else {
            mins += (1 << (i - N_HOURS));
            if (mins < 60) {
                helper(n-1, hours, mins, i+1, res);
            }
            mins -= (1 << (i - N_HOURS));
        }
    }
}

vector<string> readBinaryWatch(int n) {
    if (n > 10) {
        return {};
    }
    vector<string> res;
    helper(n, 0, 0, 0, res);
    return res;
}

void generate_binary (std::vector<string>& res, string& curr_string, int n)
{
    if (n == 0) {
        res.emplace_back(curr_string);
        return;
    }
    curr_string.push_back('0');
    generate_binary(res, curr_string, n-1);
    curr_string.pop_back();
    curr_string.push_back('1');
    generate_binary(res, curr_string, n-1);
    curr_string.pop_back();

}

int main (void)
{
    std::unordered_set<string> expect1 = {{"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"}};
    std::unordered_set<string> expect2 = {{"0:03","0:05","0:06","0:09","0:10","0:12","0:17","0:18","0:20","0:24",
        "0:33","0:34","0:36","0:40","0:48","1:01","1:02","1:04","1:08","1:16","1:32","2:01","2:02","2:04","2:08",
        "2:16","2:32","3:00","4:01","4:02","4:04","4:08","4:16","4:32","5:00","6:00","8:01","8:02","8:04","8:08","8:16","8:32","9:00","10:00"}};
    auto res1 = readBinaryWatch(1);
    auto res2 = readBinaryWatch(2);

    unordered_set<string> r1(res1.begin(), res1.end());
    unordered_set<string> r2(res2.begin(), res2.end());



    for (auto r: r1) {
        auto it = expect1.find(r);
        assert(it != expect1.end());
        expect1.erase(r);
    }
    assert(expect1.size() == 0);

    for (auto r: r2) {
        auto it = expect2.find(r);
        assert(it != expect2.end());
        expect2.erase(r);
    }
    assert(expect2.size() == 0);


    
    return 0;
}
