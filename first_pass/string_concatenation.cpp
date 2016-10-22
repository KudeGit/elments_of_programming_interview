#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include "utils.hpp"


using namespace std;

std::vector<int> findSubstring(string A, const vector<string> &B) {
    if(B.empty()) {
        return {};
    }
    int S = B[0].size();
    unordered_map<string, int> K;
    unordered_map<string, int> KK;
    for (const auto& b: B) {
        auto& k = K[b];
        if (!k) {
            k = 0;
        }
        ++k;
    }
    //debug(K);
    std::vector<int> res = {};

    for (int i = 0; i < A.size(); i++) {
        KK = K;
        int j = i;
        auto ss = A.substr(j, S);
        while (KK.find(ss) != KK.end() && !KK.empty()  && j < A.size()) {
            //debug(ss);
            auto& k = KK[ss];
            --k;
            if (k == 0) {
                KK.erase(ss);
            }
            j += S;
            ss = A.substr(j, S);
            //debug(KK);
        }
        //debug(KK);
        if (KK.empty()) {
            res.emplace_back(i);
        }

    }
    return res;
}

int main (void)
{
    string AA("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    cout << AA.size() << endl;
    string A("barfoothefoobarman");
    vector<string> B = {"foo", "bar"};
    vector<string> BB = {"aaa", "aaa", "aaa", "aaa", "aaa"};
    auto res = findSubstring(AA, BB);
    cout << res << endl;
    return 0;
}



