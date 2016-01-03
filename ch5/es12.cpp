#include <iostream>
#include <random>
#include <cassert>
#include <chrono>
#include <stdexcept>
#include <string>
#include "../utils.hpp"

int random_a_b (int a, int b)
{
    if (b < a) {
        throw std::invalid_argument("invalid interval");
    }

    std::random_device rd;
    std::default_random_engine g(rd());
    std::uniform_int_distribution<int> d(0,1);

    int delta = b - a + 1;
    int x = 0;
    do {
        x = 0;
        for(int i = 0; (1 << i) < delta; ++i) {
            int b = d(g);
            x = (x << 1) | b;
        }
    } while(x >= delta);

    return x + a;
}

int main (int argc, char* argv[])
{
    if (argc != 3) {
        error("usage: %s <a> <b>", argv[0]);
        return -1;
    }
    int a = std::stoi(argv[1]);
    int b = std::stoi(argv[2]);
    if (b < a) {
        error("invalid interval");
        return 1;
    }

    try {
        std::vector<double> stats(b - a + 1, 0);
        int N = 10000*(b - a + 1);
        for (int i = 0; i < N; ++i) {
            int k = random_a_b(a,b);
            assert( k >= a && k <= b);
            stats[k-a]++;
        }
        for(int i = 0; i < stats.size(); ++i) {
            stats[i] /= static_cast<double>(N);
        }
        std::cout << stats << std::endl;
        return 0;
    } catch (const std::invalid_argument& ia) {
        error("%s", ia.what());
        return 1;
    }
}


