#include <iostream>
#include <vector>
#include "../utils.hpp"


template <typename T>
void reverse (T& A)
{
    int i = 0, j = A.size() - 1;
    while (i <= j) {
        std::swap(A[i++], A[j--]);
    }
}


struct BigNumberVector {
    std::vector<int> number;
    BigNumberVector& operator++();
    BigNumberVector operator++(int);
};


std::ostream& operator<< (std::ostream& out, const BigNumberVector& N)
{
    for (const auto& n: N.number) {
        out << n;
    }
    return out;
}


BigNumberVector& BigNumberVector::operator++()
{
    reverse(number);
    int carry = 1;
    int i = 0;
    do {
        int new_carry = (number[i] + carry)/10;
        number[i] = (number[i] + carry) % 10;
        carry = new_carry;
        ++i;
    } while (carry && i < number.size());
    
    if(carry) {
        number.push_back(1);
    }
    reverse(number);
    return *this;
}

BigNumberVector BigNumberVector::operator++ (int)
{
    BigNumberVector tmp;
    tmp.number = this->number;
    operator++();
    return tmp;
}

int main (void) 
{
    BigNumberVector n;
    n.number = {0};
    
    for(int i  = 0; i < 20; ++i) {
        ++n;
        std::cout << n << std::endl;
    }


    return 0;
}


