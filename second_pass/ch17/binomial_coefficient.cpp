#include <iostream>
#include <vector>
#include <cassert>
#include "../../utils.hpp"

// C(n,k) = C(n-1, k-1) + C(n-1,k)
// C(n,0) = C(n,n) = 1
// C(n,k) = n!/k!/(n-k)!
//

long long int factorial (int n)
{
    long long int res = 1;
    while(n) {
        res *= n--;
    }
    if (res < 0) {
        throw std::invalid_argument("n is too big");
    }
    return res;
}

long long int binomial_coefficient_stupid (int n, int k)
{
    long long int num = factorial(n);
    long long int dem = factorial(n - k) * factorial(k);
    return num/dem;
}


int binomial_coefficient (const int n, const int k)
{
    if (n == k || k == 0) {
        return 1;
    }
    if (k > n || k < 0) {
        return 0;
    }
    std::vector<std::vector<int>> K(n+1, std::vector<int>(k+1, 0));
    for (int i = 0; i < K.size(); ++i) {
        K[i][0] = 1;
    }
    for (int i = 0, j = 0; i <= n && j <= k; ++i, ++j) {
        K[i][j] = 1;
    }


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < std::min(i,k+1); ++j) {
            K[i][j] = K[i-1][j-1] + K[i-1][j];
        }
    }
    return K[n][k];
}


int main (void)
{
    binomial_coefficient(5,1);
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            assert(
                binomial_coefficient(i,j) ==
                binomial_coefficient_stupid(i,j) );
        }
    }


    return 0;
}
