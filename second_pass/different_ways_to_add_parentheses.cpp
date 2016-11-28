#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

//#define debug(x) cout << #x": " << x << std::endl
#define debug(x) ((void)0)
template <class T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& A)
{
    for (auto& a: A) {
        out << a << ", ";
    }
    return out;
}

class Solution {
public:
    static unordered_map<char, std::function<int(int,int)>> ops;
    vector<int> evaluate (const string& S, int from, int to,
                          unordered_map<int, unordered_map<int, vector<int>>>& C) {
        std::vector<int> res;
        if (C.find(from) != C.end()) {
            if (C[from].find(to) != C[from].end()) {
                return C[from][to];
            }
        }
        
        for (auto i = from; i < to; ++i) {
            auto c = S[i];
            if (ops.find(c) != ops.end()) {
                //debug(S.substr(from, i));
                //debug(S.substr(i + 1, to - i - 1));
                auto A = evaluate(S, from, i, C);
                auto B = evaluate(S, i+1, to, C);
                for (const auto& a: A) {
                    for (const auto& b: B) {
                        res.emplace_back(ops[c](a,b));
                    }
                }
            }
        }
        if (res.empty()) {
            res.emplace_back(stoi(S.substr(from, to - from)));
        }
        C[from][to] = res;
        debug(S.substr(from, to - from));
        debug(res);
        return res;
    }
    
    vector<int> diffWaysToCompute(string S) {
        unordered_map<int, unordered_map<int, vector<int>>> C;
        return evaluate(S, 0, S.size(), C);
    }
};

unordered_map<char,std::function<int(int,int)>> Solution::ops = {
    {'+', [](int a, int b) { return (a) + (b);}},
    {'-', [](int a, int b) { return (a) - (b);}},
    {'*', [](int a, int b) { return (a) * (b);}},
};



int main (void)
{

    Solution s;
    auto res = s.diffWaysToCompute("1+1+1");
    for (const auto& r: res) {
        std::cout << r << std::endl;
    }
    return 0;
}
