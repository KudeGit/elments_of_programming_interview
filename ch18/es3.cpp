#include <iostream>
#include <vector>
#include "../utils.hpp"

int compute_capacity (const std::vector<int>& A)
{
    if(A.empty()) {
        return 0;
    }
    int capacity = 0;
    int max_h = A.front();
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] < max_h) {
            capacity += max_h - A[i];
        } else {
            max_h = A[i];
        }
    }
    max_h = A.size() - 1; //use it as an index
    for (int i = A.size() - 1; i >= 0; --i) {
        if(A[i] > A[max_h]) {
            capacity -= (A[i] - A[max_h]) * (max_h - i);
            max_h = i;
        }
    }
    return capacity;
}

int main (void)
{
    std::vector<int> A = {1,2,1,3,4,4,5,1,2,0,3};
    std::cout << compute_capacity(A) << std::endl;
    return 0;
}
