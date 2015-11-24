#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "../utils.hpp"


class IpAddress {
    private:
        uint32_t ip;
    public:
        bool is_valid();
};

bool is_valid(const std::vector<int>& current_ip)
{
    for (const auto& oct: current_ip) {
        if (oct > 256) {
            return false;
        }
    }
    return true;
}
std::string get_ip(const std::vector<int>& current_ip)
{
    std::stringstream ss;
    bool first = true;
    for (const auto& oct: current_ip) {
        if(first) {
            ss << oct; 
            first = false;
        } else {
            ss << "." << oct;
        }
    }
    return ss.str();
}


void compute_all_ips (
        const std::string& ip_str,
        std::vector<int> &current_ip,
        int pos, int n_oct,
        std::vector<std::string>& res) {
    //debug(pos);
    //debug(n_oct);
    //debug(current_ip);
    if(n_oct >= 4 && pos < ip_str.size()) {
        //debug("oct is >= 4 but not the end of ip_str");
        return;
    }
    if(pos >= ip_str.size()) {
        //debug("end of ip_str");

        if (is_valid(current_ip) && n_oct == 4) {
            //debug("current is valid");
            res.push_back(get_ip(current_ip));
        }
        return;
    }

    for (int i = pos; i < pos+3 && i < ip_str.size(); ++i) {
        current_ip[n_oct] = current_ip[n_oct]*10 + (ip_str[i]-'0') ;

        if(current_ip[n_oct] < 256) {
            compute_all_ips(ip_str, current_ip, i+1, n_oct+1, res);
            for (int j = n_oct+1; j < current_ip.size(); ++j) {
                current_ip[j] = 0;
            }
        } else {
            current_ip[n_oct] = 0;
            return;
        }
    }
}


std::vector<std::string> compute_all_ips (const std::string& ip_str)
{
    std::vector<int> current_ip(4, 0);
    std::vector<std::string> result;
    compute_all_ips (ip_str, current_ip, 0, 0, result);
    return result;
}



int main (void) 
{
//    std::string test("19216811");
    std::string test("1111");
    auto ips = compute_all_ips(test);
    for (const auto ip: ips) {
        std::cout << ip << std::endl;
    }
    return 0;
}
