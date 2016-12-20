#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <string>
#include <cassert>
#include "../../utils.hpp"


void build_and_save_result (std::vector<std::string>& ips,
        const std::array<int, 4>& candidate_ip)
{
    std::stringstream ss;
    ss << candidate_ip[0];
    for (int i = 1; i < 4; ++i) {
        ss << "." << candidate_ip[i];
    }
    ips.emplace_back(ss.str());
}

void recover_ip_addresses(std::vector<std::string>& ips,
        const std::string& str,
        std::array<int, 4>& candidate_ip,
        int k, size_t pos)
{
    if (pos == str.size() && k == 4) {
        build_and_save_result(ips, candidate_ip);
        return;
    }
    if (pos == str.size() || k == 4) {
        return;
    }
    std::stringstream ss;
    for (int i = pos; i < std::min(pos+3, str.size()); ++i) {
        ss << str[i];
        auto candidate_octect = std::stoi(ss.str());
        if (std::to_string(candidate_octect) == ss.str() &&
                candidate_octect >= 0  && candidate_octect < 256) {
            candidate_ip[k] = candidate_octect;
            recover_ip_addresses(ips, str, candidate_ip, k+1, i+1);
        } else {
            return;
        }
    }
    return;
}

std::vector<std::string> recover_ip_addresses (const std::string& str)
{
    std::vector<std::string> ips;
    std::array<int, 4> candidate_ip{{-1,-1,-1,-1}};
    recover_ip_addresses(ips, str, candidate_ip, 0, 0);
    return ips;
}

void test()
{
    auto res = recover_ip_addresses("010010");
    assert(res.size() == 2);
    assert(res[0] =="0.10.0.10");
    assert(res[1] == "0.100.1.0");
    
    res = recover_ip_addresses("0000");
    assert(res.size() == 1);
    assert(res[0]=="0.0.0.0");

    res = recover_ip_addresses("25525511135");
    assert(res.size() == 2);
    assert(res[0] == "255.255.11.135");
    assert(res[1] == "255.255.111.35");

    std::vector<std::string> expected_res = {"17.216.25.41",
        "17.216.254.1",
        "172.16.25.41",
        "172.16.254.1",
        "172.162.5.41",
        "172.162.54.1"};
    res = recover_ip_addresses("172162541");
    for (int i = 0; i < res.size(); ++i) {
        assert(res[i] == expected_res[i]);
    }
    assert(res.size() == expected_res.size());
    

}

int main (void)
{
    test();
    return 0;
}
