#include <iostream>
#include <vector>
#include <algorithm>
#include "../utils.hpp"


template <class T>
std::vector<T> get_next_perm (std::vector<T> A)
{
    int i = A.size() - 2;
    while (i >= 0 && A[i] > A[i+1]) {
        --i;
    }
    if (i == -1) {
        return {};
    }
    int k = i; int l = i;
    for (i = k + 1; i < A.size(); ++i) {
        if (A[k] < A[i]) {
            l = i;
        } else {
            break;
        }
    }
    std::swap(A[k], A[l]);
    std::reverse(A.begin() + k + 1, A.end());
    return A;
}


template <class T>
std::vector<std::vector<T>> compute_all_permutations (std::vector<T> A)
{
    sort(A.begin(), A.end());
    std::vector<std::vector<T>> res;
    res.emplace_back(A);
    do {
        A = get_next_perm(A);
        if (!A.empty()) {
            res.emplace_back(A);
        }
    } while (!A.empty());
    return res;
}


//for lexicografic order, preprocess and sort;
template <class T>
void compute_all_permutations_2 (std::vector<T>& A, std::vector<std::vector<T>>& res, int k)
{
    if (k == A.size()) {
        res.emplace_back(A);
    }
    for (int i = k; i < A.size(); ++i) {
        std::swap (A[k], A[i]);
        compute_all_permutations_2 (A, res, k+1);
        std::swap (A[k], A[i]);
    }
}


int main (void)
{
    std::vector<int> A = {1,2,3};
    std::vector<std::vector<int>> res;
    compute_all_permutations_2(A, res, 0);
    std::cout << res << std::endl;
    return 0;


    auto permutations = compute_all_permutations(A);
    std::cout << permutations << std::endl;
    return 0;

}
