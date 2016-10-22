#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
#include "../utils.hpp"



std::tuple<int,int,int> max_sub_array (const std::vector<int>& A)
{
    int curr_start = 0, curr_end = 0, curr_val = 0;
    int max_start = 0, max_end = 0, max_val = std::numeric_limits<int>::min();
    for (int i = 0; i < A.size(); ++i) {
        curr_val += A[i];
        if (curr_val > max_val) {
            max_val = curr_val;
            max_end = i;
            max_start = curr_start;
        }
        if (curr_val <= 0) {
            curr_val = 0;
            curr_start = i + 1;
        }
    }

    int c_array_start = max_end + 1;
    curr_start = max_end + 1; curr_end = max_end + 1; curr_val = 0;
    for (int i = 0; i < A.size(); ++i) {
        int j = (c_array_start + i) % A.size();
        curr_val += A[j];
        if (curr_val > max_val) {
            max_val = curr_val;
            max_start = curr_start;
            max_end = j;
        }
        if (curr_val <= 0) {
            curr_val = 0;
            curr_start = j + 1;
        }
    }

    auto res = std::make_tuple(max_val, max_start, max_end);
    return res;
}


int main (void)
{
    std::vector<int> A = {904, 40, 523, 12, -335, -385, -124, 481, -31};
    auto res = max_sub_array(A);
    std::cout << std::get<0>(res) << ", ";
    std::cout << std::get<1>(res) << ", ";
    std::cout << std::get<2>(res) << std::endl;
    return 0;
}
