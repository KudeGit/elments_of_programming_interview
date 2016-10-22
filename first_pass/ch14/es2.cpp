#include <iostream>
#include <vector>
#include "../utils.hpp"



template <class T>
void merge_in_place (std::vector<T> &A, int len_a, const std::vector<T> B)
{
    if (A.size() != len_a + B.size()) {
        throw std::invalid_argument("A length does not match");
    }
    int i_a = len_a - 1;
    int i_b = B.size() - 1;
    int k = A.size() - 1;
    while (i_a >= 0 && i_b >= 0) {
        if(A[i_a] > B[i_b]) {
            A[k--] = A[i_a--];
        } else {
            A[k--] = B[i_b--];
        }
    }
    while (i_a >= 0) {
        A[k--] = A[i_a--];
    }
    while (i_b >= 0) {
        A[k--] = B[i_b--];
    }
}


int main (void)
{
    std::vector<int> A(7, 0);
    std::vector<int> B(3);
    A[0] = 1; A[1] = 3; A[2] = 4; A[3] = 6;
    B[0] = 0; A[1] = 4; B[2] = 4;
    merge_in_place(A, 4, B);
    std::cout << A << std::endl;
    return 0;
}
