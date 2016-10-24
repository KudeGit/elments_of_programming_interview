#include <iostream>
#include <vector>

void increment (std::vector<int>& A)
{
    std::reverse(A.begin(), A.end());
    auto carry = 1;
    for (auto& a: A) {
        a += carry;
        carry = a/10;
        a %= 10;
    }
    if (carry) {
        A.emplace_back(carry);
    }
    std::reverse(A.begin(), A.end());
    return;
}
