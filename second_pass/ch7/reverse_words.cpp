#include <iostream>
#include <string>
#include <cassert>
using namespace std;

void remove_extra_spaces (string& s)
{
    auto start = 0;
    while (start < s.size() && s[start] == ' ') {
        ++start;
    }
    if (start == s.size()) {
        s = "";
        return;
    }
    int last = s.size() - 1;
    while (last >= 0 && s[last] == ' ') {
        --last;
    }

    auto first_space = false;
    int i = 0;
    for (i = 0; start <= last; ++start) {
        if(s[start] != ' ') {
            s[i++] = s[start];
            first_space = true;
        } else {
            if (first_space) {
                s[i++] = s[start];
                first_space = false;
            }
        }
    }
    s.resize(i);
}


int main (void)
{
    std::string str(" ");
    remove_extra_spaces(str);
    assert(str == "");

    str = "a  a";
    remove_extra_spaces(str);
    assert(str == "a a");
    

    str = "  a  a ";
    remove_extra_spaces(str);
    assert(str == "a a");


    str = "  asasa a ssasa saa   sasa sa as";
    remove_extra_spaces(str);
    assert(str == "asasa a ssasa saa sasa sa as");


    return 0;
}
