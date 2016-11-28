#include <iostream>
#include <vector>


using namespace std;

class Solution {
    public:
        int coinChangeHelper(const vector<int>& coins, const int amount, const int idx, vector<int>& C) {
            if (amount == 0) {
                return 0;
            }
            if (amount  < 0 || idx == coins.size()) {
                return -1;
            }

            auto min_n_coins = std::numeric_limits<int>::max();
            if (C[amount] != -1) {
                //std::cout << "C1[" << amount << "]: "  << C[amount] << std::endl;
                //return C[amount];
            } 
            {
                auto c = coins[idx];
                if (amount % c == 0) {
                    min_n_coins =  amount / c;
                } else {
                    for (int i = 0; i <= amount/c; ++i) {
                        auto leftover = amount - c * i;
                        std::cout << "leftover: " << leftover << std::endl;
                        auto candidate = coinChangeHelper(coins, leftover, idx + 1, C);
                        if (candidate != -1) {
                            candidate += i;
                            min_n_coins = std::min(min_n_coins, candidate);
                        }

                    }
                }
            }

            C[amount] = min_n_coins == std::numeric_limits<int>::max() ? 
                -1 : min_n_coins;
            //std::cout << "C2[" << amount << "]: "  << C[amount] << std::endl;
            return C[amount];
        }


        int coinChange(vector<int>& coins, int amount) {
            std::vector<int> C(amount+1, -1);
            C[0] = 0;
            std::sort(coins.begin(), coins.end(), std::greater<int>());
            //std::cout << coins[0] << std::endl;
            coinChangeHelper(coins, amount, 0, C);
            return C.back();
        }
};



int main (void)
{
    std::vector<int> A{1,2,5,10};
    int val = 18;
    Solution s;
    s.coinChange(A, val);
    return 0;
}
