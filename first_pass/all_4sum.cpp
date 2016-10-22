#include <iostream>
#include <unordered_map>
#include <vector>
#include "utils.hpp"

using namespace std;

bool comp_vector (const std::vector<int> &A, const std::vector<int> &B)
{
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] < B[i]) {
            return true;
        } else if (A[i] > B[i]) {
            return false;
        }
    }
    return true;
}


struct KeyHash {
    size_t operator() (const pair<int, int>& a) const {
        return std::hash<int>()(a.first) ^ std::hash<int>()(a.second);
    }
};
struct KeyEqual {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
        return a.first == b.first && a.second == b.second;
    }
};

vector<vector<int> > fourSum(vector<int> &A, int B) {
    vector<vector<int>> res;
    std::sort(A.begin(), A.end());

    std::unordered_set<pair<int, int>, KeyHash, KeyEqual> K1;
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i + 1; j < A.size(); ++j) {
            int k1 = j + 1, k2 = A.size() - 1;
            pair<int, int> p1 = {A[i], A[j]};
            if(K1.find(p1) != K1.end()) {
                continue;
            }
            K1.insert(p1);
            std::unordered_set<pair<int,int>, KeyHash, KeyEqual> K;
            debug(j);
            while (k1 < k2) {
                if (A[k1] + A[k2] < B - A[i] - A[j]) {
                    ++k1;
                } else if (A[k1] + A[k2] > B - A[i] - A[j]) {
                    --k2;
                } else {
                    pair<int, int> p = {A[k1], A[k2]};
                    debug(p);
                    if(K.find(p) == K.end()) {
                        debug(k1); debug(k2);
                        debug("insert");
                        K.insert(p);
                    }
                    ++k1; --k2;
                }
            }
            for (auto& k: K) {
                vector<int> candidate;
                candidate.push_back(A[i]); candidate.push_back(A[j]);
                candidate.push_back(k.first); candidate.push_back(k.second);
                res.emplace_back(candidate);
            }
        }
    }
    return res;
}




int main (void)
{
    std::vector<int> A= {9, -8, -10, -7, 7, -8, 2, -7, 4, 7, 0, -3, -4, -5, -1, -4, 5, 8, 1, 9, -2, 5, 10, -5, -7, -1, -6, 4, 1, -5, 3, 8, -4, -10, -9, -3, 10, 0, 7, 9, -8, 10, -9, 7, 8, 0, 6, -6, -7, 6, -4, 2, 0, 10, 1, -2, 5, -2};
    int target = 0;
    auto res = fourSum(A, target);
    for (auto& r: res) {
        cout << r << endl;
    }
    return 0;

}
