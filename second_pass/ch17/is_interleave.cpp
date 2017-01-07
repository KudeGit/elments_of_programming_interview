#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <unordered_map>
#include "../../utils.hpp"

using namespace std;


bool isInterleaveDP (const std::string s1,
                     const std::string& s2,
                     const std::string& s3)
{
    if (s3.size() != s1.size() + s2.size()) {
        return false;
    }
    std::vector<std::vector<bool>> K(s1.size() + 1,
                    std::vector<bool>(s2.size() + 1, false));

    K[0][0] = true;
    for (int i = 0; i < s1.size(); ++i) {
        K[i+1][0] = s1[i] == s3[i];
        if(!K[i+1][0]) {
            break;
        }
    }

    for (int i = 0; i < s2.size(); ++i) {
        K[0][i+1] = s2[i] == s3[i];
        if (!K[0][i+1]) {
            break;
        }
    }
    debug(K);
    for (int i = 0; i < s1.size(); ++i) {
        for (int j = 0; j < s2.size(); ++j) {
            K[i+1][j+1] = (K[i+1][j] && s2[j] == s3[i+j+1]) ||
                (K[i][j+1] && s1[i] == s3[i+j+1]);
        }
        debug(K);
    }
    return K.back().back();
}

struct KeyHash {
    std::size_t operator() (const tuple<int,int,int>& t) const {
        return std::hash<int>()(get<0>(t)) ^ std::hash<int>()(get<1>(t)) ^
            std::hash<int>()(get<2>(t));
    }
};
struct KeyEqual {
    bool operator() (const tuple<int,int,int>& lhs, const tuple<int,int,int>& rhs) const {
        return get<0>(lhs) == get<0>(rhs) && get<1>(lhs) == get<1>(rhs) && get<2>(lhs) == get<2>(rhs);
    }
};
bool isInterleave(const string& s1, int s1_idx, 
        const string& s2, int s2_idx,
        const string& s3, int s3_idx, 
        std::unordered_map<tuple<int,int,int>, bool, KeyHash, KeyEqual>& C) {
    if (s1_idx < -1 || s2_idx < -1 || s3_idx < -1) {
        return false;
    }
    if (s1_idx == -1 && s2_idx == -1 && s3_idx == -1) {
        return true;
    }
    auto curr_indexes = make_tuple(s1_idx, s2_idx, s3_idx);
    auto it = C.find(curr_indexes);
    if (it != C.end()) {
        return it->second;
    }
    auto curr_res = false;
    if (s1_idx >= 0 && s1[s1_idx] == s3[s3_idx]) {
        curr_res = isInterleave(s1, s1_idx - 1, s2, s2_idx, s3, s3_idx-1, C);
    }
    if (!curr_res && s2_idx >= 0 && s2[s2_idx] == s3[s3_idx]) {
        curr_res = isInterleave(s1, s1_idx, s2, s2_idx-1, s3, s3_idx-1, C);
    }
    C[curr_indexes] = curr_res;
    return curr_res;
}

bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    std::unordered_map<tuple<int,int,int>, bool, KeyHash, KeyEqual> C;
    return isInterleave(s1, s1.size() - 1, s2, s2.size() - 1, s3, s3.size()-1, C);
}


int main (void)
{
    auto res = isInterleaveDP("atc", "gtaa", "gattaca");
    debug(res);
    return 0;
}
