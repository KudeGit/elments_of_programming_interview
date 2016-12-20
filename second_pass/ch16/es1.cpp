#include <iostream>
#include "ch16.hpp"

void hanoy(int n, char from, char tmp, char to)
{
    if (n) {
        hanoy(n-1, from, to, tmp);
        std::cout << "Move disk " << n << " from " << from << " to " << to << std::endl;
        hanoy(n-1, tmp, from, to);
    }
}
