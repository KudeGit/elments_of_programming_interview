#include <iostream>
#include <vector>
#include <cmath>
#include "../../utils.hpp"

int get_next_prime(int curr_prime, std::vector<bool>& is_prime)
{
    for (auto i = 2; i*curr_prime < is_prime.size(); ++i) {
        is_prime[curr_prime*i] = false;
    }
    for (auto i = curr_prime+1; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            return i;
        }
    }
    return std::numeric_limits<int>::max();
}

int countPrimes (int n)
{
    if (n < 2) {
        return 0;
    }
    auto curr_prime  = 2;
    std::vector<bool> is_prime(n+1,true);
    is_prime[0] = false;
    is_prime[1] = false;

    do{
        curr_prime = get_next_prime(curr_prime, is_prime);
    } while (curr_prime <= std::sqrt(n));
    auto res = 0;
    for (int i = 0; i < is_prime.size(); ++i) {
        res += (is_prime[i] == true);
    }

    return res;
}


int main (void)
{
    for (int i = 2; i < 10; ++i) {
        std::cout << i << ": " << count_primes(i) << std::endl;
    }
    return 0;
}
