#include <iostream>
#include <vector>
#include <tuple>
#include "../utils.hpp"

std::tuple<int, int> find_longest_contigous_subarray (const std::vector<int>& A)
{
    int i = 0;
    int max_len = 1;
    std::tuple<int, int> res = {0,0};

    while (i < A.size()) {
        bool skip_it = false;
        for (int j = i + max_len - 1; j >= i; --j) {
            if(j+1 >= A.size() || A[j] >= A[j+1]) {
                skip_it = true;
                i = j+1;
                break;
            }
        }

        if (!skip_it) {
            i = i + max_len - 1;
            while(i + 1 < A.size() && A[i] < A[i+1]) {
                ++i; max_len++;
            }
            res = std::make_tuple(i - max_len + 1, i);
        }
    }
    return res;
}



int main (void)
{

    std::vector<int> arr = {3, 6, 5, 1, 9, 3, 2, 3, 4, 5, 6};
    auto res = find_longest_contigous_subarray(arr);
    std::cout << std::vector<int>(arr.begin() + std::get<0>(res), 
            arr.begin() + std::get<1>(res)  +1) << std::endl;
    return 0;

}
