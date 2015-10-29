#include <iostream>
#include <random>
#include <cassert>
#include <chrono>
#include "../utils.hpp"

int random_a_b (int a, int b)
{
    static unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    static std::default_random_engine g(seed);
    static std::uniform_int_distribution<int> d(0,1);
    int x = b - a;
    int res = 0;
    if (a > b) {
        std::cout << "usage error:  a("<< a << ") cannot be larger than b(" << b <<")" << std::endl;
        return -1;
    }
    do{
        res = 0;
        for (int i = 0; (1 << i) <= x; ++i ) {
            int r = d(g);
            res = (res << 1) | r;
        }
    } while (res > x);
    return a + res;
}


int main (void)
{
    for (int i = 0; i < 100; ++i) {
        int r = random_a_b(10, 20);
        std::cout << r << std::endl;
        assert(r>=10 && r<=20);
    }
    return 0;
}

