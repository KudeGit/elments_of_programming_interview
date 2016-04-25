#include <iostream>
#include <vector>
#include "../utils.hpp"

size_t sqrt (const size_t s)
{
    if (s < 0) {
        throw std::invalid_argument("cannot compute sqrt of negative number");
    }
    if (!s) {
        return 0;
    }

    size_t x = 1;
    size_t prev_x = 1;
    while (x > 0 && prev_x > 0 && (x*x) <= s) {
        prev_x = x;
        x <<= 1;
    }
    size_t candidate = prev_x;
    while (prev_x <= x) {
        size_t m = prev_x + ((x - prev_x) >> 1);
        if (m * m <= s) {
            candidate = m;
            prev_x = m + 1;
        } else {
            x = m -1;
        }
    }
    return candidate;
}



int main (void)
{
    std::vector<size_t> A = {0, 1, 2, 4, 10, 144, 25, 300};
    for (const auto s: A) {
        std::cout << "sqrt(" << s << ")= " << sqrt(s) << std::endl;
    }
    return 0;

}
