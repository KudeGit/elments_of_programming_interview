#ifndef __CH_7__
#define __CH_7__

#include <iostream>
#include <string>
#include <unordered_map>

int stringToInt (const std::string& str);
std::string intToString (int n);
void replace_and_remove (std::string& str,
        const std::unordered_map<char, std::string>& rules);

#endif //__CH_7__
