#include <iostream>
#include <string>
#include <vector>

void
helper(const int l, const int r,
       std::string& tmp,
       std::vector<std::string>& res)
{
    if (l == 0 && r == 0) {
        res.emplace_back(tmp);
        return;
    }
    if (r < l || l < 0 || r < 0) {
        return;
    }
    if (l > 0) {
        tmp.push_back('(');
        helper(l - 1, r, tmp, res);
        tmp.pop_back();
    }
    if (r > 0) {
        tmp.push_back(')');
        helper(l, r-1, tmp, res);
        tmp.pop_back();
    }
    return;
}

std::vector<std::string>
generateParenthesis (const int n)
{
    std::vector<std::string> res;
    std::string tmp;
    helper(n, n, tmp, res);
    return res;
}