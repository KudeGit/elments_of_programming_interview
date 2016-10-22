#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include "../utils.hpp"

class BigNumber 
{
    private:
        std::string number;
        bool is_negative;
        void swap(BigNumber& other) {
            std::swap(is_negative, other.is_negative);
            std::swap(number, other.number);
        }
    public:
        void setNumber (const std::string& str);
        BigNumber() {}
        BigNumber(const std::string& str);
        std::string getNumber ();
        BigNumber(const BigNumber& other);
        BigNumber(BigNumber&& other);
        BigNumber& operator= (BigNumber other);
        ~BigNumber();
        friend std::ostream& operator<<(std::ostream& out, const BigNumber& N) {
            if (N.is_negative) {
                out << '-';
            }
            for(std::string::const_reverse_iterator crit = N.number.crbegin(); 
                    crit != N.number.crend(); ++crit) {
                out << (static_cast<char>(*crit+'0'));
            }
            return out;
        }
        BigNumber& operator+= (const BigNumber& rhs);
        friend BigNumber operator+ (BigNumber lhs, const BigNumber& rhs) {
            lhs += rhs;
            return lhs;
        }
        BigNumber& operator*= (const BigNumber &rhs);
};


BigNumber operator* (BigNumber lhs, const BigNumber& rhs) {
    lhs *= rhs;
    return lhs;
}

BigNumber& BigNumber::operator*= (const BigNumber& rhs)
{
    BigNumber tmp(*this);
    if (is_negative ^ rhs.is_negative) {
        is_negative = true;
    }

    number = number + std::string(rhs.number.size(), 0);
    for(auto &c: number) {
        c = 0;
    }

    int carry = 0;
    for (int i = 0; i < tmp.number.size(); ++i) {
        carry = 0;
        for (int j =0; j < rhs.number.size() || carry; ++j) {
            int new_digit = number[i+j] + carry; 
            if (j < rhs.number.size()) { 
                new_digit += tmp.number[i]*rhs.number[j];
            }
            number[i+j] = new_digit % 10;
            carry = new_digit/10;
        }
    }
    while(number.back() == 0) {
        number.pop_back();
    }
    return *this;
}

//99
//99
//---
// 1


BigNumber& BigNumber::operator+= (const BigNumber& rhs)
{
    int carry = 0, new_carry = 0;
    int len_a = number.size();
    int len_b = rhs.number.size();
    for (int i = 0; i < std::min(len_a, len_b); ++i) {
        new_carry = (carry + (number[i]) + (rhs.number[i])) / 10;
        number[i] = ((number[i]) + (rhs.number[i]) + carry) % 10;
        carry = new_carry;
    }
    for (int i = std::min(len_a, len_b); i < len_a; i++) {
        new_carry = (carry + (number[i])) / 10;
        number[i] = ((number[i] + carry) % 10);
        carry = new_carry;
    }
    for (int i = std::min(len_a, len_b); i < len_b; ++i) {
        new_carry = (carry + (rhs.number[i])) / 10;
        number.push_back(((rhs.number[i] + carry) % 10));
        carry = new_carry;
    }
    if(carry) {
        number.push_back(carry);
    }
    return *this;
}

BigNumber::~BigNumber(){}

void BigNumber::setNumber(const std::string& str)
{
    int start = 0;
    is_negative = false;
    if(str[0] == '-') {
        is_negative = true;
        start = 1;
    }
    for(int i = str.size() - 1; i >= start; --i) {
        number.push_back(static_cast<char>(str[i] - '0'));
    }
}
BigNumber::BigNumber (const BigNumber& other)
{
    number = other.number;
    is_negative = other.is_negative;
}

BigNumber::BigNumber (BigNumber&& other)
{
    is_negative = other.is_negative;
    number = std::move(other.number);
}

BigNumber::BigNumber (const std::string& str)
{
    setNumber(str);
}
BigNumber& BigNumber::operator= (BigNumber other)
{
    swap(other);
    return *this;
}

int main (void)
{
    BigNumber a("-9999");
    BigNumber b("9999");
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << a*b << std::endl;
    return 0;
}
