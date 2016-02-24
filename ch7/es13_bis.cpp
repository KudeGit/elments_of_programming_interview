#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../utils.hpp"


std::string process_line (const std::vector<std::string>& words, const int start,
        const int end, const int current_line_len, const int L)
{
    std::stringstream ss;
    int additional_spaces = (end > start) ? (L - current_line_len) / (end - start) : 0;
    int left_spaces = (end > start) ? L - current_line_len - additional_spaces*(end - start) : 0;
    for (int i = start; i < end; ++i) {
        ss << words[i] << " " << std::string(additional_spaces + left_spaces, ' ');
        --left_spaces;
    }
    ss << words[end];
    return ss.str();
}

std::vector<std::string> giustify (const std::vector<std::string>& words, const int L)
{
    std::vector<std::string> lines;
    for (int i = 0; i < words.size(); ++i) {
        int start = i;
        int current_line_len = words[i++].size();
        while (i < words.size() && current_line_len + 1 + words[i].size() <= L) {
            current_line_len += 1 + words[i].size();
            ++i;
        }
        --i;
        auto current_line = process_line(words, start, i, current_line_len, L);
        lines.push_back(current_line);
    }
    return lines;
}

int main (void)
{
    std::vector<std::string> words = {"The", "quick", "brown", "fox", 
            "jumped", "over", "the", "lazy", "dogs" };
    auto lines = giustify(words, 11);
    for(const auto line: lines) {
        std::cout << line << std::endl;
    }
    return 0;
}
