#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "../utils.hpp"


template <class T>
void sort_almost_sorted_array (std::vector<T>& A, size_t K)
{
    std::priority_queue<T, std::vector<T>, 
        std::greater<int>> pq;

    for (int i = 0; i < std::min(A.size(), K); ++i) {
        pq.push(A[i]);
    }

    for (int i = std::min(A.size(), K), j = 0; i < A.size(); ++i) {
        A[j++] = pq.top();
        pq.pop();
        pq.push(A[i]);
    }
    for (int i = A.size() - K; i < A.size(); ++i) {
        if (pq.empty()) {
            throw std::logic_error("something is off");
        }
        A[i] = pq.top();
        pq.pop();
    }
    return;
}


int main (void)
{
    std::vector<int> A = {1,2,3,4,6,5,7,8,11,10,9};
    std::cout << A << std::endl;
    sort_almost_sorted_array(A,3);
    std::cout << A << std::endl;
    return 0;
}
