#include <iostream>
#include <vector>
#include <limits>
#include <tuple>
#include "../utils.hpp"

std::tuple<int, int,int> max_circular_array (const std::vector<int>& A)
{
    int max_sum = std::numeric_limits<int>::min();
    int curr_sum = 0;
    int cstart = 0, cend = 0;
    int max_start = 0, max_end = 0;
    for (int i = 0; i < A.size(); ++i) {
        curr_sum += A[i];
        cend = i;
        if(curr_sum >= max_sum) {
            max_sum = curr_sum;
            max_start = cstart;
            max_end = i;
            
        }
        if (curr_sum <= 0) {
            curr_sum = 0;
            cstart = i + 1;
            cend = i + 1;
        }
    }

    curr_sum = 0;
    cstart = max_end + 1;
    cend = max_end + 1;
    auto offset = max_end + 1;
    for (int k = 0; k < A.size(); ++k) {
        int i = (offset + k) % A.size();
        curr_sum += A[i];
        if (curr_sum > max_sum) {
            curr_sum = max_sum;
            max_end = i;
            max_start = cstart;
        }
        if (curr_sum <= 0) {
            curr_sum = 0;
            cstart = i+1;
            cend = i+1;
        }
    }

    return std::make_tuple(max_sum, max_start, max_end);
}


int main (void)
{
    std::vector<int> A = {904, 40, 523, 12, -335, -385, -124, 481, -31};
    auto res = max_circular_array(A);
    std::cout << std::get<0>(res) << ", ";
    std::cout << std::get<1>(res) << ", ";
    std::cout << std::get<2>(res) << std::endl;
    return 0;
}
