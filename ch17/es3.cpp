#include <iostream>
#include <vector>

int binomial (const int n, const int k)
{
//binomial (n,k) = binomial(n-1, k) + binomial (n-1, k-1);

    std::vector<std::vector<int>> K(n+1, std::vector<int>(k+1, 0));
    for (int i = 0; i <= k; ++i) {
        K[0][i] = 0;                //C(0,k) = 0
    }
    for (int i = 0; i <= n; ++i) {
        K[i][0] = 1;                //C(n,0) = 1
    }
    for (int i = 0; i <= k; ++i) {
        K[i][i] = 1;                //C(n,n) = 1
    }

    for (int i = 1; i <= n ; ++i) {
        for (int j = 1; j <= k; ++j) {
            K[i][j] = K[i-1][j] + K[i-1][j-1];
        }
    }
    return K.back().back();
}


int main (void)
{
    int a = binomial(10, 5);
    std::cout << a << std::endl;
    return 0;
}
