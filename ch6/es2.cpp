#include <iostream>
#include <vector>
#include "../utils.hpp"

template <class T>
void reverse (std::vector<T>& A)
{
    int i = 0, j = A.size() - 1;
    while (i < j) {
        std::swap(A[i++], A[j--]);
    }
}
std::vector<int> sum (std::vector<int>& a, std::vector<int>& b)
{
    int i = 0, j = 0;
    int carry = 0;
    std::vector<int> result;
    reverse(a);
    reverse(b);
    while( i < a.size() && j < b.size()) {
        result.push_back((a[i] + b[j] + carry) % 10);
        carry = (a[i++] + b[j++] + carry)/10;
    }
    while (i < a.size()) {
        result.push_back((a[i] + carry) % 10);
        carry = (a[i++] + carry)/10;
    }
    while (j < b.size()) {
        result.push_back((b[i] + carry) % 10);
        carry = (b[i++] + carry)/10;
    }
    if(carry) {
        result.push_back(carry);
    }
    reverse(a); reverse(b); reverse(result);
    return result;
}

int main (void)
{
    std::vector<int> A = {9,9,9,9};
    std::vector<int> B = {1, 0};
    auto C = sum(A,B);
    std::cout << C << std::endl;
    return 0;
}
