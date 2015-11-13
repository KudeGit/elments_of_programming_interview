#include <iostream>
#include <vector>

int find_max_product (const std::vector<int>& A)
{
    std::vector<long int> forward_prod(A.size(), 1);
    std::vector<long int> backward_prod(A.size(), 1);

    forward_prod[0] = A[0];
    for (int i = 1; i < A.size(); ++i){
        forward_prod[i] = A[i]*forward_prod[i-1];
    }
    backward_prod[A.size()-1] = A.back();
    for (int i = A.size() - 2; i >= 0; --i) {
        backward_prod[i] = A[i] * backward_prod[i+1];
    }
    long int max_product = std::numeric_limits<long int>::min();
    for (int i = 0; i < A.size() ; ++i) {
        max_product = std::max(forward_prod[i]*backward_prod[i]/A[i], max_product);
    }
    return max_product;
}

int main (void)
{
    return 0;
}
