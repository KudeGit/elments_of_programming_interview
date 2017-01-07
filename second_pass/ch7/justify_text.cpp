#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../../utils.hpp"

using namespace std;


class Solution {
    string encode_line(const vector<string>& words, const int line_words_len, 
            const int maxWidth, const int curr_start, const int curr_pos) {
        auto n_words = curr_pos - curr_start;
        auto delta = maxWidth - (line_words_len + n_words - 1);
        auto additional_spaces = delta / (n_words > 1 ? n_words - 1 : 1);
        auto leftover = delta %  (n_words > 1 ? n_words - 1 : 1);

        stringstream line;
        line << words[curr_start];
        if (curr_start == curr_pos - 1) {
            line << string(additional_spaces, ' ');
        } else {
            for (int i = curr_start + 1; i < curr_pos; ++i) {
                line << " " << string(additional_spaces, ' ');
                if (leftover > 0) {
                    line << ' ';
                    --leftover;
                }
                line << words[i];
            }
        }

        return line.str();
        //"word1 word2 word3" -> "word1   word2  word3"
        //5 + 1 + 5  + 1 + 5 = 17 / 20 - 17 = 3 => 3 / 2 = 1 => 3 %1  
    }
    public:
    vector<string> fullJustify (const vector<string>& words, int maxWidth) {
        vector<string> res;
        auto line_words_len = 0;
        auto curr_start = 0;
        for (int i = 0; i < words.size(); ++i) {
            const auto& w = words[i];
            auto curr_n_words = i - curr_start + 1;

            if (line_words_len + w.size() + (curr_n_words-1) <= maxWidth) {
                line_words_len += w.size();
            } else {
                res.emplace_back(encode_line(words, line_words_len, maxWidth, curr_start, i));
                curr_start = i;
                line_words_len =0;
                --i;
            }
        }
        if (curr_start < words.size()) {
            stringstream line;
            line << words[curr_start];
            for (int i = curr_start + 1; i < words.size(); ++i) {
                line << " " << words[i];
            }
            if (maxWidth - static_cast<int>(line.str().size()) > 0) {
                line << string(maxWidth - static_cast<int>(line.str().size()), ' ');
            }
            res.emplace_back(line.str());
        }
        return res;

    }
};

void print_line(const std::vector<string>& lines)
{
    for (auto& l: lines) {
        cout << "'" << l << "'\n";
    }
}

int main (void)
{
    Solution s;
    auto res = s.fullJustify({"Listen","to","many,","speak","to","a","few."}, 6);
    print_line(res);
    res = s.fullJustify({"a","b","c","d","e"}, 5);
    print_line(res);
    res = s.fullJustify({"a","b","c","d","e"}, 3);
    print_line(res);
    return 0;
}
