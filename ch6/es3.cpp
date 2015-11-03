#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "../utils.hpp"

class BigNumber {
    private:
        std::vector<char> val; //absolute value in reverse order
        bool is_negative;      //negative flag
        void swap(BigNumber& other);
    public:
        BigNumber () {}
        BigNumber (const char* str);
        BigNumber(const std::string& s);
        BigNumber (const BigNumber& other);
        BigNumber& operator=(BigNumber other);
        friend BigNumber operator* (const BigNumber& a, const BigNumber& b);
        friend bool operator== (const BigNumber& a, const BigNumber& b);
        friend bool operator!= (const BigNumber& a, const BigNumber& b);
        friend bool operator> (const BigNumber& a, const BigNumber& b);
        friend bool operator>= (const BigNumber& a, const BigNumber& b);
        friend bool operator< (const BigNumber& a, const BigNumber& b);
        friend bool operator<= (const BigNumber& a, const BigNumber& b);
        friend std::ostream& operator<< (std::ostream& out, const BigNumber& a);
};

BigNumber::BigNumber(const char* s)
{
    int i = 0, len = 0;
    while(s[i++] != 0) {
        ++len;
    }
    if (len == 0) {
        return;
    }
    is_negative = s[0] == '-';
    for (i = len-1; i >= 0 + static_cast<int>(is_negative); i--) {
        val.push_back(s[i] - '0');
    }
}

BigNumber::BigNumber(const std::string &s)
{
    is_negative = s[0] == '-';
    for (int i = s.size() - 1; i >= 0 + static_cast<int>(is_negative); --i) {
        val.push_back(s[i] - '0');
    }
}


bool operator== (const BigNumber& a, const BigNumber& b) 
{
    int i = 0;
    if (a.val.size() != b.val.size() ) {
        return false;
    }
    while (a.val[i] == b.val[i] && i < a.val.size()) {
        ++i;
    }
    return i == a.val.size();
}

bool operator!= (const BigNumber& a, const BigNumber& b)
{
    return !operator==(a,b);
}

bool operator< (const BigNumber& a, const BigNumber& b)
{
    int i_a = 0, i_b = 0;
    while (a.val[i_a++] == b.val[i_b++] && 
            i_a < a.val.size() && 
            i_b < b.val.size()) ;
    if(i_a == a.val.size() && i_b < b.val.size()) {
            return true;
    }
    if(i_a < a.val.size() && i_b < b.val.size()) {
        return a.val[i_a] < b.val[i_b];
    }
    return false;
}

bool operator> (const BigNumber& a, const BigNumber& b)
{
    return operator<(b,a);
}

bool operator>= (const BigNumber& a, const BigNumber& b)
{
    return !operator<(a,b);
}

bool operator<= (const BigNumber& a, const BigNumber& b)
{
    return !operator>(a,b);
}

void BigNumber::swap(BigNumber& other) 
{
    std::swap(val, other.val);
}
BigNumber& BigNumber::operator= (BigNumber other)
{
    BigNumber::swap(other);
    return *this;
}

std::ostream& operator<< (std::ostream& out, const BigNumber& a)
{
    if(a.is_negative) {
        out << '-' ;
    }
    for (int i = a.val.size() - 1; i >= 0; --i) {
        out << static_cast<char>((a.val[i] + '0'));
    }
    return out;
}


BigNumber operator* (const BigNumber& b_a, const BigNumber& b_b) 
{
    BigNumber result;
    const std::vector<char>& a = b_a.val;
    const std::vector<char>& b = b_b.val;
    result.val = std::vector<char>(a.size()+b.size(), 0);
    std::vector<char>&c = result.val;
    char carry = 0;

    for (int i_a = 0; i_a < a.size(); ++i_a) {
        int i_c = 0;
        carry = 0;
        for (int i_b = 0; i_b < b.size(); ++i_b) {
            i_c = i_a + i_b;
            c[i_c] = (carry + c[i_c] + a[i_a]*b[i_b]);
            carry = c[i_c]/10;
            c[i_c] %= 10;
        }
        if(carry) {
            c[i_c + 1] = carry;
        }
    }
    if (c.back() == 0) {
        c.pop_back();
    }
    result.is_negative = b_a.is_negative^b_b.is_negative;
    return result;
}


int main (int argc, char* argv[])
{
    assert (argc == 3);
    BigNumber a(argv[1]);
    BigNumber b(argv[2]);
    std::cout << a << " * "<< b << " = " << a*b << std::endl;
    return 0;
}
