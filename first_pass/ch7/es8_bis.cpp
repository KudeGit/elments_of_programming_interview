#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../utils.hpp"


void generate_all_ip_addr (const std::string& ip_str, int start, int pos,
        std::vector<int>& candidate, std::vector<std::string>& valid_ips)
{
    if(candidate.size() > 4) {
        return;
    }
    if (pos >= ip_str.size()) {
        if (candidate.size() == 4) {
            std::stringstream ss;
            bool first = true;
            for (const auto n: candidate) {
                std::string sep = first ? "" : ".";
                ss << sep << n ;
                first = false;
            }
            valid_ips.push_back(ss.str());
            return;
        } else{
            return;
        }
    }
    for (; pos < ip_str.size(); ++pos) {
        int octect = std::stoi(std::string(ip_str.begin() + start,
                    ip_str.begin() + pos + 1));
        if (octect > 255) {
            return;
        } else {
            candidate.push_back(octect);
            generate_all_ip_addr(ip_str, pos+1, pos+1, candidate, valid_ips);
            candidate.pop_back();
        }
    }
}


std::vector<std::string> generate_all_ip_addr(const std::string& ip_str)
{
     std::vector<int> candidate;
     std::vector<std::string> valid_ips;
     generate_all_ip_addr(ip_str, 0, 0, candidate, valid_ips);
     return valid_ips;
}


int main (int argc, char* argv[])
{
    if (argc != 2) {
        error("invalid usage: %s ip_addr_str", argv[0]);
        return -1;
    }
    std::string ip_str(argv[1]);

    auto valid_ips = generate_all_ip_addr(ip_str);
    std::cout << valid_ips << std::endl;
    return 0;
}

