#include <iostream>

#include "CppUTest/TestHarness.h"
#include "CppUTest/CommandLineTestRunner.h"

#include <vector>

#include "ch1.hpp"
#include <random>
#include <limits>
#include <cstdint>


TEST_GROUP(ParityBitGroup)
{
};

TEST(ParityBitGroup, CheckSlowZero)
{
    CHECK(parity_bit_slow(0) == 0);
}
TEST(ParityBitGroup, CheckSlowFirst16)
{
    std::vector<int>  input {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    std::vector<bool> parity{0,1,1,0,1,0,0,1,1,0,0, 1, 0, 1, 1, 0};
    size_t i = 0;
    for (const auto& in: input) {
        CHECK(parity_bit_slow(in) == parity[i++]);
    }
}

TEST(ParityBitGroup, CheckSlowPowerOf2)
{
    std::vector<int> input{4,8,16,32,64,128,256,512,1024};
    for (const auto& in: input) {
        CHECK(parity_bit_slow(in) == true);
    }
}

TEST(ParityBitGroup, CheckSlowPowerOf2Minus1)
{
    std::vector<int> input {3,7,15,31,63,127,255,512,1023};
    std::vector<int> parity{0,1,0, 1,  0,  1,  0,  1,   0};
    size_t i = 0;
    for (const auto& in: input) {
        CHECK(parity_bit_slow(in) == parity[i++]);
    }
}

TEST(ParityBitGroup, CheckFastZero)
{
    CHECK(parity_bit_fast(0) == 0);
}
TEST(ParityBitGroup, CheckFastFirst8)
{
    std::vector<int>   input{0,1,2,3,4,5,6,7};
    std::vector<bool> parity{0,1,1,0,1,0,0,1};
    size_t i = 0;
    for (const auto& in: input) {
        CHECK(parity_bit_fast(in) == parity[i++]);
    }
}

TEST(ParityBitGroup, CheckFast8_16)
{
    std::vector<int>   input{8,9,10,11,12,13,14,15};
    std::vector<bool> parity{1,0,0, 1, 0, 1, 1, 0};
    size_t i = 0;
    for (const auto& in: input) {
        CHECK(parity_bit_fast(in) == parity[i++]);
    }
}

TEST(ParityBitGroup, CheckRandom)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<uint64_t> dis(0,
            std::numeric_limits<uint64_t>::max());
    for (int i = 0; i < 100; i++) {
        auto in = dis(gen);
        if(parity_bit_slow(in) != parity_bit_fast(in)) {
            std::cout << in << ": " << parity_bit_slow(in) << " / ";
            std::cout << parity_bit_fast(in) << std::endl;
        }
    }
}


