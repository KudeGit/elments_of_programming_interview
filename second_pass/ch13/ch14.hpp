#ifndef __CH_14__
#define __CH_14__

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using anagram_set_t = std::unordered_map<std::string, std::vector<std::string>>;

anagram_set_t
partition_into_anagrams (const std::string& dict_file_name);


bool is_palindrome_permutation (const std::string& str);

bool is_constructible (std::stringstream& iss_letter, std::stringstream& iss_magazine);
#endif //__CH_14__
