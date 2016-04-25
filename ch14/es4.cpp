#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"


template <class T>
void unique (std::vector<T>& A)
{
    std::sort(A.begin(), A.end());
    int k = 0;
    for (int i = 0; i < A.size(); ++i) {
        A[k++] = A[i];
        int j = i + 1;
        while (j < A.size() && A[j] == A[i]) {
            ++j;
        }
        i = j - 1;
    }
    while (A.size() > k) {
        A.pop_back();
    }
}


int main (void)
{
    std::vector<int> A = {1,1,1,2,3};
    unique(A);
    std::cout << A << std::endl;
    return 0;
}
