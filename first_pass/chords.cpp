#include <iostream>
#include <unordered_map>
#include "utils.hpp"


int chordCntHelper(int A, std::unordered_map<int, long int>& K)
{
    if (A == 1 || A == 0) {
        return 1;
    } else if (A == 2) {
        return 2;
    }else if (K.find(A) != K.end()) {
        return K[A];
    } else {
        long acc = 0;
        for (int i = 0; i <= A - 2; ++i) {
            acc += chordCntHelper(i, K) * chordCntHelper(A-2-i, K);
            debug(acc);
        }
        K[A] =  chordCntHelper(A-1, K) + acc;
        return K[A];
    }
}


int main (void)
{
    std::unordered_map<int, long int> K;
    auto res = chordCntHelper(4, K);
    debug(res);
}
