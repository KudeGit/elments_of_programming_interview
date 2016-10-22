#include <iostream>
#include <vector>
#include <tuple>
#include "../utils.hpp"

std::tuple<int, int> find_longest_increasing_contigous_sequence (const std::vector<int>& A)
{
    if(A.size() == 0) {
        return std::make_tuple(0,0);
    }
    int current_len = 1;
    int current_start = 0;
    int max_len = current_len;
    int max_start = current_start;
    int max_end = 1;
    for (int i = 1; i < A.size(); ++i) {
        if(A[i] > A[i-1]) {
            ++current_len;
            if (current_len > max_len) {
                max_len = current_len;
                max_start = current_start;
                max_end = i;
            }
        } else {
            current_len = 1;
            current_start = i;
        }
    }
    return std::make_tuple(max_start, max_end);
}


int main (void) 
{
    //std::vector<int> A = {0,1,2,3,4};
    std::vector<int> A = {0,1,0,1,0};
    std::cout << find_longest_increasing_contigous_sequence(A) << std::endl;
    return 0;


}
