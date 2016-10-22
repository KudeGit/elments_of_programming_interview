#include <iostream>
#include <vector>
#include "../utils.hpp"


template <class T>
int partition (std::vector<T>& A, 
        const int start, const int last) {
    int pivot = A[start];
    int j = start + 1;
    for (int i = start + 1; i <= last; ++i) {
        if(A[i] <= pivot) {
            std::swap(A[i], A[j++]);
        }
    }
    std::swap(A[--j], A[start]);
    return j;
}


template <class T>
T find_kth_largest_helper (std::vector<T>& A,
        int k, int start, int end) 
{
    if (start > end) {
        throw std::invalid_argument("cannot find kth element");
    }
    auto idx = partition(A, start, end);
    if(idx == k) {
        return A[idx];
    } else {
        if (k < idx) {
            return find_kth_largest_helper(A, k, start, idx - 1);
        } else {
            return find_kth_largest_helper(A, k, idx + 1, end); 
        }
    }

}

template <class T>
T find_kth_largest (std::vector<T>& A, int k) {
    return find_kth_largest_helper (A, k, 0, A.size() - 1);
}

int main (void) 
{
    std::vector<int> A = {3,2,1,5,4};
    for (int i = 0; i < A.size(); ++i) {
        auto k = find_kth_largest(A, A.size() - i -1);
        std::cout << i << "th element is: " << k << std::endl;
    }
    return 0;
}

