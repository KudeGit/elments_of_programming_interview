#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <bitset>
#include <cstdint>
#include "../utils.hpp"

#define N_BIT 4
#define N_BIT_OVER_2 N_BIT/2


void generate_all_ips (const std::string& filename, const uint32_t skip, const uint32_t ips_max)
{
    std::ofstream of(filename);
    if(!of.good()) {
        throw std::runtime_error("cannot open ips address files");
    }
    for (size_t i = 0; i < ips_max; ++i) {
        if (i != skip) {
            of << i << std::endl;
        }
    }
    of.close();
}
unsigned int find_missing_ip_address (std::ifstream& ifs)
{
    std::vector<size_t> ips ((1 << N_BIT_OVER_2), 0);
    uint32_t x;
    while (ifs >> x) {
        ++ips[x >> N_BIT_OVER_2];
    }
    for (size_t i = 0; i < ips.size(); ++i) {
        if (ips[i] < (i << N_BIT_OVER_2)) {
            ifs.clear();
            ifs.seekg(0, std::ios::beg);
            std::bitset<(1 << N_BIT_OVER_2)> bit_vec;

            while (ifs >> x) {
                if ((x >> N_BIT_OVER_2) == i) {
                    //setting all the bits for which the MSB matches
                    bit_vec.set(((1 << N_BIT_OVER_2) - 1) & x);
                }
            }
            ifs.close();
            for (size_t j = 0; j < (1 << N_BIT_OVER_2); ++j) {
                //Find the LSB that was not present
                if (bit_vec.test(j) == 0) {
                    return (i << N_BIT_OVER_2) | j;
                }
            }
        }
    }
    return 0;
}


int main (void)
{
    std::string ip_file_name("ips.txt");
    generate_all_ips(ip_file_name, 12, (1 << N_BIT));

    std::ifstream ifs(ip_file_name);
    if(!ifs.good()) {
        return 1;
    }
    auto res = find_missing_ip_address(ifs);
    std::cout << res << std::endl;
    return 0;
}
