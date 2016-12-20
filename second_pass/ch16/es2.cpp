#include <iostream>
#include <string>

bool match_here(const std::string& s,  int i,
        const std::string& r, int j)
{
    if (j == r.size()) {
        return true;
    }
    if (j == r.size() - 1 && r.back() == '$') {
        return i == s.size();
    }
    if (i == s.size()) {
        return false;
    }
    if (j < r.size() - 1 && r[j+1] == '*') {
        do {
            if (match_here(s, i, r, j)) {
                return true;
            }
        }while (i < s.size() && (s[i++] == r[j] || r[j] == '.'));
    }
    if (s[i] == r[j] || r[j] == '.') {
        return match_here(s, i+1, r, j+1);
    }
    return false;
}


bool match (const std::string s, const std::string& r)
{
    if (r[0] == '^') {
        return match_here(s,0,r,1);
    }
    for (int i = 0; i < s.size(); ++i) {
        return match_here(s,i,r,0);
    }
}
