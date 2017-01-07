#include <iostream>
#include <vector>


std::vector<int> product_array_but_self (const std::vector<int>& A)
{
    auto F = 1;
    auto B = 1;
    std::vector<int> res(A.size(), 1);
    for (int i = 1; i < A.size(); ++i) {
        F *= A[i-1];
        res[i] *= F;
        auto j = A.size() - 1 - i;
        B *= A[j+1];
        res[j] *= B;
    }
    return res;
}

int main (void)
{
    return 0;
}
