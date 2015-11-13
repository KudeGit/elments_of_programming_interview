#include <iostream>
#include <vector>
#include <tuple>
#include <limits>
#include "../utils.hpp"

int find_max_difference (const std::vector<int>& A)
{
    int max_diff = std::numeric_limits<int>::min();
    int min_index = 0;
    for (int i = 1; i < A.size(); ++i) {
        if(A[i] < A[min_index]) {
            min_index = i;
        } else if (max_diff < A[i] - A[min_index]) {
            max_diff = A[i] - A[min_index];
        }
    }
    return max_diff;
}

int find_max_difference2 (const std::vector<int>& A)
{
    if (A.empty()) {
        return std::numeric_limits<int>::min();
    }
    int max_diff = std::numeric_limits<int>::min();
    int min_val = A[0];
    for (const auto &a: A){
        max_diff = std::max(max_diff, a - min_val);
        min_val = std::min(min_val, a);
    }
    return max_diff;
}


int find_max_difference_2D (const std::vector<int>& A)
{
    std::vector<int> forward_max_diff (A.size(), std::numeric_limits<int>::min());
    std::vector<int> backward_max_diff (A.size(), std::numeric_limits<int>::min());
    //forward direction
    int max_diff = std::numeric_limits<int>::min();
    int min_val = A[0];
    for (int i = 0; i < A.size(); ++i) {
        max_diff = std::max(max_diff, A[i] - min_val);
        min_val = std::min(A[i], min_val);
        forward_max_diff[i] = max_diff;
    }
    max_diff = std::numeric_limits<int>::min();
    min_val = A.back();
    for (int i = A.size() - 1; i >=0 ; --i) {
        max_diff = std::max(max_diff, A[i] - min_val);
        min_val = std::min(A[i], min_val);
        backward_max_diff[i] = max_diff;
    }
    max_diff = std::numeric_limits<int>::min();
    for (int i = 0 ; i < A.size(); ++i) {
        max_diff = std::max(max_diff, forward_max_diff[i] + backward_max_diff[i]);
    }
    return max_diff;
}



int main (void)
{
    std::vector<int> A = {2, 3, 10, 6, 4, 8, 1};
    std::vector<int> B = {7, 9, 5, 6, 3, 2};

    //std::cout << find_max_difference(A) << std::endl;
    //std::cout << find_max_difference2(A) << std::endl;
    //std::cout << find_max_difference(B) << std::endl;
    //std::cout << find_max_difference2(B) << std::endl;
    
    std::cout << find_max_difference_2D(A) << std::endl;
    std::cout << find_max_difference_2D(B) << std::endl;


    return 0;
}
