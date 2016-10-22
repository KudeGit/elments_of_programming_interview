#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <sstream>
#include "utils.hpp"


using namespace std;

vector<vector<string>> wordBreakHelper (const string& A, unordered_set<string>& D,
        unordered_map<string, vector<vector<string>>>& cache)
{
    debug(A);
    if (A.empty()) {
        return vector<vector<string>>(1);
    }
    if(cache.find(A) != cache.end()) {
        string msg = "cache hit " + A;
        debug(msg);
        return cache[A];
    }
    vector<vector<string>> res;
    for (int i = 1; i <= A.size(); ++i) {
        auto a = A.substr(0, i);
        auto b = A.substr(i, A.size() - i);
        if (D.find(a) != D.end()) {
            auto partial_res = wordBreakHelper(b, D, cache);
            for (const auto& pr: partial_res) {
                res.emplace_back(vector<string>());
                auto& last = res.back();
                last.emplace_back(a);
                last.insert(last.end(), pr.begin(), pr.end());
            }
        }
    }
    cache[A] = res;
    return cache[A];
}


vector<string> build_strings (const vector<vector<string>>& strs)
{
    vector<string> res;
    for (const auto& str: strs) {
        stringstream ss;
        for (const auto& s: str) {
            ss << s << " ";
        }
        res.emplace_back(ss.str());
        res.back().pop_back();
    }
    return res;
}


int main (void)
{
    string A = {"catsanddog"};
    unordered_set<string> D= {"cat", "cats", "and", "sand", "dog"};
    unordered_map<string, vector<vector<string>>> cache;
    auto res = wordBreakHelper(A, D, cache);
    cout << res << endl;
    auto strs = build_strings(res);
    cout << strs << endl;
    return 0;
}
