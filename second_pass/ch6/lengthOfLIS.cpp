#include <iostream>
#include <vector>
#include <utility>
#include "../../utils.hpp"

using namespace std;

#define DEBUG(x, end) do{if (x == end) debug("null"); else debug(x); }while(0)

std::ostream& operator<< (std::ostream& out, const std::unordered_map<int,int>::iterator& it)
{
    out << "("<< it->first << ", " << it->second << ")";
    return out;
}

int longestConsecutive(vector<int>& nums) {
    unordered_map<int,int> H;
    for (auto& n: nums) {
        auto it = H.find(n);
        //debug(n);
        if (it == H.end()) {
            auto it_n_minus_1 = H.find(n-1);
            auto it_n_plus_1 = H.find(n+1);
            //n_minus_1 and n_plus_1 both present
            //DEBUG(it_n_minus_1, H.end());
            //DEBUG(it_n_plus_1, H.end());
            if (it_n_minus_1 != H.end() && it_n_plus_1 != H.end()) {
                H[n] = it_n_minus_1->second + it_n_plus_1->second + 1;
                it_n_minus_1->second = H[n];
                it_n_plus_1->second = H[n];
                auto i = 2;
                while ((it_n_minus_1 = H.find(n-i)) != H.end()) {
                    it_n_minus_1->second = H[n];
                    ++i;
                }
                i = 2;
                while ((it_n_plus_1 = H.find(n+i)) != H.end()) {
                    it_n_plus_1->second = H[n];
                    ++i;
                }

            } else if (it_n_minus_1 != H.end() && it_n_plus_1 == H.end()) {
                H[n] = it_n_minus_1->second +  1;
                it_n_minus_1->second += 1;
                auto i = 2;
                while ((it_n_minus_1 = H.find(n-i)) != H.end()) {
                    it_n_minus_1->second = H[n];
                    ++i;
                }
            } else if (it_n_minus_1 == H.end() && it_n_plus_1 != H.end()) {
                H[n] = it_n_plus_1->second +  1;
                it_n_plus_1->second += 1;
                auto i = 2;
                while ((it_n_plus_1 = H.find(n+i)) != H.end()) {
                    it_n_plus_1->second = H[n];
                    ++i;
                }
            } else {
                H[n] = 1;
            }
            //DEBUG(H.find(n), H.end());
            //DEBUG(H.find(n-1), H.end());
            //DEBUG(H.find(n+1), H.end());
        }
    }
    auto longest_seq_len = 0;
    for (const auto& h: H) {
        longest_seq_len = std::max(longest_seq_len, h.second);
    }
    return longest_seq_len;
}


std::pair<int, int> longest_contigous_increasing_subarray (const std::vector<int>& nums)
{
    if (nums.empty()) {
        return {-1,-1};
    }
    auto res = std::make_pair(0,0);
    auto curr_start = 0;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] <= nums[i-1]) {
            if (i - curr_start > res.second - res.first) {
                res = {curr_start, i};
            }
        } else {
            curr_start = i;
        }
    }
    return res;
}

int main (void)
{
    std::vector<int> A{0,3,7,2,5,8,4,6,0,1};
    auto res = longestConsecutive(A);
    debug(res);
    return 0;
}
