#include <iostream>
#include <vector>
#include <string>
#include "../utils.hpp"


template <class T>
void get_next_perm (std::vector<T>& A)
{
    int k = A.size() - 2;
    while(k >= 0 && A[k] > A[k+1]) {
        --k;
    }
    if(k == -1) {
        std::cout << "cannot get next perm" << std::endl;
        return;
    }
    int l = k+1;
    for (int i = k+1; i < A.size(); ++i) {
        if(A[i] > A[k]) {
            l = i;
        } else {
            break;
        }
    }

    std::swap (A[l], A[k]);
    std::reverse(A.begin() + k + 1, A.end());
}

template <class T>
void get_prev_perm (std::vector<T>& A)
{
    int k = A.size() - 2;
    while (k >= 0 && A[k] < A[k+1]) {
        --k;
    }
    if (k == -1) {
        std::cout << "cannot get prev perm" << std::endl;
        return;
    }
    int l = k + 1;
    for (int i = k+1; i < A.size(); ++i) {
        if(A[i] < A[k]) {
            l = i;
        } else {
            break;
        }
    }
    std::swap(A[k], A[l]);
    std::reverse(A.begin() + k + 1, A.end());
    return;

}


int main (void)
{
    std::vector<int> A = {0, 1, 2, 3};
//    get_prev_perm(A);
//    std::cout << A << std::endl;
//    get_next_perm(A);
//    std::cout << A << std::endl;
//    get_prev_perm(A);
//    std::cout << A << std::endl;
//    return 0;


    for (int i = 0; i < 10; ++i) {
        get_next_perm(A);
        std::cout << A << std::endl;
    }
    std::cout << std::string(50, '#') << std::endl;
    for (int i = 0; i < 10; ++i) {
        get_prev_perm(A);
        std::cout << A << std::endl;
    }
    return 0;
}
