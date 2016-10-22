#include <iostream>
#include <vector>
#include "../utils.hpp"


template <class T>
std::vector<T> find_intersection (const std::vector<T>& A,
        const std::vector<T>& B)
{
    std::vector<T> C;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if(A[i] == B[j]) {
            C.push_back(A[i]);
            while (A[i] == C.back()) ++i;
            while (B[j] == C.back()) ++j;
        } else {
            if (A[i] < B[j]) {
                ++i;
            } else {
                ++j;
            }
        }
    }
    return C;
}


int main (void) 
{
    std::vector<int> A;
    std::vector<int> B;
    for (int i = 0; i < 20; ++i) {
        A.emplace_back(i);
    }
    for (int i = 1; i < 40; i += 2) {
        B.emplace_back(i);
    }
    auto C = find_intersection(A, B);
    std::cout << C << std::endl;
    return 0;
}

