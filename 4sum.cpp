#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "utils.hpp"

using namespace std;


pair<int, int> two_sum (const std::vector<int>& A, 
                        const int i1,  const int i2)
{
    unordered_map<int,int> K;
    auto target = A[i1] + A[i2];
    pair<int, int> res(-1, -1);
    for (int i = i2 + 1; i < A.size(); ++i) {
        auto candidate = target - A[i];
        if (K.find(candidate) != K.end()) {
            pair<int, int> test(K[candidate], i);
            if (res.first == -1 || res.first > test.first || 
                    (test.first == test.first && test.second > i)) {
                res = test;
            }
        } else {
            if (K.find(A[i]) == K.end()) {
                K[A[i]] = i;
            }
        }
    }
    return res;
}


vector<int> equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> res;
    unordered_set<int> attempts;
    
    for (int i = 0; i < A.size(); ++i) {
        for (int j = i+1; j < A.size(); ++j) {
            auto target = A[i] + A[j];
            if (attempts.find(target) == attempts.end()) {
                auto a = two_sum(A, i, j);
                if (a.first != -1 && a.second != -1) {
                    res.emplace_back(i);
                    res.emplace_back(j);
                    res.emplace_back(a.first);
                    res.emplace_back(a.second);
                    return res;
                }
            }
            attempts.insert(target);
        }
    }
    return res;
}


int main (void)
{
    vector<int> A = {9, 5, 4, 9, 3, 6, 8, 7, 1, 2, 8, 7, 2, 9, 7, 1, 3, 9, 7, 8, 1, 0, 5, 5};
    auto test = two_sum(A, 0, 1);
    cout << test << endl;
    return 0;
    auto res = equal(A);
    cout << res << endl;
    return 0;

}
