#include <iostream>
#include <vector>
#include <unordered_map>
#include "../../utils.hpp"

struct Person {
    int key;
    /*other data here*/
};


void sort_by_key (std::vector<int>& A)
{
    std::unordered_map<int,int> C;
    std::unordered_map<int,int> M;
    for (const auto& a: A) {
        ++C[a];
    }
    int offset = 0;
    for (const auto& c: C) {
        M[c.first] = offset;
        offset += c.second;
    }
    while (!M.empty()) {
        auto from = M.begin();
        auto to = M.find(A[from->second]);
        std::swap(A[from->second], A[to->second]);
        if (--C[to->first]) {
            ++to->second;
        } else {
            M.erase(to);
        }
    }
}
