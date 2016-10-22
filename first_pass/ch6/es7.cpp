#include <iostream>
#include <vector>
#include "../utils.hpp"


int find_first_missing_int (std::vector<int>& A)
{
    int i = 0;
    while (i < A.size()) {
        if(A[i] >= 1 && A[i] <= A.size() && A[A[i]-1] != A[i]) {
            std::swap(A[i], A[A[i]-1]);
        } else {
            ++i;
        }
    }
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] != i+1) {
            return i+1;
        }
    }
    return A.size() + 1;
}



int main (void)
{
    std::vector<int> A = {2,4,5,3,1};
    std::vector<int> B = {1,2,3,5,6,7};
    std::vector<int> C = {2,7,1,5,3,100,6};
    std::cout << find_first_missing_int(A) << std::endl;
    std::cout << find_first_missing_int(B) << std::endl;
    std::cout << find_first_missing_int(C) << std::endl;
    return 0;
}
