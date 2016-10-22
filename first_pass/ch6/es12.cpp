#include <iostream>
#include <vector>
#include <cmath>
#include "../utils.hpp"

void update_flags (std::vector<bool>& is_prime, int current_prime) 
{
    for (int i = 2*current_prime; i < is_prime.size(); i += current_prime) {
        is_prime[i] = false;
    }
}

int get_next_prime (const std::vector<bool>& is_prime, int current_prime) 
{
    for (int i = current_prime + 1; i < is_prime.size(); ++i) {
        if (is_prime[i] == true) {
            return i;
        }
    }
    return is_prime.size();
}

std::vector<int> find_all_prime (int n)
{
    std::vector<bool> is_prime(n, true);
    is_prime[1] = true;
    is_prime[2] = true;
    int current_prime = 2;
    while(current_prime <= sqrt(n)) {
        update_flags (is_prime, current_prime);
        current_prime = get_next_prime(is_prime, current_prime);
    }
    std::vector<int> result;
    for (int i = 0; i < is_prime.size(); ++i) {
        if (is_prime[i]) {
            result.push_back(i);
        }
    }
    return result;
}



void remove_multiples(const int current_prime, std::vector<bool> & is_prime) 
{
    int i = 2;
    while (i * current_prime < is_prime.size()) {
        is_prime[i*current_prime] = false;
        ++i;
    }
}
int get_next_prime_2(int current_prime, const std::vector<bool>& is_prime) 
{
    int i;
    for (i = current_prime + 1; i < is_prime.size() && 
            is_prime[i] == false; ++i);
    return i;
}


std::vector<int> find_all_prime2 (const int N)
{
    std::vector<bool> is_prime(N, true);
    std::vector<int> primes;
    int current_prime = 2;
    while(current_prime < sqrt(N)) {
        remove_multiples(current_prime, is_prime);
        current_prime = get_next_prime_2(current_prime, is_prime);;
    }
    for (int i = 0; i < is_prime.size(); ++i) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;

}


int main (void)
{
    std::cout << find_all_prime2(10) << std::endl;
    return 0;
}
