#include <iostream>
#include <string>


std::string multply (const std::string& s1, const std::string& s2)
{
    std::string res(s1.size() + s2.size(), '0');
    auto N1 = s1.size()-1;
    auto N2 = s1.size()-1;


    for (int i = 0; i < s1.size(); ++i) {
        auto carry = 0;
        auto a = s1[N1 - i] - '0';
        for (int j = 0; j < s2.size(); ++j) {
            auto b = s2[N2 - j] - '0';
            auto c = res[i+j] - '0';
            auto d = (a*b + c + carry) % 10;
            carry = (a*b + c + carry) / 10;
            res[i+j] = d + '0';
        }
        if (carry) {
            res[s2.size() + i] += carry;
        }
    }
    while (res.back() == '0' && res.size() > 1) {
        res.pop_back();
    }
    std::reverse(res.begin(), res.end());
    return res;
}


int main (void)
{
    auto res = multply("99", "99");
    std::cout << res << std::endl;
    return 0;
}
