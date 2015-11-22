#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "../utils.hpp"

std::vector<int> get_next_perm (std::vector<int> A)
{
    int k = A.size() - 2;
    while (k >= 0 && A[k] > A[k+1]) {
        --k;
    }
    int l = -1;
    for (int i = k+1; i < A.size(); ++i) {
        if(A[i] > A[k]) {
            l = i;
        } else {
            break;
        }
    }
    std::swap(A[k], A[l]);
    std::reverse(A.begin() + k + 1, A.begin() + l +1);
    return A;
}

std::vector<int> get_prev_perm (std::vector<int> A)
{
    int k = A.size() - 2;
    while (k >= 0 && A[k+1] > A[k]) {
        --k;
    }
    if (k == -1) {
        return std::vector<int>();
    }
    int l = A.size() - 1;
    while(A[l] > A[k]) {
        --l;
    }
    std::swap(A[l], A[k]);
    std::reverse(A.begin() + k + 1, A.end());
    return A;
}

int main (void)
{
    std::vector<int> A = {1, 4, 3, 5, 2};
    std::cout << A << std::endl;
    for (int i= 0; i < 10; ++i) {
        A = get_next_perm(A);
        std::cout << A << std::endl;
    }

    std::cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxx" << std::endl;
    std::cout << A << std::endl;
    for (int i= 0; i < 10; ++i) {
        //A = get_prev_perm(A);
        std::cout << get_prev_perm(A) << "/ ";
        std::cout << __prev_permutation(A, 0, A.size()) << ": ";
        std::cout << A << std::endl;
        std::cin.get();
    }

    return 0;
}

