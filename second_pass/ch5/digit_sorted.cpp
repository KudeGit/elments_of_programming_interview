#include <iostream>
#include <limits>
#include <cassert>

bool is_sorted (int n) {
    auto curr_digit = std::numeric_limits<int>::max();
    auto prev_digit = std::numeric_limits<int>::max();

    while (n) {
        curr_digit = n % 10;
        if (curr_digit > prev_digit) {
            return false;
        }
        prev_digit = curr_digit;
        n /= 10;
    }
    return true;
}


int main (void)
{
    assert(is_sorted(0) == true);
    assert(is_sorted(1) == true);
    assert(is_sorted(9) == true);
    assert(is_sorted(11) == true);
    assert(is_sorted(12) == true);
    assert(is_sorted(21) == false);
    assert(is_sorted(1233344555) == true);
    assert(is_sorted(22221111) == false);
    std::cout << std::numeric_limits<int>::max() << std::endl;
    std::cout << 2147483648 << std::endl;
    std::cout << std::numeric_limits<int>::max() - 2147483648 << std::endl;
    return 0;
}
