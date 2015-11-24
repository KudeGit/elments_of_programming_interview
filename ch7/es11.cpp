#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>


struct EliasGammaEconder {
    std::string encode (int n);
    int decode(const std::string& str);
};

std::string EliasGammaEconder::encode (int n) 
{
    int count = 0;
    std::stringstream ss_res;
    do {
        ss_res << (n%2);
        n /= 2;
        ++count;
    } while(n>0);

    while (count > 0) {
        ss_res << '0';
        --count;
    }

    std::string res = ss_res.str();
    std::reverse(res.begin(), res.end());
    return res;
}

int main (void)
{
    EliasGammaEconder egc;
    std::cout << egc.encode(13) << std::endl;
    return 0;
}

