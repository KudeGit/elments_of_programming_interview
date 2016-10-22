#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

#include "../utils.hpp"


std::vector<std::string> find_heavy_hitters (std::stringstream& iss, int K)
{
    std::unordered_map<std::string, long> hh; //heavy hitters
    std::string cw; //current word
    long N = 0;
    while (iss >> cw) {
        if (hh.size() < K) {
            auto& h = hh[cw];
            if (!h) {
                h = 0;
            }
            ++h;
        } else {
            if (hh.find(cw) != hh.end()) {
                ++hh[cw];
            } else {
                for (auto& h: hh) {
                    --h.second;
                    if (h.second  == 0) {
                        hh.erase(h.first);
                    }
                }
                if (hh.size() < K) {
                    hh[cw] = 1;
                }
            }
        }
        ++N;
    }



    iss.clear();
    iss.seekg(0, std::ios_base::beg);
    std::vector<std::string> res;
    auto th = static_cast<double>(K)/static_cast<double>(N);
    for (auto& h: hh) {
        h.second = 0;
    }
    while (iss >> cw) {
        if (hh.find(cw) != hh.end()) {
            ++hh[cw];
        }
    }
    for (auto& h: hh) {
        auto freq = static_cast<double>(h.second)/static_cast<double>(N);
        if(freq >= th) {
            res.emplace_back(cw);
            hh.erase(cw);
        }
    }

    return res;
}

int main (void)
{
    std::stringstream ss;
    ss << "A A A B A";
    auto res = find_heavy_hitters(ss, 1);
    std::cout << res << std::endl;
    return 0;
}
