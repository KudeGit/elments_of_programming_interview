#include <iostream>
#include <string>
#include <vector>

#include "../../utils.hpp"


using namespace std;


class Solution {
    string encode_ip (const vector<string>& curr_octect) {
        string ip_addr = (curr_octect[0]);
        for (int i = 1; i < 4; ++i) {
            ip_addr += "." + (curr_octect[i]);
        }
        return ip_addr;
    };
    public:
    void restoreIpAddressesHelper(const string& s, const int str_idx, 
            vector<string>& curr_octect, const int curr_octect_idx,
            vector<string>& res) {
        if (str_idx == s.size()) {
            if (curr_octect_idx == 4) {
                auto curr_ip_addr = encode_ip(curr_octect);
                res.emplace_back(curr_ip_addr);
            }
            return;
        }
        if (curr_octect_idx >= 4) {
            return;
        }
        string octect = "";
        if (s[str_idx] == '0') {
            curr_octect[curr_octect_idx] = '0';
            restoreIpAddressesHelper(s, str_idx + 1, curr_octect,  curr_octect_idx + 1, res);
        } else {
            for (auto i = str_idx; i < std::min(static_cast<int>(s.size()), str_idx+4); ++i) {
                octect += s[i] ;
                if (stoi(octect) < 256 && i < s.size()) {
                    curr_octect[curr_octect_idx] = octect;
                    restoreIpAddressesHelper(s, i + 1, curr_octect,  curr_octect_idx + 1, res);
                } else {
                    break;
                }
            }
        }
        curr_octect[curr_octect_idx] = "";
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        vector<string> curr_octect(4, "");
        restoreIpAddressesHelper(s, 0 , curr_octect, 0, res);
        return res;
    }
};

int main (void)
{
    string s="";
    s += '2';
    debug(s);
    cout << ('255' < '256') << endl;
    string str="25525511135";
    return 0;
}
