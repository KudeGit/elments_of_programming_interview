#include <iostream>
#include <string>
#include <cassert>

using namespace std;

auto find_substring (const std::string s, const std::string p)
{
    for (int i = 0; i < s.size() - p.size() + 1; ++i) {
        auto find = true;
        for (int j = 0; j < p.size(); ++j) {
            assert(i+j < s.size());
            if (p[j] != s[i+j]) {
                find = false;
                break;
            }
        }
        if (find) {
            return i;
        }
    }
    return -1;
}


int main (void)
{
    string s("1234567890");
    string p("7890");
    auto res = find_substring(s,p);
    cout << res << endl;
    return 0;

}
